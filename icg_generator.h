#ifndef ICG_GENERATOR_H
#define ICG_GENERATOR_H
#include<bits/stdc++.h>
#include "SymbolTable.h"
using namespace std;
//asm code
extern string initiation;
extern string data_seg;
extern string code_seg;
extern string icg;
//asm code
int cur_leb=0;
string new_label()
{
    cur_leb++;
    return "L"+to_string(cur_leb);
}
void generate_declaration(vector<string> vars)
{
    //cout<<"hola\n";
    for(string var: vars){
        string asm_name=st.getScope()+var;
        st.lookup(var)->lookup(var)->asm_name=asm_name;
        data_seg+=asm_name+" DW ?\n";
    }
}
void generate_declaration(string var)
{
    string asm_name=st.getScope()+var;
    st.lookup(var)->lookup(var)->asm_name=asm_name;
    data_seg+=asm_name+" DW ?\n";
}
void generate_declaration(string var_array, string size)
{
    string asm_name=st.getScope()+var_array;
    st.lookup(var_array)->lookup(var_array)->asm_name=asm_name;
    data_seg+=st.getScope()+var_array+" DW "+size+" DUP (?)"+"\n";
}
string push_var(string var)
{
    string asm_name=st.lookup(var)->lookup(var)->asm_name;
    string code="MOV AX, "+asm_name+"\nPUSH AX\n\n";
    return code;
}
string push_varray(string varray)
{
    string var;
    for(int v: varray) {
        if(v=='[') { var.pop_back(); break; }
        else var.push_back(v);
    }

    string asm_name=st.lookup(var)->lookup(var)->asm_name;
    string code="LEA SI, "+asm_name+"\nPOP AX\nADD AX, AX\nADD SI, AX\nPUSH [SI]\n\n";
    return code;
}
string push_literal(string val)
{
    string code="PUSH "+val+"\n\n";
    return code;
}
string incop(string var, string type)
{
    if(type=="VAR_ARRAY"){
        while(true){
            if(var.back()=='[') { var.pop_back(), var.pop_back(); break; }
            var.pop_back();
        }
    }
    string asm_name=st.lookup(var)->lookup(var)->asm_name;
    string code;
    if(type=="VAR") code+="PUSH "+asm_name+"\nINC "+asm_name+"\n\n";
    else if(type=="VAR_ARRAY") 
        code+="LEA SI, "+asm_name+"\nPOP AX\nADD AX, AX\nADD SI, AX\nPUSH [SI]\nADD WORD PTR [SI], 1\n\n";
    return code;
}
string decop(string var, string type)
{
    if(type=="VAR_ARRAY"){
        while(true){
            if(var.back()=='[') { var.pop_back(), var.pop_back(); break; }
            var.pop_back();
        }
    }
    string asm_name=st.lookup(var)->lookup(var)->asm_name;
    string code;
    if(type=="VAR") code+="PUSH "+asm_name+"\nDEC "+asm_name+"\n\n";
    else if(type=="VAR_ARRAY") 
        code+="LEA SI, "+asm_name+"\nPOP AX\nADD AX, AX\nADD SI, AX\nPUSH [SI]\nSUB WORD PTR [SI], 1\n\n";
    return code;
}
string unary_pop()
{
    string code="POP AX\n\n";
    return code;
}
string binary_addop(string op)
{
    string code;
    if(op=="+")
    { code="POP AX\nPOP BX\nADD AX, BX\nPUSH AX\n\n";
    }
    if(op=="-")
    { code="POP BX\nPOP AX\nSUB AX, BX\nPUSH AX\n\n";
    }
    return code;
}
string unary_addop(string op)
{
    string code;
    if(op=="-")
    { code="POP AX\nNEG AX\nPUSH AX\n\n";
    }
    return code;
}

