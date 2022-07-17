#ifndef SEMANTIC_PROCESSOR_H
#define SEMANTIC_PROCESSOR_H
#include<bits/stdc++.h>
#include "SymbolTable.h"
using namespace std;

void error(string message)
{
    error_count++;
	err<<"Error at line "<<line_count<<": "<<message<<"\n";
}
string to_upper(string str)
{
    for(auto &v: str) v+='A'-'a';
    return str;
}
void process_parameter_list(vector<string> prev_list, string new_type, string new_var, SymbolInfo* &cur_list)
{
    cur_list->param=prev_list;
    cur_list->param.push_back("CONST_"+to_upper(new_type));
    SymbolInfo* s=st.insert(new_var, "PAR_VAR");
    if(s==NULL){
        error("redeclaration of parameter variable: "+new_var);
    }
    else {
        s->ret="CONST_"+to_upper(new_type);
    }
    if(new_type=="void"){
        error("void parameter variable: "+new_var);
    }
}
void process_function_declaration(string func_name, string ret_type, vector<string> param, vector<string> pids)
{
    SymbolInfo* s=st.curScope->lookup(func_name);
    if(s==NULL){
        s=st.insert(func_name, "FUNC_DEC");
        s->param=param;
        s->ret="CONST_"+to_upper(ret_type);
    }
    else if(!(s->type=="FUNC_DEF" or s->type=="FUNC_DEC")){
         error("variable name used as function name in function declaration: "+func_name);
         //return;
    }
    else if(s->param.size()!=param.size()){
        error("Total number of arguments mismatch with declaration in function: "+func_name);
    }
    else if(s->param!=param){
        error("mismatch in parameter type in function declaration: "+func_name);
        //return;
    }
    else if(s->ret!="CONST_"+to_upper(ret_type)){
        error("mismatch in return type of function declaration: "+func_name);
        //return;
    }
    st.enter( );
    for(int i=0;i<pids.size(   );i++){
        string id=pids[i];
        if(!id.empty()){
            SymbolInfo* s=st.insert(id, "VAR");
            if(s==NULL){
                error("redeclaration of parameter variable: "+id);
            }
            else {
                s->ret="CONST_"+to_upper(param[i]);
            }
            if(param[i]=="void"){
                error("void parameter variable: "+id);
            }
        }
    }
    st.printAll();
    st.exit();
}
void process_function_definition(string func_name, string ret_type, vector<string> param, vector<string> pids)
{
    SymbolInfo* s=st.curScope->lookup(func_name);
    if(s==NULL) {
        s=st.insert(func_name, "FUNC_DEF");
        s->param=param;
        s->ret="CONST_"+to_upper(ret_type);
    }
    else if(s->type=="FUNC_DEC" and s->param==param and s->ret==ret_type){
        s->type="FUNC_DEF";
        //return;
    }
    else if(s->type=="FUNC_DEF"){
        error("redefinition of function in function definition: "+func_name);
        //return;
    }
    else if(s->type=="VAR"){
        error("variable name used as function name in function definition: "+func_name);
        //return;
    }
    else if(s->param.size()!=param.size()){
        error("Total number of arguments mismatch with declaration in function: "+func_name);
    }
    else if(s->param!=param){
        error("mismatch in parameter type in function declaration: "+func_name);
        //return;
    }
    else if(s->ret!="CONST_"+to_upper(ret_type)){
        error("mismatch in return type of function definition: "+func_name);
        //return;
    }
    st.enter( );
    in=true;
    //cout<<"bolo\n";
    for(int i=0;i<pids.size(   );i++){
        string id=pids[i];
        if(!id.empty()){
            SymbolInfo* s=st.insert(id, "VAR");
            if(s==NULL){
                error("redeclaration of parameter variable: "+id);
            }
            else {
                s->ret="CONST_"+to_upper(param[i]);
            }
            if(param[i]=="void"){
                error("void parameter variable: "+id);
            }
        }
    }
    //cout<<"bolbona\n";
}
void process_declaration_list(vector<string> prev_dec, string new_dec, string new_type, SymbolInfo* &cur_dec)
{
    SymbolInfo* s=st.curScope->lookup(new_dec);
    if(s==NULL){
        //cout<<"ayo\n";
        s=st.insert(new_dec, new_type);
        cur_dec->param=prev_dec;
        cur_dec->param.push_back(new_dec);
    }
    else if(s->type=="FUNC_DEC" or s->type=="FUNC_DEF")
        error("use of function name as variable name in variable: "+new_dec);
    else if(s->type=="VAR" or s->type=="VAR_ARRAY"){
        error("redeclaration of variable: "+new_dec);
    }
}
void process_var_declaration(string type, vector<string> dec_list)
{
    if(type=="void") error("variable must be non-void");
    for(auto var: dec_list){
        SymbolInfo* s=st.curScope->lookup(var);
        s->ret="CONST_"+to_upper(type);
    }
}
string process_variable(string var, string type)
{
    ScopeTable* t=st.lookup(var);
    if(t==nullptr){
        error("no declaration of variable: "+var);
        return "DUMMY";
    }
    SymbolInfo* s=t->lookup(var);
    if(s->type!=type){
        error(var+" is not declared as "+type);
    }
    return s->ret;
}
string process_function_call(string func_name, vector<string> args)
{
    //cout<<func_name<<"\n";
    ScopeTable* t=st.lookup(func_name);
    //cout<<"trprbolo2\n";
    if(t==nullptr){
        error("undeclared function: "+func_name);
        return "DUMMY";
    }
    SymbolInfo* s=t->lookup(func_name);
    if(s->type!="FUNC_DEF" and s->type!="FUNC_DEC"){
        error("not a function: "+func_name);
        return "DUMMY";
    }

    else if(s->param.size()!=args.size()){
        error("total number of arguments mismatch in function_call: "+func_name);
        return s->ret;
    }
    else {
        for(int i=0;i<args.size();i++){
            if(args[i]=="CONST_VOID"){
                error("void type expression used as "+to_string(i+1)+"th argument of function_call: "+func_name);
            }
            if(!((s->param[i]=="CONST_FLOAT" and args[i]=="CONST_INT") or s->param[i]==args[i] or args[i]=="DUMMY")){
                error("type mismatch in "+to_string(i+1)+"th argument in function_call: "+func_name);
            }
        }
        return s->ret;
    }
}
#endif
