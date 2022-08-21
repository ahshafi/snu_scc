/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     FOR = 260,
     WHILE = 261,
     INT = 262,
     FLOAT = 263,
     RETURN = 264,
     VOID = 265,
     PRINTLN = 266,
     ADDOP = 267,
     MULOP = 268,
     ASSIGNOP = 269,
     RELOP = 270,
     LOGICOP = 271,
     NOT = 272,
     SEMICOLON = 273,
     COMMA = 274,
     LPAREN = 275,
     RPAREN = 276,
     LCURL = 277,
     RCURL = 278,
     LTHIRD = 279,
     RTHIRD = 280,
     INCOP = 281,
     DECOP = 282,
     CONST_INT = 283,
     CONST_FLOAT = 284,
     ID = 285,
     STRING = 286,
     CONST_CHAR = 287
   };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define WHILE 261
#define INT 262
#define FLOAT 263
#define RETURN 264
#define VOID 265
#define PRINTLN 266
#define ADDOP 267
#define MULOP 268
#define ASSIGNOP 269
#define RELOP 270
#define LOGICOP 271
#define NOT 272
#define SEMICOLON 273
#define COMMA 274
#define LPAREN 275
#define RPAREN 276
#define LCURL 277
#define RCURL 278
#define LTHIRD 279
#define RTHIRD 280
#define INCOP 281
#define DECOP 282
#define CONST_INT 283
#define CONST_FLOAT 284
#define ID 285
#define STRING 286
#define CONST_CHAR 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 45 "1805016.y"
{
	SymbolInfo *symbolInfo;
}
/* Line 1529 of yacc.c.  */
#line 117 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