string binary_mulop(string op)
{
    string code;
    if(op=="*")
    { code="POP AX\nPOP DX\nMUL DX\nPUSH AX\n\n";
    }
    if(op=="/")
    { code="MOV DX, 0\nPOP BX\nPOP AX\nIDIV BX\nPUSH AX\n\n";
    }
    if(op=="%")
    { code="MOV DX, 0\nPOP BX\nPOP AX\nIDIV BX\nPUSH DX\n\n";
    }
    return code;
}
string binary_logicop(string op)
{
    string code;
    if(op=="||")
    { code="POP AX\nPOP BX\nOR AX, BX\nPUSH AX\n\n";
    }
    if(op=="&&")
    { 
        string false_label=new_label();
        string exit_label=new_label();
        code="POP AX\nPOP BX\nCMP AX, 0\nJE "+false_label+"\nCMP BX, 0\nJE "+false_label+"\nPUSH 1\nJMP "+exit_label+"\n"+false_label+":\nPUSH 0\n"+exit_label+":\n\n";
    }
    return code;
}
string unary_logicop(string op)
{
    string code;
    if(op=="!")
    { 
        string true_label=new_label();
        string exit_label=new_label();
        string false_label=new_label();
        code+="POP AX\nCMP AX, 0\nJNE "+false_label+"\nJMP "+true_label+"\n"+false_label+":\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    
    }
    return code;
}
string relop(string op)
{
    string code;
    if(op=="=="){
        string true_label=new_label();
        string exit_label=new_label();
        string false_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJNE "+false_label+"\nJMP "+true_label+"\n"+false_label+":\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op=="!="){
        string true_label=new_label();
        string exit_label=new_label();
        string false_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJE "+false_label+"\nJMP "+true_label+"\n"+false_label+":\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op=="<"){
        string true_label=new_label();
        string exit_label=new_label();
        string false_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJGE "+false_label+"\nJMP "+true_label+"\n"+false_label+":\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op==">"){
        string true_label=new_label();
        string exit_label=new_label();
        string false_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJLE "+false_label+"\nJMP "+true_label+"\n"+false_label+":\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op=="<="){
        string true_label=new_label();
        string exit_label=new_label();
        string false_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJG "+false_label+"\nJMP "+true_label+"\n"+false_label+":\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op==">="){
        string true_label=new_label();
        string exit_label=new_label();
        string false_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJL "+false_label+"\nJMP "+true_label+"\n"+false_label+":\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    return code;
}
string assignop(string var, string type)
{
    if(type=="VAR_ARRAY"){
        while(true){
            if(var.back()=='[') { var.pop_back(), var.pop_back(); break; }
            var.pop_back();
        }
    }
    string asm_name=st.lookup(var)->lookup(var)->asm_name;
    string code;
    if(type=="VAR") code="POP AX\nMOV "+asm_name+", AX\nPUSH AX\n\n";
    else if(type=="VAR_ARRAY") 
        code="POP BX\nLEA SI, "+asm_name+"\nPOP AX\nADD AX, AX\nADD SI, AX\nMOV [SI], BX\nPUSH BX\n\n";
    return code;
}
string jump_if_false(string label)
{
    string false_label=new_label();
    string code="POP AX\nCMP AX, 0\nJNE "+false_label+"\nJMP "+label+"\n"+false_label+":\n\n";
    return code;
}
string jump(string label)
{
    string code="JMP "+label+"\n\n";
    return code;
}
string call_func(string func_name)
{
    string code="CALL "+func_name+"\n";
    return code;
}
string return_func()
{
    string code="POP AX\nPOP BX\nPUSH AX\nPUSH BX\nRET\n\n";
    return code;
}
string parapass(vector<string> pids)
{
    reverse(pids.begin(), pids.end());
    string code="POP AX\n";
    for(string pid: pids){
        string asm_name=st.lookup(pid)->lookup(pid)->asm_name;
        code+="POP "+asm_name+"\n";
    }
    code+="PUSH AX\n";
    return code;
}
string print()
{
    string code="POP NUMBER\nCALL PRINT_NUMBER\n\n";
    return code;
}
#endif