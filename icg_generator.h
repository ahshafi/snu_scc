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
string push_literal(string val)
{
    string code="PUSH "+val+"\n\n";
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
    { code="POP BX\nPOP AX\nIDIV BX\nPUSH AX\n\n";
    }
    if(op=="%")
    { code="POP BX\nPOP AX\nIDIV BX\nPUSH DX\n\n";
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
    { code="POP AX\nPOP BX\nAND AX, BX\nPUSH AX\n\n";
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
        code+="POP AX\nCMP AX, 0\nJE "+true_label+"\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    
    }
    return code;
}
string relop(string op)
{
    string code;
    if(op=="=="){
        string true_label=new_label();
        string exit_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJE "+true_label+"\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op=="!="){
        string true_label=new_label();
        string exit_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJNE "+true_label+"\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op=="<"){
        string true_label=new_label();
        string exit_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJL "+true_label+"\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op==">"){
        string true_label=new_label();
        string exit_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJG "+true_label+"\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op=="<="){
        string true_label=new_label();
        string exit_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJLE "+true_label+"\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    if(op==">="){
        string true_label=new_label();
        string exit_label=new_label();
        code+="POP BX\nPOP AX\nCMP AX, BX\nJGE "+true_label+"\nPUSH 0\nJMP "+exit_label+"\n"+true_label+":\n"+"PUSH 1\n"+exit_label+":\n\n";
    }
    return code;
}
string assignop(string var)
{
    string asm_name=st.lookup(var)->lookup(var)->asm_name;
    string code="POP AX\nMOV "+asm_name+", AX\n\n";
    return code;
}
string jump_if_false(string label)
{
    string code="POP AX\nCMP AX, 0\nJE "+label+"\n\n";
    return code;
}
string jump(string label)
{
    string code="JMP "+label+"\n\n";
    return code;
}
#endif