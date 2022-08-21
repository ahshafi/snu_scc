%option noyywrap
%x STRING
%x sCOMMENT
%x mCOMMENT
%{
#include<bits/stdc++.h>
using namespace std;
extern fstream enlog;
extern fstream err;
#include "SymbolInfo.h"
#include "SymbolTable.h"
#include "ScopeTable.h"
#include "y.tab.h"


extern YYSTYPE yylval;
extern SymbolTable *table;
extern SymbolTable st;
void yyerror(char *);


int line_count=1;
string state="INITIAL";
string str;
bool escape=false;

fstream latoken("error.txt", std::ofstream::out | std::ofstream::trunc);

void logger(string error)
{
	latoken<<"Line No. "<<line_count<<": "<<error<<"\n";
}
void set_yylval(string name,string  type) {
	SymbolInfo *s= new  SymbolInfo(yytext, type);
	yylval.symbolInfo = s;	
}

%}
AlphaNumeric [a-zA-Z0-9_]
Printables [^\'\n\t\r\f\v]
delim [ \t\v]
ws {delim}+
letter [A-Za-z_]
digit [0-9]
id {letter}({letter}|{digit})*
integer {digit}+
float {digit}*(\.{digit}+)?(E[+-]?{digit}+)?



%%

"if" {set_yylval(yytext, "IF"); return IF;}
"else" {set_yylval(yytext, "ELSE"); return ELSE;}
"for" {set_yylval(yytext, "FOR"); return FOR;}
"while" {set_yylval(yytext, "WHILE"); return WHILE;}
"int" {set_yylval(yytext, "INT"); return INT;}
"float" {set_yylval(yytext, "FLOAT"); return FLOAT;}
"return" {set_yylval(yytext, "RETURN"); return RETURN;}
"void" {set_yylval(yytext, "VOID"); return VOID;}
"println" {set_yylval(yytext, "PRINTLN"); return PRINTLN;}

<INITIAL>{ws} {}
<INITIAL>[\n] { line_count++; }

<INITIAL>{integer} {
		set_yylval(yytext, "CONST_INT");
		return CONST_INT;
	}
<INITIAL>{float} {
		set_yylval(yytext, "CONST_FLOAT");
		return CONST_FLOAT;
	}

<INITIAL>"\'\\n\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\t\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\a\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\f\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\r\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\b\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\v\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\0\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\\\\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>"\'\\\'\'" { set_yylval(yytext, "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>'{Printables}{1}' { set_yylval(string(1, yytext[1]), "CONST_CHAR"); return CONST_CHAR; }
<INITIAL>'' { logger("EMPTY_CHARACTER_ERROR"); }
<INITIAL>'[^'\n][^'\n]+' { logger("MULTIPLE_CHARACTER_ERROR"); }
<INITIAL>'[\t\r\f\v]' { logger("INVALID_CHARACTER_ERROR"); }
<INITIAL>'[^'\n]*[\n] { logger("UNFINISHED_CHARACTER_ERROR"); line_count++ ;}
<INITIAL>'[^'\n]* { logger("UNFINISHED_CHARACTER_ERROR"); }

<INITIAL>{id} {
		set_yylval(yytext, "ID");
		return ID;
	}
<INITIAL>(({integer}{letter})|({float}({letter}|\.)))({AlphaNumeric}|\.)* { logger("INVALID_NUMBER\\ID_ERROR"); }

<INITIAL>[+-] { set_yylval(yytext, "ADDOP"); return ADDOP; }
<INITIAL>[*/%] {  set_yylval(yytext, "MULOP"); return MULOP;}
<INITIAL>("++") {  set_yylval(yytext, "INCOP"); return INCOP;}
<INITIAL>("--") {  set_yylval(yytext, "INCOP"); return DECOP;}
<INITIAL>("<"|"<="|">"|">="|"=="|"!=") {  set_yylval(yytext, "RELOP"); return RELOP;}
<INITIAL>"=" { set_yylval(yytext, "ASSIGNOP"); return ASSIGNOP; }
<INITIAL>("&&"|"||") {  set_yylval(yytext, "LOGICOP"); return LOGICOP;}
<INITIAL>"!" { set_yylval(yytext, "NOT"); return NOT; }
<INITIAL>"\(" { set_yylval(yytext, "LPAREN"); return LPAREN; }
<INITIAL>"\)" {  set_yylval(yytext, "RPAREN"); return RPAREN;}
<INITIAL>"{" { set_yylval(yytext, "LCURL"); return LCURL;}
<INITIAL>"}" { set_yylval(yytext, "RCURL"); return RCURL;}
<INITIAL>"[" { set_yylval(yytext, "LTHIRD"); return LTHIRD; }
<INITIAL>"]" {  set_yylval(yytext, "RTHIRD"); return RTHIRD;}
<INITIAL>"," { set_yylval(yytext, "COMMA"); return COMMA; }
<INITIAL>";" { set_yylval(yytext, "SEMICOLON"); return SEMICOLON; }



<INITIAL>"\"" { BEGIN STRING; state="STRING";}
<STRING>"\\" { 
            //latoken<<"\nholna\n";
            if(!escape) escape=true;
            else escape=false, str.push_back('\\');     
        }
<STRING>. {
            if(escape){
               if(yytext[0]=='t') str.push_back('\t');
               else if(yytext[0]=='v') str.push_back('\v');
               else if(yytext[0]=='n') str.push_back('\n');
               else if(yytext[0]=='a') str.push_back('\n');
               else if(yytext[0]=='b') str.push_back('\v');
               else if(yytext[0]=='f') str.push_back('\f');
               else if(yytext[0]=='r') str.push_back('\r');
               else if(yytext[0]=='0') str.push_back('\0');
               else if(yytext[0]=='\"') str.push_back('\"');
               else str.push_back(0);

               escape=false;
            }
            else if(yytext[0]=='\"') {
                BEGIN INITIAL;
                state="INITIAL";
                set_yylval(yytext, "STRING");
				return STRING; 
                str.clear( );
                //escape=false;
            }
            else  str.push_back(yytext[0]);
        }
<STRING>[\n] {
            if(!escape ) {
             BEGIN INITIAL;
             logger("UNFINISHED_STRING_ERROR"); 
             str.clear();
             }
            else escape=false;
            line_count++;
        }
<STRING><<EOF>> { logger("UNFINISHED_STRING_ERROR"); }

<INITIAL>"//" { BEGIN sCOMMENT; state="sCOMMENT";}
<sCOMMENT>"\\\n" { str.push_back('\n'); line_count++; }
<sCOMMENT>. { str.push_back(yytext[0]); }
<sCOMMENT>[\n] {
            BEGIN INITIAL;
            state="INITIAL"; 
            str.clear( );
            line_count++;
        }
<sCOMMENT><<EOF>> {}

<INITIAL>"/*" { BEGIN mCOMMENT; state="mCOMMENT"; }
<mCOMMENT>.|[\n] { str.push_back(yytext[0]); line_count+=yytext[0]=='\n'; }
<mCOMMENT>"*/" {
            BEGIN INITIAL;
            state="INITIAL";
            str.clear( );
        }
<mCOMMENT><<EOF>> { logger("UNFINISHED_COMMENT_ERROR"); }


<INITIAL>. { logger("UNRECOGNIZED_CHARACTER_ERROR"); }

%%

