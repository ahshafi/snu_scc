/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "1805016.y"

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

stack<string> iflabel;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 45 "1805016.y"
{
	SymbolInfo *symbolInfo;
}
/* Line 193 of yacc.c.  */
#line 207 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   166

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    23,
      29,    30,    38,    39,    46,    51,    55,    58,    60,    61,
      66,    67,    71,    75,    77,    79,    81,    85,    92,    94,
      99,   101,   104,   106,   108,   110,   118,   124,   130,   136,
     140,   142,   143,   152,   154,   156,   159,   161,   166,   168,
     172,   174,   178,   180,   184,   186,   190,   192,   196,   199,
     202,   204,   206,   211,   215,   217,   219,   222,   225,   227,
     228,   232
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    35,    36,    -1,    36,    -1,
      45,    -1,    37,    -1,    38,    -1,    46,    30,    20,    41,
      21,    18,    -1,    46,    30,    20,    21,    18,    -1,    -1,
      46,    30,    20,    41,    21,    39,    42,    -1,    -1,    46,
      30,    20,    21,    40,    42,    -1,    41,    19,    46,    30,
      -1,    41,    19,    46,    -1,    46,    30,    -1,    46,    -1,
      -1,    22,    43,    48,    23,    -1,    -1,    22,    44,    23,
      -1,    46,    47,    18,    -1,     7,    -1,     8,    -1,    10,
      -1,    47,    19,    30,    -1,    47,    19,    30,    24,    28,
      25,    -1,    30,    -1,    30,    24,    28,    25,    -1,    50,
      -1,    48,    50,    -1,    45,    -1,    53,    -1,    42,    -1,
       5,    20,    53,    53,    55,    21,    49,    -1,     3,    20,
      52,    21,    49,    -1,     6,    20,    55,    21,    49,    -1,
      11,    20,    30,    21,    18,    -1,     9,    55,    18,    -1,
      49,    -1,    -1,     3,    20,    52,    21,    49,     4,    51,
      50,    -1,    55,    -1,    18,    -1,    55,    18,    -1,    30,
      -1,    30,    24,    55,    25,    -1,    56,    -1,    54,    14,
      56,    -1,    57,    -1,    57,    16,    57,    -1,    58,    -1,
      58,    15,    58,    -1,    59,    -1,    58,    12,    59,    -1,
      60,    -1,    59,    13,    60,    -1,    12,    60,    -1,    17,
      60,    -1,    61,    -1,    54,    -1,    30,    20,    62,    21,
      -1,    20,    55,    21,    -1,    28,    -1,    29,    -1,    54,
      26,    -1,    54,    27,    -1,    63,    -1,    -1,    63,    19,
      56,    -1,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    64,    70,    78,    84,    90,    98,   106,
     116,   115,   134,   133,   154,   168,   181,   191,   206,   205,
     228,   227,   251,   261,   267,   273,   281,   290,   299,   307,
     317,   323,   332,   338,   344,   350,   356,   368,   374,   380,
     388,   396,   394,   412,   420,   426,   436,   444,   459,   466,
     490,   497,   519,   526,   548,   555,   580,   587,   620,   633,
     646,   655,   665,   673,   680,   689,   696,   703,   712,   720,
     726,   734
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "FOR", "WHILE", "INT",
  "FLOAT", "RETURN", "VOID", "PRINTLN", "ADDOP", "MULOP", "ASSIGNOP",
  "RELOP", "LOGICOP", "NOT", "SEMICOLON", "COMMA", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "INCOP", "DECOP", "CONST_INT",
  "CONST_FLOAT", "ID", "STRING", "CONST_CHAR", "$accept", "start",
  "program", "unit", "func_declaration", "func_definition", "@1", "@2",
  "parameter_list", "compound_statement", "@3", "@4", "var_declaration",
  "type_specifier", "declaration_list", "statements", "simple_statement",
  "statement", "@5", "conditional_expression", "expression_statement",
  "variable", "expression", "logic_expression", "rel_expression",
  "simple_expression", "term", "unary_expression", "factor",
  "argument_list", "arguments", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    37,    37,
      39,    38,    40,    38,    41,    41,    41,    41,    43,    42,
      44,    42,    45,    46,    46,    46,    47,    47,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    49,    49,    49,
      50,    51,    50,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    60,    60,
      60,    61,    61,    61,    61,    61,    61,    61,    62,    62,
      63,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       0,     7,     0,     6,     4,     3,     2,     1,     0,     4,
       0,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     5,     5,     3,
       1,     0,     8,     1,     1,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     2,     2,     1,     0,
       3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,     0,     0,    22,     0,    12,
       0,    17,     0,    26,     9,     0,     0,    10,    16,    29,
       0,    18,    13,    15,     8,     0,     0,     0,     0,    14,
      11,    27,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    64,    65,    46,    34,    32,     0,     0,    40,    30,
      33,    61,     0,    48,    50,    52,    54,    56,    60,    21,
       0,     0,     0,     0,     0,    61,    58,    59,     0,    69,
       0,    28,    19,    31,     0,    66,    67,    45,     0,     0,
       0,     0,     0,    43,     0,     0,    39,     0,    63,    71,
       0,    68,     0,    49,    51,    55,    53,    57,     0,     0,
       0,     0,    62,     0,    47,     0,    36,     0,    37,    38,
      70,     0,    41,     0,     0,     0,    35,     0,    42,    36
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    35,    25,    20,    54,
      37,    38,    55,    56,    14,    57,    58,    59,   125,    92,
      60,    61,    62,    63,    64,    65,    66,    67,    68,   100,
     101
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
      78,   -70,   -70,   -70,     4,    78,   -70,   -70,   -70,   -70,
       0,   -70,   -70,    22,    55,    47,    17,   -70,     2,    41,
      -8,    35,    42,    63,   -70,    49,    78,    73,   -70,   -70,
      65,    74,   -70,    68,   -70,    49,    88,    72,    92,   -70,
     -70,   -70,    96,   101,   103,   107,   113,   107,   107,   -70,
     107,   -70,   -70,    38,   -70,   -70,   108,    11,   -70,   -70,
     -70,    10,   121,   -70,   124,    48,   128,   -70,   -70,   -70,
     107,   114,   107,   127,   116,    69,   -70,   -70,   126,   107,
     107,   125,   -70,   -70,   107,   -70,   -70,   -70,   107,   107,
     107,   107,   129,   -70,   114,   130,   -70,   131,   -70,   -70,
     132,   135,   123,   -70,   -70,   128,   143,   -70,   100,   107,
     100,   138,   -70,   107,   -70,   137,   154,   139,   -70,   -70,
     -70,   107,   -70,   100,   140,    72,   -70,   100,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -70,   -70,   -70,   157,   -70,   -70,   -70,   -70,   -70,   -23,
     -70,   -70,    56,    99,   -70,   -70,   -57,   -56,   -70,    43,
     -68,   -41,   -45,   -69,    71,    75,    77,   -39,   -70,   -70,
     -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      73,    83,    32,    94,    11,    78,    75,    75,    76,    77,
      99,    26,    40,    27,    42,   103,    43,    44,     1,     2,
      45,     3,    46,    47,    84,    93,   109,    95,    48,    49,
      13,    50,    23,    31,    82,   102,    85,    86,    75,    51,
      52,    53,    15,    75,   120,    22,    16,    75,    75,    75,
      75,   116,   107,   118,     1,     2,     9,     3,    79,    24,
      89,     9,    80,    90,   117,    28,   126,    29,    19,   128,
     129,    31,    75,    17,    18,    42,    93,    43,    44,     1,
       2,    45,     3,    46,    47,     1,     2,    30,     3,    48,
      49,    34,    50,    36,    31,    85,    86,   -20,    39,    10,
      51,    52,    53,   115,    10,    43,    44,     1,     2,    45,
       3,    46,    47,    41,    21,    69,    70,    48,    49,    47,
      50,    71,    31,    72,    48,    33,    47,    50,    51,    52,
      53,    48,    49,    74,    50,    51,    52,    53,    81,    87,
      88,    91,    51,    52,    53,    96,    97,    98,   114,    16,
     108,   110,   111,   112,   113,    89,   119,   121,   122,   104,
     123,   127,    12,     0,   124,   106,   105
};

