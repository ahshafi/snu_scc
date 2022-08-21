%{
#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
fstream enlog("log.txt", std::ofstream::out | std::ofstream::trunc);
fstream gic("code.asm", std::ofstream::out | std::ofstream::trunc);
#include "SymbolTable.h"

int yyparse(void);
int yylex(void);
extern FILE *yyin;

extern int line_count;

SymbolTable st(10);
bool in=false;
fstream err("error.txt", std::ofstream::out | std::ofstream::trunc);
int error_count=0;

#include "semantic_processor.h"
#include "icg_generator.h"
void yyerror(char *s)
{
	error_count++;
	err<<"Syntax error at Line: "<<line_count<<"\n";
}
void rule_matched(string rule, string phrase)
{
	
	enlog<<"Line "<<line_count<<": "<<rule<<"\n";
	enlog<<phrase<<"\n";
}

template<class T>
ostream& operator<<(ostream &os, vector<T> &vec)
{
	for(auto v: vec) cout<<v<<" ";
	return os;
}

stack<string> iflabel, whilelabel, forlabel;
%}

%union 
{
	SymbolInfo *symbolInfo;
}
%token <symbolInfo> IF ELSE FOR WHILE INT FLOAT RETURN VOID PRINTLN ADDOP MULOP ASSIGNOP RELOP LOGICOP NOT SEMICOLON COMMA LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD INCOP DECOP CONST_INT CONST_FLOAT ID STRING CONST_CHAR
%type <symbolInfo> start program unit var_declaration func_declaration func_definition type_specifier parameter_list declaration_list statements statement simple_statement expression_statement conditional_expression_statement  compound_statement expression conditional_expression variable logic_expression rel_expression simple_expression term unary_expression factor argument_list arguments




%%

start : program
	{
		$$=new SymbolInfo();
			$$->name=$1->name;
		rule_matched("start : program", $$->name);
	}
	;

program : program unit 
	{
		$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name;
		rule_matched("program : program unit", $$->name);
	}
	| unit
	{
		$$=new SymbolInfo();
			$$->name=$1->name;
		rule_matched("program : unit", $$->name);
	}
	;
	
unit : var_declaration
	{
		$$=new SymbolInfo();
		$$->name=$1->name;
		rule_matched("unit : var_declaration", $$->name);
	}
     | func_declaration
     {
     		$$=new SymbolInfo();
			$$->name=$1->name;
		rule_matched("unit : func_declaration", $$->name);
     }
     | func_definition
     {
     		$$=new SymbolInfo();
			$$->name=$1->name;
		rule_matched("unit : func_definition", $$->name);
     }
     ;
     
func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$5->name+" "+$6->name;
			process_function_declaration($2->name, $1->name, $4->param, $4->pids);
			rule_matched("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON", $$->name);
			
		}
		| type_specifier ID LPAREN RPAREN SEMICOLON
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$5->name;
			process_function_declaration($2->name, $1->name, vector<string>(), vector<string>());
			rule_matched("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON", $$->name);
		}
		;
		 
func_definition : type_specifier ID LPAREN parameter_list RPAREN 
		{
			//cout<<"faker\n";
			process_function_definition($2->name, $1->name, $4->param, $4->pids);
			
			generate_declaration($4->pids);
			code_seg+=$2->name+" PROC\n";
			code_seg+=parapass($4->pids);
			
			if($2->name=="main") code_seg+="MOV AX, @DATA\nMOV DS, AX\n";
		}
		compound_statement
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$5->name+" "+$7->name;
			rule_matched("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement", $$->name);
			
			if($2->name=="main") code_seg+="MOV AH, 4CH\nINT 21H\n\n";
			else code_seg+=return_func();

			code_seg+=$2->name+" ENDP\n";
			if($2->name=="main") code_seg+="END MAIN\n";
		}
		| type_specifier ID LPAREN RPAREN
		{
			//cout<<"faker\n";
			process_function_definition($2->name, $1->name, vector<string>(), vector<string>());
		
			code_seg+=$2->name+" PROC\n";
			if($2->name=="main") code_seg+="MOV AX, @DATA\nMOV DS, AX\n";
		}
		compound_statement
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$6->name;
			rule_matched("func_definition : type_specifier ID LPAREN RPAREN compound_statement", $$->name);
			
			if($2->name=="main") code_seg+="MOV AH, 4CH\nINT 21H\n\n";
			else code_seg+=return_func();

			code_seg+=$2->name+" ENDP\n";
			if($2->name=="main") code_seg+="END MAIN\n";
		}
		
 		;				


parameter_list  : parameter_list COMMA type_specifier ID
		{
			
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name;
			//process_parameter_list($1->param, $3->name, $4->name, $$);

			$$->param=$1->param;
			$$->param.push_back("CONST_"+to_upper($3->name));
			$$->pids=$1->pids;
			$$->pids.push_back($4->name);
			
			rule_matched("parameter_list  : parameter_list COMMA type_specifier ID", $$->name);
		}
		| parameter_list COMMA type_specifier
		{
			
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name;

			$$->param=$1->param;
			$$->param.push_back("CONST_"+to_upper($3->name));
			$$->pids=$1->pids;
			$$->pids.push_back("");
			
			rule_matched("parameter_list  : parameter_list COMMA type_specifier", $$->name);
		}
 		| type_specifier ID
 		{
 			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name;

			$$->param.push_back("CONST_"+to_upper($1->name));
			$$->pids.push_back($2->name);

			rule_matched("parameter_list  : type_specifier ID", $$->name);
 		}
		| type_specifier
		{
			
 			$$=new SymbolInfo();
			$$->name=$1->name;

			$$->param.push_back("CONST_"+to_upper($1->name));
			$$->pids.push_back("");

			rule_matched("parameter_list  : type_specifier", $$->name);
 		}
 		;

 		
compound_statement : LCURL 
			{
				//cout<<"ayo1\n";
				if(!in){
					st.enter();
					//cout<<"entered\n";
				}
				else in=false;
				//cout<<"ayo2\n";
			}
			statements RCURL
		    {
				//cout<<"compound_statement\n";
				

				$$=new SymbolInfo();
				$$->name=$1->name+" "+$3->name+" "+$4->name;
				rule_matched("compound_statement : LCURL statements RCURL", $$->name);
				st.printAll();
				st.exit();
				//cout<<"exited\n";
		    }
 		    | LCURL
			{
				//cout<<"ayo\n";
				if(!in){
					st.enter();
					//cout<<"entered\n";
				}
				else in=false;
			}
			RCURL
 		    {
				//cout<<"compound_statement\n";
				
				$$=new SymbolInfo();
				$$->name=$1->name+" "+$3->name;
				rule_matched("compound_statement : LCURL RCURL", $$->name);	

				st.printAll();
				st.exit();
				//cout<<"exited\n";
 		    }
			
 		    ;
 	  
var_declaration : type_specifier declaration_list SEMICOLON
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name;
			process_var_declaration($1->name, $2->param);
			//generate_declaration($2->param);
			rule_matched("var_declaration : type_specifier declaration_list SEMICOLON", $$->name);	
		}
 		 ;
 		 
type_specifier	: INT
		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			rule_matched("type_specifier	: INT", $$->name);
		}
 		| FLOAT
 		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			rule_matched("type_specifier	: FLOAT", $$->name);
		}
 		| VOID
 		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			rule_matched("type_specifier	: VOID", $$->name);
		}
 		;
 		