static const yytype_int8 yycheck[] =
{
      45,    57,    25,    71,     0,    50,    47,    48,    47,    48,
      79,    19,    35,    21,     3,    84,     5,     6,     7,     8,
       9,    10,    11,    12,    14,    70,    94,    72,    17,    18,
      30,    20,    30,    22,    23,    80,    26,    27,    79,    28,
      29,    30,    20,    84,   113,    28,    24,    88,    89,    90,
      91,   108,    91,   110,     7,     8,     0,    10,    20,    18,
      12,     5,    24,    15,   109,    30,   123,    25,    21,   125,
     127,    22,   113,    18,    19,     3,   121,     5,     6,     7,
       8,     9,    10,    11,    12,     7,     8,    24,    10,    17,
      18,    18,    20,    28,    22,    26,    27,    23,    30,     0,
      28,    29,    30,     3,     5,     5,     6,     7,     8,     9,
      10,    11,    12,    25,    15,    23,    20,    17,    18,    12,
      20,    20,    22,    20,    17,    26,    12,    20,    28,    29,
      30,    17,    18,    20,    20,    28,    29,    30,    30,    18,
      16,    13,    28,    29,    30,    18,    30,    21,    25,    24,
      21,    21,    21,    21,    19,    12,    18,    20,     4,    88,
      21,    21,     5,    -1,   121,    90,    89
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    10,    34,    35,    36,    37,    38,    45,
      46,     0,    36,    30,    47,    20,    24,    18,    19,    21,
      41,    46,    28,    30,    18,    40,    19,    21,    30,    25,
      24,    22,    42,    46,    18,    39,    28,    43,    44,    30,
      42,    25,     3,     5,     6,     9,    11,    12,    17,    18,
      20,    28,    29,    30,    42,    45,    46,    48,    49,    50,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    23,
      20,    20,    20,    55,    20,    54,    60,    60,    55,    20,
      24,    30,    23,    50,    14,    26,    27,    18,    16,    12,
      15,    13,    52,    55,    53,    55,    18,    30,    21,    56,
      62,    63,    55,    56,    57,    59,    58,    60,    21,    53,
      21,    21,    21,    19,    25,     3,    49,    55,    49,    18,
      56,    20,     4,    21,    52,    51,    49,    21,    50,    49
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 57 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("start : program", (yyval.symbolInfo)->name);
	}
    break;

  case 3:
#line 65 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (2)].symbolInfo)->name+" "+(yyvsp[(2) - (2)].symbolInfo)->name;
		rule_matched("program : program unit", (yyval.symbolInfo)->name);
	}
    break;

  case 4:
#line 71 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("program : unit", (yyval.symbolInfo)->name);
	}
    break;

  case 5:
#line 79 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("unit : var_declaration", (yyval.symbolInfo)->name);
	}
    break;

  case 6:
#line 85 "1805016.y"
    {
     		(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("unit : func_declaration", (yyval.symbolInfo)->name);
     }
    break;

  case 7:
#line 91 "1805016.y"
    {
     		(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("unit : func_definition", (yyval.symbolInfo)->name);
     }
    break;

  case 8:
#line 99 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (6)].symbolInfo)->name+" "+(yyvsp[(2) - (6)].symbolInfo)->name+" "+(yyvsp[(3) - (6)].symbolInfo)->name+" "+(yyvsp[(4) - (6)].symbolInfo)->name+" "+(yyvsp[(5) - (6)].symbolInfo)->name+" "+(yyvsp[(6) - (6)].symbolInfo)->name;
			process_function_declaration((yyvsp[(2) - (6)].symbolInfo)->name, (yyvsp[(1) - (6)].symbolInfo)->name, (yyvsp[(4) - (6)].symbolInfo)->param, (yyvsp[(4) - (6)].symbolInfo)->pids);
			rule_matched("func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON", (yyval.symbolInfo)->name);
			
		}
    break;

  case 9:
#line 107 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (5)].symbolInfo)->name+" "+(yyvsp[(2) - (5)].symbolInfo)->name+" "+(yyvsp[(3) - (5)].symbolInfo)->name+" "+(yyvsp[(4) - (5)].symbolInfo)->name+" "+(yyvsp[(5) - (5)].symbolInfo)->name;
			process_function_declaration((yyvsp[(2) - (5)].symbolInfo)->name, (yyvsp[(1) - (5)].symbolInfo)->name, vector<string>(), vector<string>());
			rule_matched("func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON", (yyval.symbolInfo)->name);
		}
    break;

  case 10:
#line 116 "1805016.y"
    {
			//cout<<"faker\n";
			process_function_definition((yyvsp[(2) - (5)].symbolInfo)->name, (yyvsp[(1) - (5)].symbolInfo)->name, (yyvsp[(4) - (5)].symbolInfo)->param, (yyvsp[(4) - (5)].symbolInfo)->pids);
			generate_declaration((yyvsp[(4) - (5)].symbolInfo)->pids);

			code_seg+=(yyvsp[(2) - (5)].symbolInfo)->name+" PROC\n";
			if((yyvsp[(2) - (5)].symbolInfo)->name=="main") code_seg+="MOV AX, @DATA\nMOV DS, AX\n";
		}
    break;

  case 11:
#line 125 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (7)].symbolInfo)->name+" "+(yyvsp[(2) - (7)].symbolInfo)->name+" "+(yyvsp[(3) - (7)].symbolInfo)->name+" "+(yyvsp[(4) - (7)].symbolInfo)->name+" "+(yyvsp[(5) - (7)].symbolInfo)->name+" "+(yyvsp[(7) - (7)].symbolInfo)->name;
			rule_matched("func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement", (yyval.symbolInfo)->name);
			
			code_seg+=(yyvsp[(2) - (7)].symbolInfo)->name+" ENDP\n";
			if((yyvsp[(2) - (7)].symbolInfo)->name=="main") code_seg+="END MAIN\n";
		}
    break;

  case 12:
#line 134 "1805016.y"
    {
			//cout<<"faker\n";
			process_function_definition((yyvsp[(2) - (4)].symbolInfo)->name, (yyvsp[(1) - (4)].symbolInfo)->name, vector<string>(), vector<string>());
		
			code_seg+=(yyvsp[(2) - (4)].symbolInfo)->name+" PROC\n";
			if((yyvsp[(2) - (4)].symbolInfo)->name=="main") code_seg+="MOV AX, @DATA\nMOV DS, AX\n";
		}
    break;

  case 13:
#line 142 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (6)].symbolInfo)->name+" "+(yyvsp[(2) - (6)].symbolInfo)->name+" "+(yyvsp[(3) - (6)].symbolInfo)->name+" "+(yyvsp[(4) - (6)].symbolInfo)->name+" "+(yyvsp[(6) - (6)].symbolInfo)->name;
			rule_matched("func_definition : type_specifier ID LPAREN RPAREN compound_statement", (yyval.symbolInfo)->name);
			
			code_seg+=(yyvsp[(2) - (6)].symbolInfo)->name+" ENDP\n";
			if((yyvsp[(2) - (6)].symbolInfo)->name=="main") code_seg+="END MAIN\n";
		}
    break;

  case 14:
#line 155 "1805016.y"
    {
			
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (4)].symbolInfo)->name+" "+(yyvsp[(2) - (4)].symbolInfo)->name+" "+(yyvsp[(3) - (4)].symbolInfo)->name+" "+(yyvsp[(4) - (4)].symbolInfo)->name;
			//process_parameter_list($1->param, $3->name, $4->name, $$);

			(yyval.symbolInfo)->param=(yyvsp[(1) - (4)].symbolInfo)->param;
			(yyval.symbolInfo)->param.push_back("CONST_"+to_upper((yyvsp[(3) - (4)].symbolInfo)->name));
			(yyval.symbolInfo)->pids=(yyvsp[(1) - (4)].symbolInfo)->pids;
			(yyval.symbolInfo)->pids.push_back((yyvsp[(4) - (4)].symbolInfo)->name);
			
			rule_matched("parameter_list  : parameter_list COMMA type_specifier ID", (yyval.symbolInfo)->name);
		}
    break;

  case 15:
#line 169 "1805016.y"
    {
			
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;

			(yyval.symbolInfo)->param=(yyvsp[(1) - (3)].symbolInfo)->param;
			(yyval.symbolInfo)->param.push_back("CONST_"+to_upper((yyvsp[(3) - (3)].symbolInfo)->name));
			(yyval.symbolInfo)->pids=(yyvsp[(1) - (3)].symbolInfo)->pids;
			(yyval.symbolInfo)->pids.push_back("");
			
			rule_matched("parameter_list  : parameter_list COMMA type_specifier", (yyval.symbolInfo)->name);
		}
    break;

  case 16:
#line 182 "1805016.y"
    {
 			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (2)].symbolInfo)->name+" "+(yyvsp[(2) - (2)].symbolInfo)->name;

			(yyval.symbolInfo)->param.push_back("CONST_"+to_upper((yyvsp[(1) - (2)].symbolInfo)->name));
			(yyval.symbolInfo)->pids.push_back((yyvsp[(2) - (2)].symbolInfo)->name);

			rule_matched("parameter_list  : type_specifier ID", (yyval.symbolInfo)->name);
 		}
    break;

  case 17:
#line 192 "1805016.y"
    {
			
 			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;

			(yyval.symbolInfo)->param.push_back("CONST_"+to_upper((yyvsp[(1) - (1)].symbolInfo)->name));
			(yyval.symbolInfo)->pids.push_back("");

			rule_matched("parameter_list  : type_specifier", (yyval.symbolInfo)->name);
 		}
    break;

  case 18:
#line 206 "1805016.y"
    {
				//cout<<"ayo1\n";
				if(!in){
					st.enter();
					//cout<<"entered\n";
				}
				else in=false;
				//cout<<"ayo2\n";
			}
    break;

  case 19:
#line 216 "1805016.y"
    {
				//cout<<"compound_statement\n";
				

				(yyval.symbolInfo)=new SymbolInfo();
				(yyval.symbolInfo)->name=(yyvsp[(1) - (4)].symbolInfo)->name+" "+(yyvsp[(3) - (4)].symbolInfo)->name+" "+(yyvsp[(4) - (4)].symbolInfo)->name;
				rule_matched("compound_statement : LCURL statements RCURL", (yyval.symbolInfo)->name);
				st.printAll();
				st.exit();
				//cout<<"exited\n";
		    }
    break;

  case 20:
#line 228 "1805016.y"
    {
				//cout<<"ayo\n";
				if(!in){
					st.enter();
					//cout<<"entered\n";
				}
				else in=false;
			}
    break;

  case 21:
#line 237 "1805016.y"
    {
				//cout<<"compound_statement\n";
				
				(yyval.symbolInfo)=new SymbolInfo();
				(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;
				rule_matched("compound_statement : LCURL RCURL", (yyval.symbolInfo)->name);	

				st.printAll();
				st.exit();
				cout<<"exited\n";
 		    }
    break;

  case 22:
#line 252 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;
			process_var_declaration((yyvsp[(1) - (3)].symbolInfo)->name, (yyvsp[(2) - (3)].symbolInfo)->param);
			//generate_declaration($2->param);
			rule_matched("var_declaration : type_specifier declaration_list SEMICOLON", (yyval.symbolInfo)->name);	
		}
    break;

  case 23:
#line 262 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			rule_matched("type_specifier	: INT", (yyval.symbolInfo)->name);
		}
    break;

  case 24:
#line 268 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			rule_matched("type_specifier	: FLOAT", (yyval.symbolInfo)->name);
		}
    break;

  case 25:
#line 274 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			rule_matched("type_specifier	: VOID", (yyval.symbolInfo)->name);
		}
    break;

  case 26:
#line 282 "1805016.y"
    {
		  	(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;
			process_declaration_list((yyvsp[(1) - (3)].symbolInfo)->param, (yyvsp[(3) - (3)].symbolInfo)->name, "VAR", (yyval.symbolInfo));
			rule_matched("declaration_list : declaration_list COMMA ID", (yyval.symbolInfo)->name);
		  
		  	generate_declaration((yyvsp[(3) - (3)].symbolInfo)->name);
		  }
    break;

  case 27:
#line 291 "1805016.y"
    {
 		  	(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (6)].symbolInfo)->name+" "+(yyvsp[(2) - (6)].symbolInfo)->name+" "+(yyvsp[(3) - (6)].symbolInfo)->name+" "+(yyvsp[(4) - (6)].symbolInfo)->name+" "+(yyvsp[(5) - (6)].symbolInfo)->name+" "+(yyvsp[(6) - (6)].symbolInfo)->name;
			process_declaration_list((yyvsp[(1) - (6)].symbolInfo)->param, (yyvsp[(3) - (6)].symbolInfo)->name, "VAR_ARRAY", (yyval.symbolInfo));
			rule_matched("declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD", (yyval.symbolInfo)->name);
 		  
		  	generate_declaration((yyvsp[(3) - (6)].symbolInfo)->name, (yyvsp[(5) - (6)].symbolInfo)->name);
		  }
    break;

  case 28:
#line 300 "1805016.y"
    {
 		  	(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			process_declaration_list(vector<string>(), (yyvsp[(1) - (1)].symbolInfo)->name, "VAR", (yyval.symbolInfo));
			generate_declaration((yyvsp[(1) - (1)].symbolInfo)->name);
			rule_matched("declaration_list : ID", (yyval.symbolInfo)->name);
 		  }
    break;

  case 29:
#line 308 "1805016.y"
    {
 		  	(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (4)].symbolInfo)->name+" "+(yyvsp[(2) - (4)].symbolInfo)->name+" "+(yyvsp[(3) - (4)].symbolInfo)->name+" "+(yyvsp[(4) - (4)].symbolInfo)->name;
			process_declaration_list(vector<string>(), (yyvsp[(1) - (4)].symbolInfo)->name, "VAR_ARRAY", (yyval.symbolInfo));
			generate_declaration((yyvsp[(1) - (4)].symbolInfo)->name, (yyvsp[(3) - (4)].symbolInfo)->name);
			rule_matched("declaration_list : ID LTHIRD CONST_INT RTHIRD", (yyval.symbolInfo)->name);
 		  }
    break;

  case 30:
#line 318 "1805016.y"
    {
	   	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("statements : statement", (yyval.symbolInfo)->name);
	   }
    break;

  case 31:
#line 324 "1805016.y"
    {
	   	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (2)].symbolInfo)->name+" "+(yyvsp[(2) - (2)].symbolInfo)->name;
		rule_matched("statements : statements statement", (yyval.symbolInfo)->name);
	   }
    break;

  case 32:
#line 333 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("simple_statement : var_declaration", (yyval.symbolInfo)->name);
	  }
    break;

  case 33:
#line 339 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("simple_statement : expression_statement", (yyval.symbolInfo)->name);
	  }
    break;

  case 34:
#line 345 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("simple_statement : compound_statement", (yyval.symbolInfo)->name);
	  }
    break;

  case 35:
#line 351 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (7)].symbolInfo)->name+" "+(yyvsp[(2) - (7)].symbolInfo)->name+" "+(yyvsp[(3) - (7)].symbolInfo)->name+" "+(yyvsp[(4) - (7)].symbolInfo)->name+" "+(yyvsp[(5) - (7)].symbolInfo)->name+" "+(yyvsp[(6) - (7)].symbolInfo)->name+" "+(yyvsp[(7) - (7)].symbolInfo)->name;
	  	rule_matched("simple_statement : FOR LPAREN expression_statement expression_statement expression RPAREN simple_statement", (yyval.symbolInfo)->name);
	  }
    break;

  case 36:
#line 357 "1805016.y"
    {
		string false_label=iflabel.top(); iflabel.pop();
		string exit_label=iflabel.top(); iflabel.pop();
		code_seg+=jump(exit_label);
		code_seg+=false_label+":\n";
		code_seg+=exit_label+":\n\n";

	  	(yyval.symbolInfo)=new SymbolInfo();
		//$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$6->name;
	  	rule_matched("simple_statement : IF LPAREN expression RPAREN simple_statement", (yyval.symbolInfo)->name);
	  }
    break;

  case 37:
#line 369 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (5)].symbolInfo)->name+" "+(yyvsp[(2) - (5)].symbolInfo)->name+" "+(yyvsp[(3) - (5)].symbolInfo)->name+" "+(yyvsp[(4) - (5)].symbolInfo)->name+" "+(yyvsp[(5) - (5)].symbolInfo)->name;
	  	rule_matched("simple_statement : WHILE LPAREN expression RPAREN simple_statement", (yyval.symbolInfo)->name);
	  }
    break;

  case 38:
#line 375 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (5)].symbolInfo)->name+" "+(yyvsp[(2) - (5)].symbolInfo)->name+" "+(yyvsp[(3) - (5)].symbolInfo)->name+" "+(yyvsp[(4) - (5)].symbolInfo)->name+" "+(yyvsp[(5) - (5)].symbolInfo)->name;
	  	rule_matched("simple_statement : PRINTLN LPAREN ID RPAREN SEMICOLON", (yyval.symbolInfo)->name);
	  }
    break;

  case 39:
#line 381 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;
	  	rule_matched("simple_statement : RETURN expression SEMICOLON", (yyval.symbolInfo)->name);
	  }
    break;

  case 40:
#line 389 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		rule_matched("statement: simple_statement", (yyval.symbolInfo)->name);
	  }
    break;

  case 41:
#line 396 "1805016.y"
    {
		string false_label=iflabel.top(); iflabel.pop();
		string exit_label=iflabel.top();
		code_seg+=jump(exit_label);
		code_seg+=false_label+":\n";
	  }
    break;

  case 42:
#line 403 "1805016.y"
    {
	  	(yyval.symbolInfo)=new SymbolInfo();
		//$$->name=$1->name+" "+$2->name+" "+$3->name+" "+$4->name+" "+$6->name+" "+$7->name+" "+$8->name;
	  	rule_matched("statement : IF LPAREN expression RPAREN simple_statement ELSE statement", (yyval.symbolInfo)->name);
	  	
		string exit_label=iflabel.top(); iflabel.pop();
		code_seg+=exit_label+":\n\n";
	  }
    break;

  case 43:
#line 413 "1805016.y"
    {
				string exit_label=new_label();
				string false_label=new_label();
				iflabel.push(exit_label);
				iflabel.push(false_label);
				code_seg+=jump_if_false(false_label);
	  		}
    break;

  case 44:
#line 421 "1805016.y"
    {
				(yyval.symbolInfo)=new SymbolInfo();
				(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
				rule_matched("expression_statement : SEMICOLON", (yyval.symbolInfo)->name);
			}
    break;

  case 45:
#line 427 "1805016.y"
    {
				(yyval.symbolInfo)=new SymbolInfo();
				(yyval.symbolInfo)->name=(yyvsp[(1) - (2)].symbolInfo)->name+" "+(yyvsp[(2) - (2)].symbolInfo)->name;
	  			rule_matched("expression_statement : expression SEMICOLON ", (yyval.symbolInfo)->name);

				code_seg+=unary_pop();
			}
    break;

  case 46:
#line 437 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			(yyval.symbolInfo)->ret=process_variable((yyvsp[(1) - (1)].symbolInfo)->name,"VAR");
			(yyval.symbolInfo)->type="VAR";
			rule_matched("variable : ID", (yyval.symbolInfo)->name);
		}
    break;

  case 47:
#line 445 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (4)].symbolInfo)->name+" "+(yyvsp[(2) - (4)].symbolInfo)->name+" "+(yyvsp[(3) - (4)].symbolInfo)->name+" "+(yyvsp[(4) - (4)].symbolInfo)->name;
			(yyval.symbolInfo)->ret=process_variable((yyvsp[(1) - (4)].symbolInfo)->name,"VAR_ARRAY");
			(yyval.symbolInfo)->type="VAR_ARRAY";
			if((yyvsp[(3) - (4)].symbolInfo)->ret!="CONST_INT" and (yyvsp[(3) - (4)].symbolInfo)->ret!="DUMMY"){
				error("non_const_integer used as array subscript in variable: "+(yyvsp[(1) - (4)].symbolInfo)->name);
			}
	  		rule_matched("variable : ID LTHIRD expression RTHIRD", (yyval.symbolInfo)->name);

			
		}
    break;

  case 48:
#line 460 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			(yyval.symbolInfo)->ret=(yyvsp[(1) - (1)].symbolInfo)->ret;
			rule_matched("expression : logic_expression", (yyval.symbolInfo)->name);
		}
    break;

  case 49:
#line 467 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;

			if((yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if((yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_INT" and (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_FLOAT"){
				error("float type expression assigned to integer type variable: "+(yyvsp[(1) - (3)].symbolInfo)->name);
				(yyval.symbolInfo)->ret="CONST_INT";
			}
			if((yyvsp[(1) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(3) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				(yyval.symbolInfo)->ret="DUMMY";
			}
			else (yyval.symbolInfo)->ret=(yyvsp[(1) - (3)].symbolInfo)->ret;

	  		rule_matched("expression : variable ASSIGNOP logic_expression", (yyval.symbolInfo)->name);
		
			code_seg+=assignop((yyvsp[(1) - (3)].symbolInfo)->name, (yyvsp[(1) - (3)].symbolInfo)->type);
		}
    break;

  case 50:
#line 491 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			(yyval.symbolInfo)->ret=(yyvsp[(1) - (1)].symbolInfo)->ret;
			rule_matched("logic_expression : rel_expression", (yyval.symbolInfo)->name);
		}
    break;

  case 51:
#line 498 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;

			if((yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if((yyvsp[(1) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(3) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				(yyval.symbolInfo)->ret="DUMMY";
			}
			else {
				(yyval.symbolInfo)->ret="CONST_INT";
			}

	  		rule_matched("logic_expression : rel_expression LOGICOP rel_expression", (yyval.symbolInfo)->name);
		
			code_seg+=binary_logicop((yyvsp[(2) - (3)].symbolInfo)->name);
		}
    break;

  case 52:
#line 520 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			(yyval.symbolInfo)->ret=(yyvsp[(1) - (1)].symbolInfo)->ret;
			rule_matched("rel_expression : simple_expression", (yyval.symbolInfo)->name);
		}
    break;

  case 53:
#line 527 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;
			
			if((yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if((yyvsp[(1) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(3) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				(yyval.symbolInfo)->ret="DUMMY";
			}
			else {
				(yyval.symbolInfo)->ret="CONST_INT";
			}

	  		rule_matched("rel_expression : simple_expression RELOP simple_expression", (yyval.symbolInfo)->name);
		
			code_seg+=relop((yyvsp[(2) - (3)].symbolInfo)->name);
		}
    break;

  case 54:
#line 549 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			(yyval.symbolInfo)->ret=(yyvsp[(1) - (1)].symbolInfo)->ret;
			rule_matched("simple_expression : term", (yyval.symbolInfo)->name);
		}
    break;

  case 55:
#line 556 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;

			if((yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if((yyvsp[(1) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(3) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				(yyval.symbolInfo)->ret="DUMMY";
			}
			else if((yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_FLOAT" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_FLOAT"){
				(yyval.symbolInfo)->ret="CONST_FLOAT";
			}
			else {
				(yyval.symbolInfo)->ret="CONST_INT";
			}

	  		rule_matched("simple_expression : simple_expression ADDOP term", (yyval.symbolInfo)->name);
		
			code_seg+=binary_addop((yyvsp[(2) - (3)].symbolInfo)->name);
		}
    break;

  case 56:
#line 581 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			(yyval.symbolInfo)->ret=(yyvsp[(1) - (1)].symbolInfo)->ret;
			rule_matched("term : unary_expression", (yyval.symbolInfo)->name);
		}
    break;

  case 57:
#line 588 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;

			if((yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				error("Void function used in expression");
			}

			if((yyvsp[(2) - (3)].symbolInfo)->name=="%"){
				if((yyvsp[(3) - (3)].symbolInfo)->name=="0"){
					error("0 used as an operand for modulus operator");
				}
				if((yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_FLOAT" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_FLOAT"){
					error("float type expression used as an operand for modulus operator");
				}
			}

			else if((yyvsp[(1) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(3) - (3)].symbolInfo)->ret=="DUMMY" or (yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_VOID" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_VOID"){
				(yyval.symbolInfo)->ret="DUMMY";
			}
			else if((yyvsp[(1) - (3)].symbolInfo)->ret=="CONST_FLOAT" or (yyvsp[(3) - (3)].symbolInfo)->ret=="CONST_FLOAT"){
				(yyval.symbolInfo)->ret="CONST_FLOAT";
			}
			else {
				(yyval.symbolInfo)->ret="CONST_INT";
			}
	  		rule_matched("term : term MULOP unary_expression", (yyval.symbolInfo)->name);

			code_seg+=binary_mulop((yyvsp[(2) - (3)].symbolInfo)->name);
		}
    break;

  case 58:
#line 621 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (2)].symbolInfo)->name+" "+(yyvsp[(2) - (2)].symbolInfo)->name;
			if((yyvsp[(2) - (2)].symbolInfo)->ret=="CONST_VOID"){
				(yyval.symbolInfo)->ret="DUMMY";
				error("Void function used in expression");
			}
			else (yyval.symbolInfo)->ret=(yyvsp[(2) - (2)].symbolInfo)->ret;
	  		rule_matched("unary_expression : ADDOP unary_expression", (yyval.symbolInfo)->name);

			code_seg+=unary_addop((yyvsp[(1) - (2)].symbolInfo)->name);
		}
    break;

  case 59:
#line 634 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (2)].symbolInfo)->name+" "+(yyvsp[(2) - (2)].symbolInfo)->name;
			if((yyvsp[(2) - (2)].symbolInfo)->ret=="CONST_VOID"){
				(yyval.symbolInfo)->ret="DUMMY";
				error("Void function used in expression");
			}
			else (yyval.symbolInfo)->ret="CONST_INT";
	  		rule_matched("unary_expression : NOT unary_expression", (yyval.symbolInfo)->name);

			code_seg+=unary_logicop((yyvsp[(1) - (2)].symbolInfo)->name);
		}
    break;

  case 60:
#line 647 "1805016.y"
    {
			(yyval.symbolInfo)=new SymbolInfo();
			(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
			(yyval.symbolInfo)->ret=(yyvsp[(1) - (1)].symbolInfo)->ret;
			rule_matched("unary_expression : factor", (yyval.symbolInfo)->name);
		}
    break;

  case 61:
#line 656 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		(yyval.symbolInfo)->ret=(yyvsp[(1) - (1)].symbolInfo)->ret;
		rule_matched("factor : variable", (yyval.symbolInfo)->name);

		if((yyvsp[(1) - (1)].symbolInfo)->type=="VAR") code_seg+=push_var((yyvsp[(1) - (1)].symbolInfo)->name);
		else if((yyvsp[(1) - (1)].symbolInfo)->type=="VAR_ARRAY") code_seg+=push_varray((yyvsp[(1) - (1)].symbolInfo)->name);
	}
    break;

  case 62:
#line 666 "1805016.y"
    {
		//cout<<"ID LPAREN argument_list RPAREN\n";
		(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (4)].symbolInfo)->name+" "+(yyvsp[(2) - (4)].symbolInfo)->name+" "+(yyvsp[(3) - (4)].symbolInfo)->name+" "+(yyvsp[(4) - (4)].symbolInfo)->name;
		(yyval.symbolInfo)->ret=process_function_call((yyvsp[(1) - (4)].symbolInfo)->name, (yyvsp[(3) - (4)].symbolInfo)->param);
	  	rule_matched("factor : ID LPAREN argument_list RPAREN", (yyval.symbolInfo)->name);
	}
    break;

  case 63:
#line 674 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;
		(yyval.symbolInfo)->ret=(yyvsp[(2) - (3)].symbolInfo)->ret;
	  	rule_matched("factor : LPAREN expression RPAREN", (yyval.symbolInfo)->name);
	}
    break;

  case 64:
#line 681 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		(yyval.symbolInfo)->ret="CONST_INT";
		rule_matched("factor : CONST_INT", (yyval.symbolInfo)->name);

		code_seg+=push_literal((yyvsp[(1) - (1)].symbolInfo)->name);
	}
    break;

  case 65:
#line 690 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
		(yyval.symbolInfo)->ret="CONST_FLOAT";
		rule_matched("factor : CONST_FLOAT", (yyval.symbolInfo)->name);
	}
    break;

  case 66:
#line 697 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (2)].symbolInfo)->name+" "+(yyvsp[(2) - (2)].symbolInfo)->name;
		(yyval.symbolInfo)->ret=(yyvsp[(1) - (2)].symbolInfo)->ret;
	  	rule_matched("factor : variable INCOP", (yyval.symbolInfo)->name);
	}
    break;

  case 67:
#line 704 "1805016.y"
    {
		(yyval.symbolInfo)=new SymbolInfo();
		(yyval.symbolInfo)->name=(yyvsp[(1) - (2)].symbolInfo)->name+" "+(yyvsp[(2) - (2)].symbolInfo)->name;
		(yyval.symbolInfo)->ret=(yyvsp[(1) - (2)].symbolInfo)->ret;
	  	rule_matched("factor : variable DECOP", (yyval.symbolInfo)->name);
	}
    break;

  case 68:
#line 713 "1805016.y"
    {
				(yyval.symbolInfo)=new SymbolInfo();
				(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
				(yyval.symbolInfo)->param=(yyvsp[(1) - (1)].symbolInfo)->param;
				rule_matched("argument_list : arguments", (yyval.symbolInfo)->name);
			}
    break;

  case 69:
#line 720 "1805016.y"
    {
				(yyval.symbolInfo)=new SymbolInfo();
				rule_matched("argument_list : ", (yyval.symbolInfo)->name);
			}
    break;

  case 70:
#line 727 "1805016.y"
    {
				(yyval.symbolInfo)=new SymbolInfo();
				(yyval.symbolInfo)->name=(yyvsp[(1) - (3)].symbolInfo)->name+" "+(yyvsp[(2) - (3)].symbolInfo)->name+" "+(yyvsp[(3) - (3)].symbolInfo)->name;
				(yyval.symbolInfo)->param=(yyvsp[(1) - (3)].symbolInfo)->param;
				(yyval.symbolInfo)->param.push_back((yyvsp[(3) - (3)].symbolInfo)->ret);
	  			rule_matched("arguments : arguments COMMA logic_expression", (yyval.symbolInfo)->name);
			}
    break;

  case 71:
#line 735 "1805016.y"
    {
				(yyval.symbolInfo)=new SymbolInfo();
				(yyval.symbolInfo)->name=(yyvsp[(1) - (1)].symbolInfo)->name;
				(yyval.symbolInfo)->param.push_back((yyvsp[(1) - (1)].symbolInfo)->ret);
				rule_matched("arguments : logic_expression", (yyval.symbolInfo)->name);
			}
    break;


/* Line 1267 of yacc.c.  */
#line 2384 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 744 "1805016.y"

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