declaration_list : declaration_list COMMA ID
		  {
		  	$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name;
			process_declaration_list($1->param, $3->name, "VAR", $$);
			rule_matched("declaration_list : declaration_list COMMA ID", $$->name);
		  
		  	generate_declaration($3->name);
		  }
 		  | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
 		  {
 		  	$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$5->name+" "+$6->name;
			process_declaration_list($1->param, $3->name, "VAR_ARRAY", $$);
			rule_matched("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", $$->name);
 		  
		  	generate_declaration($3->name, $5->name);
		  }
 		  | ID
 		  {
 		  	$$=new SymbolInfo();
			$$->name=$1->name;
			process_declaration_list(vector<string>(), $1->name, "VAR", $$);
			generate_declaration($1->name);
			rule_matched("declaration_list : ID", $$->name);
 		  }
 		  | ID LTHIRD CONST_INT RTHIRD
 		  {
 		  	$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name;
			process_declaration_list(vector<string>(), $1->name, "VAR_ARRAY", $$);
			generate_declaration($1->name, $3->name);
			rule_matched("declaration_list : ID LTHIRD CONST_INT RTHIRD", $$->name);
 		  }
 		  ;
 		  
statements : statement
	   {
	   	$$=new SymbolInfo();
		$$->name=$1->name;
		rule_matched("statements : statement", $$->name);
	   }
	   | statements statement
	   {
	   	$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name;
		rule_matched("statements : statements statement", $$->name);
	   }
	   ;

	   
simple_statement : var_declaration
	  {
	  	$$=new SymbolInfo();
		$$->name=$1->name;
		rule_matched("simple_statement : var_declaration", $$->name);
	  }
	  | expression_statement
	  {
	  	$$=new SymbolInfo();
		$$->name=$1->name;
		rule_matched("simple_statement : expression_statement", $$->name);
	  }
	  | compound_statement
	  {
	  	$$=new SymbolInfo();
		$$->name=$1->name;
		rule_matched("simple_statement : compound_statement", $$->name);
	  }
	  | FOR 
	  {
		code_seg+=";start for loop\n";
	  }
	  LPAREN expression_statement 
	  {
		string loop_label=new_label();
		forlabel.push(loop_label);
		code_seg+=loop_label+":\n";
	  }
	  conditional_expression_statement expression 
	  {
		string tail_label=forlabel.top(); forlabel.pop();
		string body_label=forlabel.top(); forlabel.pop();
		string exit_label=forlabel.top(); forlabel.pop();
		string loop_label=forlabel.top(); forlabel.pop();
		code_seg+=unary_pop();
		code_seg+=jump(loop_label);
		code_seg+=body_label+":\n";
		forlabel.push(exit_label), forlabel.push(tail_label);
	  }
	  RPAREN simple_statement
	  {
	  	$$=new SymbolInfo();
		//$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$5->name+" "+$6->name+" "+$7->name;
	  	rule_matched("simple_statement : FOR LPAREN expression_statement expression_statement expression RPAREN simple_statement", $$->name);
	  
	  	string tail_label=forlabel.top(); forlabel.pop();
		code_seg+=jump(tail_label);
		string exit_label=forlabel.top(); forlabel.pop();
		code_seg+=exit_label+":\n\n";
		code_seg+=";end for loop\n";
	  }
	  | IF LPAREN conditional_expression RPAREN simple_statement
	  {
		string false_label=iflabel.top(); iflabel.pop();
		string exit_label=iflabel.top(); iflabel.pop();
		code_seg+=jump(exit_label);
		code_seg+=false_label+":\n";
		code_seg+=exit_label+":\n\n";

	  	$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$5->name;
	  	rule_matched("simple_statement : IF LPAREN expression RPAREN simple_statement", $$->name);
	  }
	  | WHILE 
	  {
		whilelabel.push(new_label());
		code_seg+=whilelabel.top()+":\n";
	  }
	  LPAREN expression 
	  {
		whilelabel.push(new_label());
		code_seg+=jump_if_false(whilelabel.top());
	  }
	  RPAREN simple_statement
	  {
	  	$$=new SymbolInfo();
		//$$->name=$1->name+" "+$3->name+" "+$4->name+" "+$6->name+" "+$7->name;
	  	rule_matched("simple_statement : WHILE LPAREN expression RPAREN simple_statement", $$->name);
	  
	  	string exit_label=whilelabel.top(); whilelabel.pop();
		string loop_label=whilelabel.top(); whilelabel.pop();
		code_seg+=jump(loop_label);
		code_seg+=exit_label+":\n\n";
	  }
	  | PRINTLN LPAREN ID RPAREN SEMICOLON
	  {
	  	$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$5->name;
	  	rule_matched("simple_statement : PRINTLN LPAREN ID RPAREN SEMICOLON", $$->name);
	  }
	  | RETURN expression SEMICOLON
	  {
	  	$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name+" "+$3->name;
	  	rule_matched("simple_statement : RETURN expression SEMICOLON", $$->name);

		code_seg+=return_func();
	  }
	  ;

statement: simple_statement
	  {
	  	$$=new SymbolInfo();
		$$->name=$1->name;
		rule_matched("statement: simple_statement", $$->name);
	  }
	  | IF LPAREN conditional_expression RPAREN
	  simple_statement ELSE 
	  {
		string false_label=iflabel.top(); iflabel.pop();
		string exit_label=iflabel.top();
		code_seg+=jump(exit_label);
		code_seg+=false_label+":\n";
	  }
	  statement
	  {
	  	$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$5->name+" "+$6->name+" "+$8->name;
	  	rule_matched("statement : IF LPAREN expression RPAREN simple_statement ELSE statement", $$->name);
	  	
		string exit_label=iflabel.top(); iflabel.pop();
		code_seg+=exit_label+":\n\n";
	  } 
 	;
conditional_expression : expression
			{
				string exit_label=new_label();
				string false_label=new_label();
				iflabel.push(exit_label);
				iflabel.push(false_label);
				code_seg+=jump_if_false(false_label);
	  		}
conditional_expression_statement : SEMICOLON	
			{
				$$=new SymbolInfo();
				$$->name=$1->name;
				rule_matched("expression_statement : SEMICOLON", $$->name);

				string exit_label=new_label();
				forlabel.push(exit_label);

				string body_label=new_label();
				forlabel.push(body_label);
				code_seg+=jump(body_label);

				string tail_label=new_label();
				forlabel.push(tail_label);
				code_seg+=tail_label+":\n";
			}		
			| expression SEMICOLON 
			{
				$$=new SymbolInfo();
				$$->name=$1->name+" "+$2->name;
	  			rule_matched("expression_statement : expression SEMICOLON ", $$->name);

				string exit_label=new_label();
				forlabel.push(exit_label);
				code_seg+=jump_if_false(exit_label);

				string body_label=new_label();
				forlabel.push(body_label);
				code_seg+=jump(body_label);

				string tail_label=new_label();
				forlabel.push(tail_label);
				code_seg+=tail_label+":\n";
			}
			;
expression_statement : SEMICOLON	
			{
				$$=new SymbolInfo();
				$$->name=$1->name;
				rule_matched("expression_statement : SEMICOLON", $$->name);
			}		
			| expression SEMICOLON 
			{
				$$=new SymbolInfo();
				$$->name=$1->name+" "+$2->name;
	  			rule_matched("expression_statement : expression SEMICOLON ", $$->name);

				code_seg+=unary_pop();
			}
			;

variable : ID 
		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			$$->ret=process_variable($1->name,"VAR");
			$$->type="VAR";
			rule_matched("variable : ID", $$->name);
		}
	 	| ID LTHIRD expression RTHIRD 
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name;
			$$->ret=process_variable($1->name,"VAR_ARRAY");
			$$->type="VAR_ARRAY";
			if($3->ret!="CONST_INT" and $3->ret!="DUMMY"){
				error("non_const_integer used as array subscript in variable: "+$1->name);
			}
	  		rule_matched("variable : ID LTHIRD expression RTHIRD", $$->name);

			
		}
	 ;
	 
expression : logic_expression	
		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			$$->ret=$1->ret;
			rule_matched("expression : logic_expression", $$->name);
		}
	   	| variable ASSIGNOP logic_expression 	
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name;

			if($3->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if($1->ret=="CONST_INT" and $3->ret=="CONST_FLOAT"){
				error("float type expression assigned to integer type variable: "+$1->name);
				$$->ret="CONST_INT";
			}
			if($1->ret=="DUMMY" or $3->ret=="DUMMY" or $1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				$$->ret="DUMMY";
			}
			else $$->ret=$1->ret;

	  		rule_matched("expression : variable ASSIGNOP logic_expression", $$->name);
		
			code_seg+=assignop($1->name, $1->type);
		}
	   ;
			
logic_expression : rel_expression 
		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			$$->ret=$1->ret;
			rule_matched("logic_expression : rel_expression", $$->name);
		}
		| rel_expression LOGICOP rel_expression 	
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name;

			if($1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if($1->ret=="DUMMY" or $3->ret=="DUMMY" or $1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				$$->ret="DUMMY";
			}
			else {
				$$->ret="CONST_INT";
			}

	  		rule_matched("logic_expression : rel_expression LOGICOP rel_expression", $$->name);
		
			code_seg+=binary_logicop($2->name);
		}
		;
			
rel_expression	: simple_expression 
		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			$$->ret=$1->ret;
			rule_matched("rel_expression : simple_expression", $$->name);
		}
		| simple_expression RELOP simple_expression	
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name;
			
			if($1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if($1->ret=="DUMMY" or $3->ret=="DUMMY" or $1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				$$->ret="DUMMY";
			}
			else {
				$$->ret="CONST_INT";
			}

	  		rule_matched("rel_expression : simple_expression RELOP simple_expression", $$->name);
		
			code_seg+=relop($2->name);
		}
		;
				
simple_expression : term 
		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			$$->ret=$1->ret;
			rule_matched("simple_expression : term", $$->name);
		}
		| simple_expression ADDOP term 
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name;

			if($1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if($1->ret=="DUMMY" or $3->ret=="DUMMY" or $1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				$$->ret="DUMMY";
			}
			else if($1->ret=="CONST_FLOAT" or $3->ret=="CONST_FLOAT"){
				$$->ret="CONST_FLOAT";
			}
			else {
				$$->ret="CONST_INT";
			}

	  		rule_matched("simple_expression : simple_expression ADDOP term", $$->name);
		
			code_seg+=binary_addop($2->name);
		}
		;
					
term :	unary_expression
		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			$$->ret=$1->ret;
			rule_matched("term : unary_expression", $$->name);
		}
     	|  term MULOP unary_expression
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name+" "+$3->name;

			if($1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if($2->name=="%"){
				if($3->name=="0"){
					error("0 used as an operand for modulus operator");
				}
				if($1->ret=="CONST_FLOAT" or $3->ret=="CONST_FLOAT"){
					error("float type expression used as an operand for modulus operator");
				}
			}

			else if($1->ret=="DUMMY" or $3->ret=="DUMMY" or $1->ret=="CONST_VOID" or $3->ret=="CONST_VOID"){
				$$->ret="DUMMY";
			}
			else if($1->ret=="CONST_FLOAT" or $3->ret=="CONST_FLOAT"){
				$$->ret="CONST_FLOAT";
			}
			else {
				$$->ret="CONST_INT";
			}
	  		rule_matched("term : term MULOP unary_expression", $$->name);

			code_seg+=binary_mulop($2->name);
		}
     	;

unary_expression : ADDOP unary_expression  
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name;
			if($2->ret=="CONST_VOID"){
				$$->ret="DUMMY";
				error("Void function used in expression");
			}
			else $$->ret=$2->ret;
	  		rule_matched("unary_expression : ADDOP unary_expression", $$->name);

			code_seg+=unary_addop($1->name);
		}
		| NOT unary_expression 
		{
			$$=new SymbolInfo();
			$$->name=$1->name+" "+$2->name;
			if($2->ret=="CONST_VOID"){
				$$->ret="DUMMY";
				error("Void function used in expression");
			}
			else $$->ret="CONST_INT";
	  		rule_matched("unary_expression : NOT unary_expression", $$->name);

			code_seg+=unary_logicop($1->name);
		}
		| factor 
		{
			$$=new SymbolInfo();
			$$->name=$1->name;
			$$->ret=$1->ret;
			rule_matched("unary_expression : factor", $$->name);
		}
		;
	
factor	: variable 
	{
		$$=new SymbolInfo();
		$$->name=$1->name;
		$$->ret=$1->ret;
		rule_matched("factor : variable", $$->name);

		if($1->type=="VAR") code_seg+=push_var($1->name);
		else if($1->type=="VAR_ARRAY") code_seg+=push_varray($1->name);
	}
	| ID LPAREN argument_list RPAREN
	{
		//cout<<"ID LPAREN argument_list RPAREN\n";
		$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name;
		$$->ret=process_function_call($1->name, $3->param);
	  	rule_matched("factor : ID LPAREN argument_list RPAREN", $$->name);

		code_seg+=call_func($1->name);
	}
	| LPAREN expression RPAREN
	{
		$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name+" "+$3->name;
		$$->ret=$2->ret;
	  	rule_matched("factor : LPAREN expression RPAREN", $$->name);
	}
	| CONST_INT 
	{
		$$=new SymbolInfo();
		$$->name=$1->name;
		$$->ret="CONST_INT";
		rule_matched("factor : CONST_INT", $$->name);

		code_seg+=push_literal($1->name);
	}
	| CONST_FLOAT
	{
		$$=new SymbolInfo();
		$$->name=$1->name;
		$$->ret="CONST_FLOAT";
		rule_matched("factor : CONST_FLOAT", $$->name);
	}
	| variable INCOP 
	{
		$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name;
		$$->ret=$1->ret;
	  	rule_matched("factor : variable INCOP", $$->name);

		code_seg+=incop($1->name, $1->type);
	}
	| variable DECOP
	{
		$$=new SymbolInfo();
		$$->name=$1->name+" "+$2->name;
		$$->ret=$1->ret;
	  	rule_matched("factor : variable DECOP", $$->name);

		code_seg+=decop($1->name, $1->type);
	}
	;
	
argument_list : arguments
			{
				$$=new SymbolInfo();
				$$->name=$1->name;
				$$->param=$1->param;
				rule_matched("argument_list : arguments", $$->name);
			}
			|
			{
				$$=new SymbolInfo();
				rule_matched("argument_list : ", $$->name);
			}
			;
	
arguments : arguments COMMA logic_expression
			{
				$$=new SymbolInfo();
				$$->name=$1->name+" "+$2->name+" "+$3->name;
				$$->param=$1->param;
				$$->param.push_back($3->ret);
	  			rule_matched("arguments : arguments COMMA logic_expression", $$->name);
			}
	      	| logic_expression
			{
				$$=new SymbolInfo();
				$$->name=$1->name;
				$$->param.push_back($1->ret);
				rule_matched("arguments : logic_expression", $$->name);
			}
	      	;
 

%%
//asm code
string initiation=".MODEL SMALL\n.STACK 100H\n";
string data_seg=".DATA\n";
string code_seg=".CODE\n";
string icg;
//asm code
void init()
{

}
int main(int argc, char* argv[])
{
	//fastio;
	st.enter();
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	yyin= fin;

	yyparse();
	st.printAll();
	enlog<<"Total Line: "<<line_count<<"\n";
	err<<"Total Error: "<<error_count<<"\n";
	st.exit();

	icg=initiation+data_seg+code_seg;
	cout<<icg;
	return 0;
}

