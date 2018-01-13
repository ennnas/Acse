/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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
     LBRACE = 258,
     RBRACE = 259,
     LPAR = 260,
     RPAR = 261,
     LSQUARE = 262,
     RSQUARE = 263,
     SEMI = 264,
     COLON = 265,
     PLUS = 266,
     MINUS = 267,
     MUL_OP = 268,
     DIV_OP = 269,
     MOD_OP = 270,
     AND_OP = 271,
     OR_OP = 272,
     NOT_OP = 273,
     ASSIGN = 274,
     LT = 275,
     GT = 276,
     SHL_OP = 277,
     SHR_OP = 278,
     EQ = 279,
     NOTEQ = 280,
     LTEQ = 281,
     GTEQ = 282,
     ANDAND = 283,
     OROR = 284,
     COMMA = 285,
     RETURN = 286,
     READ = 287,
     WRITE = 288,
     CASE = 289,
     DEFAULT = 290,
     BREAK = 291,
     QMARK = 292,
     HAT = 293,
     SUM = 294,
     WEIGHTED = 295,
     BY = 296,
     DO = 297,
     WHILE = 298,
     IF = 299,
     ELSE = 300,
     TYPE = 301,
     IDENTIFIER = 302,
     NUMBER = 303,
     EVAL = 304,
     UNLESS = 305,
     FOREACH = 306,
     FOR = 307,
     SWITCH = 308,
     DOLLAR = 309,
     AT = 310,
     NOT = 311
   };
#endif
/* Tokens.  */
#define LBRACE 258
#define RBRACE 259
#define LPAR 260
#define RPAR 261
#define LSQUARE 262
#define RSQUARE 263
#define SEMI 264
#define COLON 265
#define PLUS 266
#define MINUS 267
#define MUL_OP 268
#define DIV_OP 269
#define MOD_OP 270
#define AND_OP 271
#define OR_OP 272
#define NOT_OP 273
#define ASSIGN 274
#define LT 275
#define GT 276
#define SHL_OP 277
#define SHR_OP 278
#define EQ 279
#define NOTEQ 280
#define LTEQ 281
#define GTEQ 282
#define ANDAND 283
#define OROR 284
#define COMMA 285
#define RETURN 286
#define READ 287
#define WRITE 288
#define CASE 289
#define DEFAULT 290
#define BREAK 291
#define QMARK 292
#define HAT 293
#define SUM 294
#define WEIGHTED 295
#define BY 296
#define DO 297
#define WHILE 298
#define IF 299
#define ELSE 300
#define TYPE 301
#define IDENTIFIER 302
#define NUMBER 303
#define EVAL 304
#define UNLESS 305
#define FOREACH 306
#define FOR 307
#define SWITCH 308
#define DOLLAR 309
#define AT 310
#define NOT 311




/* Copy the first part of user declarations.  */
#line 1 "Acse.y"

/*
 * Andrea Di Biagio
 * Politecnico di Milano, 2007
 * 
 * Acse.y
 * Formal Languages & Compilers Machine, 2007/2008
 * 
 */

/*************************************************************************

                   Compiler for the language LANCE

***************************************************************************/

#include <stdio.h>       
#include <stdlib.h>
#include <assert.h>
#include <malloc/malloc.h>
#include "axe_struct.h"
#include "axe_engine.h"
#include "symbol_table.h"
#include "axe_errors.h"
#include "collections.h"
#include "axe_expressions.h"
#include "axe_gencode.h"
#include "axe_utils.h"
#include "axe_array.h"
#include "axe_cflow_graph.h"
#include "cflow_constants.h"
#include "axe_transform.h"
#include "axe_reg_alloc.h"
#include "reg_alloc_constants.h"
#include "axe_io_manager.h"
#ifndef NDEBUG
#  include "axe_debug.h"
#endif



/* global variables */
int line_num;        /* this variable will keep track of the
                      * source code line number. Every time that a newline
                      * is encountered while parsing the input file, this
                      * value is increased by 1. This value is then used
                      * for error tracking: if the parser returns an error
                      * or a warning, this value is used in order to notify
                      * in which line of code the error has been found */
int num_error;       /* the number of errors found in the code. This value
                      * is increased by 1 every time a new error is found
                      * in the code. */
int num_warning;     /* As for the `num_error' global variable, this one
                      * keeps track of all the warning messages displayed */

/* errorcode is defined inside "axe_engine.c" */
extern int errorcode;   /* this variable is used to test if an error is found
                         * while parsing the input file. It also is set
                         * to notify if the compiler internal state is invalid.
                         * When the parsing process is started, the value
                         * of `errorcode' is set to the value of the macro
                         * `AXE_OK' defined in "axe_constants.h".
                         * As long as everything (the parsed source code and
                         * the internal state of the compiler) is correct,
                         * the value of `errorcode' is set to `AXE_OK'.
                         * When an error occurs (because the input file contains
                         * one or more syntax errors or because something went
                         * wrong in the machine internal state), the errorcode
                         * is set to a value that is different from `AXE_OK'. */
                         

extern int cflow_errorcode;   /* As for `errorcode' this value is used to
                        * test if an error occurs during the creation process of
                        * a control flow graph. More informations can be found
                        * analyzing the file `axe_cflow_graph.h'. */
                     
/* program informations */
t_program_infos *program;  /* The singleton instance of `program'.
                            * An instance of `t_program_infos' holds in its
                            * internal structure, all the useful informations
                            * about a program. For example: the assembly
                            * (code and directives); the symbol table;
                            * the label manager (see axe_labels.h) etc. */
t_cflow_Graph *graph;      /* An instance of a control flow graph. This instance
                            * will be generated starting from `program' and will
                            * be used during the register allocation process */

t_reg_allocator *RA;       /* Register allocator. It implements the "Linear scan"
                            * algorythm */

t_io_infos *file_infos;    /* input and output files used by the compiler */

t_list *switchStack = NULL;



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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 103 "Acse.y"
typedef union YYSTYPE {            
   int intval;
   char *svalue;
   t_axe_expression expr;
   t_axe_declaration *decl;
   t_list *list;
   t_axe_label *label;
   t_while_statement while_stmt;
   t_unless_statement unless_stmt;
   t_foreach_statement foreach_stmt;
   t_for_statement for_stmt;
   t_switch_statement *switch_stmt;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 307 "Acse.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 319 "Acse.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   899

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  48
/* YYNRULES -- Number of rules. */
#define YYNRULES  104
/* YYNRULES -- Number of states. */
#define YYNSTATES  215

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    14,    18,    20,    24,
      29,    31,    33,    37,    40,    42,    45,    47,    50,    52,
      54,    56,    58,    61,    63,    65,    68,    70,    73,    75,
      77,    78,    82,    84,    91,    95,    97,    98,   103,   104,
     105,   113,   114,   115,   122,   123,   124,   132,   133,   141,
     142,   143,   153,   154,   155,   156,   157,   171,   172,   181,
     183,   186,   189,   191,   192,   198,   199,   204,   206,   208,
     213,   218,   220,   222,   227,   233,   236,   239,   243,   246,
     248,   252,   256,   260,   264,   268,   272,   276,   280,   284,
     288,   292,   296,   300,   304,   308,   312,   316,   319,   325,
     329,   337,   341,   349,   353
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      58,     0,    -1,    59,    64,    -1,    59,    60,    -1,    -1,
      46,    61,     9,    -1,    61,    30,    62,    -1,    62,    -1,
      47,    19,    48,    -1,    47,     7,    48,     8,    -1,    47,
      -1,    65,    -1,     3,    64,     4,    -1,    64,    65,    -1,
      65,    -1,    69,     9,    -1,    66,    -1,    67,     9,    -1,
       9,    -1,    70,    -1,    75,    -1,    78,    -1,    81,     9,
      -1,    83,    -1,    86,    -1,   100,     9,    -1,    91,    -1,
      99,     9,    -1,   101,    -1,   102,    -1,    -1,    68,    30,
      69,    -1,    69,    -1,    47,     7,   103,     8,    19,   103,
      -1,    47,    19,   103,    -1,    72,    -1,    -1,    72,    45,
      71,    63,    -1,    -1,    -1,    44,    73,     5,   103,     6,
      74,    63,    -1,    -1,    -1,    49,    76,    63,    77,    50,
     103,    -1,    -1,    -1,    43,    79,     5,   103,     6,    80,
      63,    -1,    -1,    42,    82,    63,    43,     5,   103,     6,
      -1,    -1,    -1,    51,    84,     5,    47,    10,    47,     6,
      85,    63,    -1,    -1,    -1,    -1,    -1,    52,    87,     5,
      68,     9,    88,   103,     9,    89,    68,     6,    90,    63,
      -1,    -1,    53,     5,    47,     6,     3,    92,    93,     4,
      -1,    94,    -1,    94,    97,    -1,    94,    95,    -1,    95,
      -1,    -1,    34,    48,    10,    96,    64,    -1,    -1,    35,
      10,    98,    64,    -1,    36,    -1,    31,    -1,    32,     5,
      47,     6,    -1,    33,     5,   103,     6,    -1,    48,    -1,
      47,    -1,    47,     7,   103,     8,    -1,   103,    44,   103,
      45,   103,    -1,    18,    48,    -1,   103,    18,    -1,    17,
     103,    17,    -1,    18,    47,    -1,    69,    -1,   103,    16,
     103,    -1,   103,    17,   103,    -1,   103,    11,   103,    -1,
     103,    12,   103,    -1,   103,    13,   103,    -1,   103,    14,
     103,    -1,   103,    20,   103,    -1,   103,    21,   103,    -1,
     103,    24,   103,    -1,   103,    25,   103,    -1,   103,    26,
     103,    -1,   103,    27,   103,    -1,   103,    22,   103,    -1,
     103,    23,   103,    -1,   103,    28,   103,    -1,   103,    29,
     103,    -1,     5,   103,     6,    -1,    12,   103,    -1,   103,
      54,   103,    55,   103,    -1,   103,    15,   103,    -1,     5,
     103,     6,    37,   103,    10,   103,    -1,   103,    38,   103,
      -1,    39,    40,    41,    47,     7,   104,     8,    -1,   104,
      30,   103,    -1,   103,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   186,   186,   199,   200,   203,   210,   214,   221,   230,
     239,   253,   254,   258,   259,   264,   265,   266,   267,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   281,   282,
     285,   286,   287,   289,   295,   312,   318,   317,   337,   343,
     336,   356,   364,   356,   381,   390,   380,   417,   416,   439,
     447,   438,   468,   469,   471,   479,   468,   490,   490,   529,
     532,   537,   537,   539,   539,   549,   549,   554,   565,   572,
     592,   611,   612,   625,   638,   654,   659,   684,   703,   725,
     726,   729,   732,   735,   738,   741,   744,   747,   750,   753,
     756,   759,   762,   763,   764,   765,   766,   767,   785,   828,
     835,   865,   895,   921,   931
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LBRACE", "RBRACE", "LPAR", "RPAR",
  "LSQUARE", "RSQUARE", "SEMI", "COLON", "PLUS", "MINUS", "MUL_OP",
  "DIV_OP", "MOD_OP", "AND_OP", "OR_OP", "NOT_OP", "ASSIGN", "LT", "GT",
  "SHL_OP", "SHR_OP", "EQ", "NOTEQ", "LTEQ", "GTEQ", "ANDAND", "OROR",
  "COMMA", "RETURN", "READ", "WRITE", "CASE", "DEFAULT", "BREAK", "QMARK",
  "HAT", "SUM", "WEIGHTED", "BY", "DO", "WHILE", "IF", "ELSE", "TYPE",
  "IDENTIFIER", "NUMBER", "EVAL", "UNLESS", "FOREACH", "FOR", "SWITCH",
  "DOLLAR", "AT", "NOT", "$accept", "program", "var_declarations",
  "var_declaration", "declaration_list", "declaration", "code_block",
  "statements", "statement", "control_statement", "read_write_statement",
  "assign_list", "assign_statement", "if_statement", "@1", "if_stmt", "@2",
  "@3", "unless_statement", "@4", "@5", "while_statement", "@6", "@7",
  "do_while_statement", "@8", "foreach_statement", "@9", "@10",
  "for_statement", "@11", "@12", "@13", "@14", "switch_statement", "@15",
  "switch_block", "case_statements", "case_statement", "@16",
  "default_statement", "@17", "break_statement", "return_statement",
  "read_statement", "write_statement", "exp", "exp_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    57,    58,    59,    59,    60,    61,    61,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      68,    68,    68,    69,    69,    70,    71,    70,    73,    74,
      72,    76,    77,    75,    79,    80,    78,    82,    81,    84,
      85,    83,    87,    88,    89,    90,    86,    92,    91,    93,
      93,    94,    94,    96,    95,    98,    97,    99,   100,   101,
     102,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   104,   104
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     2,     0,     3,     3,     1,     3,     4,
       1,     1,     3,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     2,     1,     2,     1,     1,
       0,     3,     1,     6,     3,     1,     0,     4,     0,     0,
       7,     0,     0,     6,     0,     0,     7,     0,     7,     0,
       0,     9,     0,     0,     0,     0,    13,     0,     8,     1,
       2,     2,     1,     0,     5,     0,     4,     1,     1,     4,
       4,     1,     1,     4,     5,     2,     2,     3,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     5,     3,
       7,     3,     7,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       4,     0,     0,     1,    18,    68,     0,     0,    67,    47,
      44,    38,     0,     0,    41,    49,    52,     0,     3,     2,
      14,    16,     0,     0,    19,    35,    20,    21,     0,    23,
      24,    26,     0,     0,    28,    29,     0,     0,     0,     0,
       0,    10,     0,     7,     0,     0,     0,     0,     0,     0,
      13,    17,    15,    36,    22,    27,    25,     0,     0,     0,
       0,     0,     0,    72,    71,    79,     0,     0,     0,    11,
       0,     0,     0,     0,     5,     0,     0,    34,    42,     0,
      30,     0,     0,    69,     0,    97,     0,    78,    75,     0,
       0,    70,     0,     0,     0,     0,     0,     0,     0,    76,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     6,
       0,     0,     0,     0,    32,     0,    37,    96,    77,     0,
       0,    82,    83,    84,    85,    99,    80,    81,    86,    87,
      92,    93,    88,    89,    90,    91,    94,    95,   101,     0,
       0,    12,     0,    45,    39,     9,     0,     0,     0,    53,
       0,    57,     0,     0,    73,     0,     0,     0,     0,     0,
      33,    43,     0,     0,    31,     0,     0,     0,    74,    98,
      48,    46,    40,    50,     0,     0,     0,    59,    62,     0,
     104,     0,     0,    54,     0,    58,     0,    61,    60,   100,
     102,     0,    51,    30,    63,    65,   103,     0,     0,     0,
      55,    64,    66,     0,    56
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,    18,    42,    43,    68,    19,    69,    21,
      22,   123,    65,    24,    82,    25,    40,   169,    26,    46,
     121,    27,    39,   168,    28,    38,    29,    47,   192,    30,
      48,   173,   203,   213,    31,   175,   186,   187,   188,   208,
     198,   209,    32,    33,    34,    35,   137,   191
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -66
static const short int yypact[] =
{
     -66,    13,   519,   -66,   -66,   -66,     6,    19,   -66,   -66,
     -66,   -66,   -43,     8,   -66,   -66,   -66,    21,   -66,   590,
     -66,   -66,    34,    36,   -66,     7,   -66,   -66,    42,   -66,
     -66,   -66,    44,    45,   -66,   -66,    -7,   762,    30,    53,
      54,     9,     1,   -66,   762,   762,    30,    55,    59,    29,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,    78,   762,   762,
     762,   -28,    48,    11,   -66,   -66,   231,   590,    52,   -66,
     762,   762,    62,    64,   -66,   -43,   406,   668,   -66,    49,
      66,   108,    30,   -66,   266,    -6,   703,   -66,   -66,    74,
     762,   -66,   762,   762,   762,   762,   762,   762,   762,   -66,
     762,   762,   762,   762,   762,   762,   762,   762,   762,   762,
     762,   762,   762,   187,   111,   301,   336,   118,   -66,   -66,
     116,    86,   127,     5,   -66,   135,   -66,   102,   762,    93,
     441,    -6,    -6,    31,    31,   668,   107,   808,   170,   170,
     845,   845,   827,   827,   170,   170,   773,   738,   668,   633,
     520,   -66,   762,   -66,   -66,   -66,   762,   762,    94,   -66,
      66,   -66,   762,   139,   116,   762,   762,   371,    30,    30,
     668,   668,   136,   762,   -66,   114,   566,   762,    32,   668,
     -66,   -66,   -66,   -66,   485,   104,   146,   -13,   -66,   762,
     668,    -5,    30,   -66,   145,   -66,   147,   -66,   -66,   668,
     -66,   762,   -66,    66,   -66,   -66,   668,    -1,   590,   590,
     -66,   590,   590,    30,   -66
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
     -66,   -66,   -66,   -66,   -66,    81,   -45,   -65,     4,   -66,
     -66,   -39,    -2,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -27,   -66,
     -66,   -66,   -66,   -66,   -66,   -66,    -3,   -66
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      23,    78,   113,   200,    41,   210,    20,    94,    95,    96,
      74,    36,    99,     3,   159,    44,    72,    23,    90,    87,
      88,   185,   196,    50,    37,   201,    49,    45,    73,   160,
      45,    75,   110,    67,    66,   160,    23,   126,   111,     4,
      57,    76,    77,    51,    23,    52,    96,    96,   112,    99,
      99,    54,    53,    55,    56,    84,    85,    86,    70,    71,
      79,     5,     6,     7,    80,    23,     8,   115,   116,   110,
     110,    20,     9,    10,    11,   111,    81,    13,   124,    14,
      23,    15,    16,    17,    83,   112,   112,   130,    89,   131,
     132,   133,   134,   135,   136,   114,   122,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     117,    23,   118,    13,   125,   129,   152,    50,    92,    93,
      94,    95,    96,   181,   182,    99,   155,   100,   101,   102,
     103,   104,   105,   106,   107,   156,   157,   158,   161,   162,
     163,   172,   183,   211,   212,   110,   177,   202,   185,   167,
     195,   111,   194,   170,   171,   204,   119,   205,   174,   176,
     197,   112,   178,   179,   207,     0,    23,    23,   214,     0,
     184,     0,     0,     0,   190,     0,     0,     0,     0,     0,
       0,    92,    93,    94,    95,    96,   199,     0,    99,     0,
      23,   151,   102,   103,     0,     0,     4,     0,   206,     0,
       0,   124,     0,     0,     0,     0,    23,    23,   110,    23,
      23,    23,    20,    20,   111,    50,    50,     0,     5,     6,
       7,     0,     0,     8,   112,     0,     0,     0,     0,     9,
      10,    11,     0,     0,    13,     0,    14,    91,    15,    16,
      17,     0,    92,    93,    94,    95,    96,    97,    98,    99,
       0,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,   127,     0,     0,   111,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   112,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,   153,     0,     0,
     111,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     112,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,   154,     0,     0,   111,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   112,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,   180,     0,     0,
     111,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     112,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,   120,   111,     0,    92,    93,    94,
      95,    96,    97,    98,    99,   112,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,   164,
     111,     0,    92,    93,    94,    95,    96,    97,    98,    99,
     112,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,     0,     0,     0,     0,     0,     0,     0,     0,   110,
       0,     0,     0,     0,     0,   111,     0,     0,     0,     0,
       0,     0,     0,     0,   193,   112,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,     0,     0,     0,     0,     0,
       0,     0,     0,   110,     0,     0,     0,     0,     4,   111,
       0,    92,    93,    94,    95,    96,    97,    98,    99,   112,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
       5,     6,     7,     0,     0,     8,     0,     0,   110,     0,
       0,     9,    10,    11,   111,    12,    13,     0,    14,     0,
      15,    16,    17,     0,   112,   166,   189,    92,    93,    94,
      95,    96,    97,    98,    99,     0,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,     0,     0,     0,     4,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     112,     5,     6,     7,     0,     0,     8,     0,     0,     0,
       0,     0,     9,    10,    11,     0,     0,    13,     0,    14,
       0,    15,    16,    17,    92,    93,    94,    95,    96,    97,
      98,    99,     0,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,   111,   165,    92,
      93,    94,    95,    96,    97,    98,    99,   112,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,   111,     0,    92,    93,    94,    95,    96,    97,
     128,    99,   112,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,   111,     0,    92,
      93,    94,    95,    96,    97,    98,    99,   112,   100,   101,
     102,   103,   104,   105,   106,   107,   108,    58,     0,     0,
       0,     0,     0,     0,    59,     0,   110,     0,     0,    60,
      61,     0,   111,     0,    92,    93,    94,    95,    96,    97,
      98,    99,   112,   100,   101,   102,   103,   104,   105,   106,
     107,    62,     0,     0,     0,     0,     0,     0,     0,    63,
      64,   110,     0,     0,     0,     0,     0,   111,     0,    92,
      93,    94,    95,    96,    97,     0,    99,   112,   100,   101,
     102,   103,   104,   105,   106,   107,     0,     0,    92,    93,
      94,    95,    96,     0,     0,    99,   110,   100,   101,   102,
     103,     0,   111,   106,   107,     0,    92,    93,    94,    95,
      96,     0,   112,    99,     0,   110,     0,     0,     0,     0,
       0,   111,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   112,     0,   110,     0,     0,     0,     0,     0,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   112
};

static const short int yycheck[] =
{
       2,    46,    67,     8,    47,     6,     2,    13,    14,    15,
       9,     5,    18,     0,     9,     7,     7,    19,     7,    47,
      48,    34,    35,    19,     5,    30,     5,    19,    19,    30,
      19,    30,    38,     3,    37,    30,    38,    82,    44,     9,
      47,    44,    45,     9,    46,     9,    15,    15,    54,    18,
      18,     9,    45,     9,     9,    58,    59,    60,     5,     5,
       5,    31,    32,    33,     5,    67,    36,    70,    71,    38,
      38,    67,    42,    43,    44,    44,    47,    47,    80,    49,
      82,    51,    52,    53,     6,    54,    54,    90,    40,    92,
      93,    94,    95,    96,    97,    43,    47,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      48,   113,    48,    47,     6,    41,     5,   113,    11,    12,
      13,    14,    15,   168,   169,    18,     8,    20,    21,    22,
      23,    24,    25,    26,    27,    19,    50,    10,     3,    37,
      47,    47,     6,   208,   209,    38,     7,   192,    34,   152,
       4,    44,    48,   156,   157,    10,    75,    10,   160,   162,
     187,    54,   165,   166,   203,    -1,   168,   169,   213,    -1,
     173,    -1,    -1,    -1,   177,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    12,    13,    14,    15,   189,    -1,    18,    -1,
     192,     4,    22,    23,    -1,    -1,     9,    -1,   201,    -1,
      -1,   203,    -1,    -1,    -1,    -1,   208,   209,    38,   211,
     212,   213,   208,   209,    44,   211,   212,    -1,    31,    32,
      33,    -1,    -1,    36,    54,    -1,    -1,    -1,    -1,    42,
      43,    44,    -1,    -1,    47,    -1,    49,     6,    51,    52,
      53,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,     6,    -1,    -1,    44,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    54,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,     6,    -1,    -1,
      44,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      54,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,     6,    -1,    -1,    44,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    54,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,     6,    -1,    -1,
      44,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      54,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,     8,    44,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    54,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,     8,
      44,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      54,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    54,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,     9,    44,
      -1,    11,    12,    13,    14,    15,    16,    17,    18,    54,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      31,    32,    33,    -1,    -1,    36,    -1,    -1,    38,    -1,
      -1,    42,    43,    44,    44,    46,    47,    -1,    49,    -1,
      51,    52,    53,    -1,    54,    55,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    -1,    -1,    47,    -1,    49,
      -1,    51,    52,    53,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    11,
      12,    13,    14,    15,    16,    17,    18,    54,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    54,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    54,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    38,    -1,    -1,    17,
      18,    -1,    44,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    54,    20,    21,    22,    23,    24,    25,    26,
      27,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    11,
      12,    13,    14,    15,    16,    -1,    18,    54,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    -1,    11,    12,
      13,    14,    15,    -1,    -1,    18,    38,    20,    21,    22,
      23,    -1,    44,    26,    27,    -1,    11,    12,    13,    14,
      15,    -1,    54,    18,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    58,    59,     0,     9,    31,    32,    33,    36,    42,
      43,    44,    46,    47,    49,    51,    52,    53,    60,    64,
      65,    66,    67,    69,    70,    72,    75,    78,    81,    83,
      86,    91,    99,   100,   101,   102,     5,     5,    82,    79,
      73,    47,    61,    62,     7,    19,    76,    84,    87,     5,
      65,     9,     9,    45,     9,     9,     9,    47,     5,    12,
      17,    18,    39,    47,    48,    69,   103,     3,    63,    65,
       5,     5,     7,    19,     9,    30,   103,   103,    63,     5,
       5,    47,    71,     6,   103,   103,   103,    47,    48,    40,
       7,     6,    11,    12,    13,    14,    15,    16,    17,    18,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      38,    44,    54,    64,    43,   103,   103,    48,    48,    62,
       8,    77,    47,    68,    69,     6,    63,     6,    17,    41,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,     4,     5,     6,     6,     8,    19,    50,    10,     9,
      30,     3,    37,    47,     8,    45,    55,   103,    80,    74,
     103,   103,    47,    88,    69,    92,   103,     7,   103,   103,
       6,    63,    63,     6,   103,    34,    93,    94,    95,    10,
     103,   104,    85,     9,    48,     4,    35,    95,    97,   103,
       8,    30,    63,    89,    10,    10,   103,    68,    96,    98,
       6,    64,    64,    90,    63
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 187 "Acse.y"
    {
            /* Notify the end of the program. Once called
             * the function `set_end_Program' - if necessary -
             * introduces a `HALT' instruction into the
             * list of instructions. */
            set_end_Program(program);

            /* return from yyparse() */
            YYACCEPT;
         ;}
    break;

  case 3:
#line 199 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 4:
#line 200 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 5:
#line 204 "Acse.y"
    {
                     /* update the program infos by adding new variables */
                     set_new_variables(program, (yyvsp[-2].intval), (yyvsp[-1].list));
                  ;}
    break;

  case 6:
#line 211 "Acse.y"
    {  /* add the new declaration to the list of declarations */
                     (yyval.list) = addElement((yyvsp[-2].list), (yyvsp[0].decl), -1);
                  ;}
    break;

  case 7:
#line 215 "Acse.y"
    {
                     /* add the new declaration to the list of declarations */
                     (yyval.list) = addElement(NULL, (yyvsp[0].decl), -1);
                  ;}
    break;

  case 8:
#line 222 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[-2].svalue), 0, 0, (yyvsp[0].intval));

               /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 9:
#line 231 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[-3].svalue), 1, (yyvsp[-1].intval), 0);

                  /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 10:
#line 240 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[0].svalue), 0, 0, 0);
               
               /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 11:
#line 253 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 12:
#line 254 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 13:
#line 258 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 14:
#line 259 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 15:
#line 264 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 16:
#line 265 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 17:
#line 266 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 18:
#line 267 "Acse.y"
    { gen_nop_instruction(program); ;}
    break;

  case 19:
#line 270 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 20:
#line 271 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 21:
#line 272 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 22:
#line 273 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 23:
#line 274 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 24:
#line 275 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 25:
#line 276 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 26:
#line 277 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 27:
#line 278 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 28:
#line 281 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 29:
#line 282 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 30:
#line 285 "Acse.y"
    {;}
    break;

  case 31:
#line 286 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 32:
#line 287 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 33:
#line 290 "Acse.y"
    {
               storeArrayElement(program, (yyvsp[-5].svalue), (yyvsp[-3].expr), (yyvsp[0].expr));
			   (yyval.expr) = create_expression((yyvsp[0].expr).value, IMMEDIATE);
               free((yyvsp[-5].svalue));
            ;}
    break;

  case 34:
#line 296 "Acse.y"
    {
               int location;
               location = get_symbol_location(program, (yyvsp[-2].svalue), 0);

               if ((yyvsp[0].expr).expression_type == IMMEDIATE) {
					gen_addi_instruction(program, location, REG_0, (yyvsp[0].expr).value);
					(yyval.expr) = create_expression((yyvsp[0].expr).value, IMMEDIATE);
			   }
               else {
			        gen_add_instruction(program, location, REG_0, (yyvsp[0].expr).value, CG_DIRECT_ALL);
					(yyval.expr) = create_expression((yyvsp[0].expr).value, REGISTER);
			   }
			   free((yyvsp[-2].svalue));
            ;}
    break;

  case 35:
#line 313 "Acse.y"
    {
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[0].label));
               ;}
    break;

  case 36:
#line 318 "Acse.y"
    {
                  /* reserve a new label that points to the address where to jump if
                   * `exp' is verified */
                  (yyvsp[0].label) = newLabel(program);
   
                  /* exit from the if-else */
                  gen_bt_instruction (program, (yyvsp[0].label), 0);
   
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[-1].label));
               ;}
    break;

  case 37:
#line 330 "Acse.y"
    {
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[-2].label));
               ;}
    break;

  case 38:
#line 337 "Acse.y"
    {
                  /* the label that points to the address where to jump if
                   * `exp' is not verified */
                  (yyvsp[0].label) = newLabel(program);
               ;}
    break;

  case 39:
#line 343 "Acse.y"
    {
                     if ((yyvsp[-1].expr).expression_type == IMMEDIATE)
                         gen_load_immediate(program, (yyvsp[-1].expr).value);
                     else
                         gen_andb_instruction(program, (yyvsp[-1].expr).value,
                             (yyvsp[-1].expr).value, (yyvsp[-1].expr).value, CG_DIRECT_ALL);

                     /* if `exp' returns FALSE, jump to the label $1 */
                     gen_beq_instruction (program, (yyvsp[-4].label), 0);
               ;}
    break;

  case 40:
#line 353 "Acse.y"
    { (yyval.label) = (yyvsp[-6].label); ;}
    break;

  case 41:
#line 356 "Acse.y"
    {
				(yyvsp[0].unless_stmt) = create_unless_statement();
				(yyvsp[0].unless_stmt).condition = newLabel(program);
				(yyvsp[0].unless_stmt).code_block = newLabel(program);
				(yyvsp[0].unless_stmt).end = newLabel(program);
				gen_bt_instruction(program, (yyvsp[0].unless_stmt).condition, 0);
				assignLabel(program, (yyvsp[0].unless_stmt).code_block);
			;}
    break;

  case 42:
#line 364 "Acse.y"
    {
				gen_bt_instruction(program, (yyvsp[-2].unless_stmt).end, 0);
				assignLabel(program, (yyvsp[-2].unless_stmt).condition);
			;}
    break;

  case 43:
#line 368 "Acse.y"
    {
				if ((yyvsp[0].expr).expression_type == IMMEDIATE) {
					gen_load_immediate(program, (yyvsp[0].expr).value);
				}
				else {
					gen_andb_instruction(program, (yyvsp[0].expr).value, (yyvsp[0].expr).value, (yyvsp[0].expr).value, CG_DIRECT_ALL);
				}
				gen_beq_instruction(program, (yyvsp[-5].unless_stmt).code_block, 0);
				assignLabel(program, (yyvsp[-5].unless_stmt).end);
			;}
    break;

  case 44:
#line 381 "Acse.y"
    {
                     /* initialize the value of the non-terminal */
                     (yyvsp[0].while_stmt) = create_while_statement();

                     /* reserve and fix a new label */
                     (yyvsp[0].while_stmt).label_condition
                           = assignNewLabel(program);
                  ;}
    break;

  case 45:
#line 390 "Acse.y"
    {
                     if ((yyvsp[-1].expr).expression_type == IMMEDIATE)
                        gen_load_immediate(program, (yyvsp[-1].expr).value);
                     else
                         gen_andb_instruction(program, (yyvsp[-1].expr).value,
                             (yyvsp[-1].expr).value, (yyvsp[-1].expr).value, CG_DIRECT_ALL);

                     /* reserve a new label. This new label will point
                      * to the first instruction after the while code
                      * block */
                     (yyvsp[-4].while_stmt).label_end = newLabel(program);

                     /* if `exp' returns FALSE, jump to the label $1.label_end */
                     gen_beq_instruction (program, (yyvsp[-4].while_stmt).label_end, 0);
                  ;}
    break;

  case 46:
#line 406 "Acse.y"
    {
                     /* jump to the beginning of the loop */
                     gen_bt_instruction
                           (program, (yyvsp[-6].while_stmt).label_condition, 0);

                     /* fix the label `label_end' */
                     assignLabel(program, (yyvsp[-6].while_stmt).label_end);
                  ;}
    break;

  case 47:
#line 417 "Acse.y"
    {
                        /* the label that points to the address where to jump if
                         * `exp' is not verified */
                        (yyvsp[0].label) = newLabel(program);
                        
                        /* fix the label */
                        assignLabel(program, (yyvsp[0].label));
                     ;}
    break;

  case 48:
#line 426 "Acse.y"
    {
                           if ((yyvsp[-1].expr).expression_type == IMMEDIATE)
                               gen_load_immediate(program, (yyvsp[-1].expr).value);
                           else
                               gen_andb_instruction(program, (yyvsp[-1].expr).value,
                                   (yyvsp[-1].expr).value, (yyvsp[-1].expr).value, CG_DIRECT_ALL);

                           /* if `exp' returns TRUE, jump to the label $1 */
                           gen_bne_instruction (program, (yyvsp[-6].label), 0);
                     ;}
    break;

  case 49:
#line 439 "Acse.y"
    {
				(yyvsp[0].foreach_stmt).counter = getNewRegister(program);
				gen_addi_instruction(program, (yyvsp[0].foreach_stmt).counter, REG_0, 0);
				(yyvsp[0].foreach_stmt).iteration = newLabel(program);
				(yyvsp[0].foreach_stmt).end = newLabel(program);
				assignLabel(program, (yyvsp[0].foreach_stmt).iteration);
			;}
    break;

  case 50:
#line 447 "Acse.y"
    {
				int var_location = get_symbol_location(program, (yyvsp[-3].svalue), 0);
				t_axe_variable * array_declaration = getVariable(program, (yyvsp[-1].svalue));
				
				int temp_register = getNewRegister(program);
				gen_subi_instruction(program, temp_register, (yyvsp[-6].foreach_stmt).counter, array_declaration->arraySize);
				gen_beq_instruction(program, (yyvsp[-6].foreach_stmt).end, 0);
					
				int new_value = loadArrayElement(program, (yyvsp[-1].svalue), create_expression((yyvsp[-6].foreach_stmt).counter, REGISTER));
				gen_add_instruction(program, var_location, REG_0, new_value, CG_DIRECT_ALL);
				free((yyvsp[-3].svalue));
				free((yyvsp[-1].svalue));
			;}
    break;

  case 51:
#line 461 "Acse.y"
    {
				gen_addi_instruction(program, (yyvsp[-8].foreach_stmt).counter, (yyvsp[-8].foreach_stmt).counter, 1);
				gen_bt_instruction(program, (yyvsp[-8].foreach_stmt).iteration, 0);
				assignLabel(program, (yyvsp[-8].foreach_stmt).end);
			;}
    break;

  case 52:
#line 468 "Acse.y"
    { (yyvsp[0].for_stmt) = create_for_statement();;}
    break;

  case 53:
#line 469 "Acse.y"
    {(yyvsp[-4].for_stmt).label_exp = assignNewLabel(program);;}
    break;

  case 54:
#line 471 "Acse.y"
    {
          (yyvsp[-7].for_stmt).label_end = newLabel(program);
          gen_beq_instruction(program, (yyvsp[-7].for_stmt).label_end, 0);
          (yyvsp[-7].for_stmt).label_code = newLabel(program);
          gen_bt_instruction(program, (yyvsp[-7].for_stmt).label_code, 0);
          (yyvsp[-7].for_stmt).label_epilogue = assignNewLabel(program);
        ;}
    break;

  case 55:
#line 479 "Acse.y"
    {
          gen_bt_instruction(program, (yyvsp[-10].for_stmt).label_exp, 0);
          assignLabel(program, (yyvsp[-10].for_stmt).label_code);
        ;}
    break;

  case 56:
#line 484 "Acse.y"
    {
          gen_bt_instruction(program, (yyvsp[-12].for_stmt).label_epilogue, 0);
          assignLabel(program, (yyvsp[-12].for_stmt).label_end);
        ;}
    break;

  case 57:
#line 490 "Acse.y"
    {
					
					/* allocate memory for switch struct that will later be inserted into the stack */
					(yyvsp[-4].switch_stmt) = (t_switch_statement *)malloc(sizeof(t_switch_statement));
					(yyvsp[-4].switch_stmt)->cmp_register = getNewRegister(program);
					/* get_symbol_location returns a register where the $3 ID is stored */
					gen_addi_instruction(program, (yyvsp[-4].switch_stmt)->cmp_register, get_symbol_location(program,(yyvsp[-2].svalue),0), 0);
					
					(yyvsp[-4].switch_stmt)->begin_tests = newLabel(program);
					(yyvsp[-4].switch_stmt)->switch_end = newLabel(program);
					
					switchStack = addFirst(switchStack, (yyvsp[-4].switch_stmt));
					gen_bt_instruction(program, (yyvsp[-4].switch_stmt)->begin_tests, 0);

					;}
    break;

  case 58:
#line 504 "Acse.y"
    {

						t_list *p;
						int cmpReg;
						assignLabel(program, (yyvsp[-7].switch_stmt)->begin_tests);
						cmpReg = getNewRegister(program);
						p = (yyvsp[-7].switch_stmt)->cases;
						/* test all the cases */
						while(p!=NULL){
							/* cmpReg is 0 if the case is the correct one. p->data access an element of the list which is casted to a t_case_statement */
							gen_subi_instruction(program,cmpReg, (yyvsp[-7].switch_stmt)->cmp_register, ((t_case_statement *)p->data)->number);
							gen_beq_instruction(program, ((t_case_statement*)p->data)->begin_case, 0);
              p = p->next;
						}
						/* check if there is a default statement */
						if((yyvsp[-7].switch_stmt)->default_label!=NULL){
							gen_bt_instruction(program, (yyvsp[-7].switch_stmt)->default_label, 0);
            }

						assignLabel(program, (yyvsp[-7].switch_stmt)->switch_end);
						/* current switch has been executed, remove it from stack */
						switchStack = removeFirst(switchStack);
					;}
    break;

  case 59:
#line 529 "Acse.y"
    {
					gen_bt_instruction(program, ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->switch_end, 0);
				;}
    break;

  case 60:
#line 532 "Acse.y"
    {
					gen_bt_instruction(program, ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->switch_end, 0);
				;}
    break;

  case 63:
#line 539 "Acse.y"
    {
          /* allocate memory for the test_case */
					t_case_statement *c = (t_case_statement *)malloc(sizeof(t_case_statement));
					c->number = (yyvsp[-1].intval); // assign number to c
					c->begin_case = assignNewLabel(program);
					/* update list of cases with c as last element */
          ((t_switch_statement *)LDATA(getElementAt(switchStack, 0)))->cases = addLast(((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->cases, c);
				;}
    break;

  case 65:
#line 549 "Acse.y"
    {
          ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->default_label = assignNewLabel(program);
					;}
    break;

  case 67:
#line 554 "Acse.y"
    {
                  if(switchStack==NULL){
                    abort();
                  }
                  else{
                    /* jump to the end of the current active switch statement */
                    gen_bt_instruction(program, ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->switch_end, 0);
                  }
                ;}
    break;

  case 68:
#line 566 "Acse.y"
    {
               /* insert an HALT instruction */
               gen_halt_instruction(program);
            ;}
    break;

  case 69:
#line 573 "Acse.y"
    {
               int location;
               
               /* read from standard input an integer value and assign
                * it to a variable associated with the given identifier */
               /* get the location of the symbol with the given ID */
               
               /* lookup the symbol table and fetch the register location
                * associated with the IDENTIFIER $3. */
               location = get_symbol_location(program, (yyvsp[-1].svalue), 0);

               /* insert a read instruction */
               gen_read_instruction (program, location);

               /* free the memory associated with the IDENTIFIER */
               free((yyvsp[-1].svalue));
            ;}
    break;

  case 70:
#line 593 "Acse.y"
    {
   
               int location;

               if ((yyvsp[-1].expr).expression_type == IMMEDIATE)
               {
                  /* load `immediate' into a new register. Returns the new register
                   * identifier or REG_INVALID if an error occurs */
                  location = gen_load_immediate(program, (yyvsp[-1].expr).value);
               }
               else
                  location = (yyvsp[-1].expr).value;

               /* write to standard output an integer value */
               gen_write_instruction (program, location);
            ;}
    break;

  case 71:
#line 611 "Acse.y"
    { (yyval.expr) = create_expression ((yyvsp[0].intval), IMMEDIATE); ;}
    break;

  case 72:
#line 612 "Acse.y"
    {
                     int location;
   
                     /* get the location of the symbol with the given ID */
                     location = get_symbol_location(program, (yyvsp[0].svalue), 0);
                     
                     /* return the register location of IDENTIFIER as
                      * a value for `exp' */
                     (yyval.expr) = create_expression (location, REGISTER);

                     /* free the memory associated with the IDENTIFIER */
                     free((yyvsp[0].svalue));
   ;}
    break;

  case 73:
#line 625 "Acse.y"
    {
                     int reg;
                     
                     /* load the value IDENTIFIER[exp]
                      * into `arrayElement' */
                     reg = loadArrayElement(program, (yyvsp[-3].svalue), (yyvsp[-1].expr));

                     /* create a new expression */
                     (yyval.expr) = create_expression (reg, REGISTER);

                     /* free the memory associated with the IDENTIFIER */
                     free((yyvsp[-3].svalue));
   ;}
    break;

  case 74:
#line 638 "Acse.y"
    {
                            if ((yyvsp[-2].expr).expression_type == IMMEDIATE){
                              (yyval.expr) = (yyvsp[-2].expr).value ? (yyvsp[-4].expr) : (yyvsp[0].expr);
                            }
                            else{
                              t_axe_expression zero = create_expression(0, IMMEDIATE);
                              t_axe_expression one = create_expression(1, IMMEDIATE);
                              t_axe_expression cmp = handle_binary_comparison(program,(yyvsp[-2].expr),zero,_EQ_);
                              t_axe_expression mask = handle_bin_numeric_op(program, (yyvsp[-2].expr), one, SUB);
                              int r = getNewRegister(program);
                              gen_notb_instruction(program,r,mask.value);
                              t_axe_expression nmask = create_expression(r, REGISTER);
                              (yyval.expr) = handle_bin_numeric_op(program,handle_bin_numeric_op(program,(yyvsp[-4].expr),mask,ANDB),
                                handle_bin_numeric_op(program,(yyvsp[0].expr),nmask,ANDB),ORB);
                            }
   ;}
    break;

  case 75:
#line 654 "Acse.y"
    {  if ((yyvsp[0].intval) == 0)
                           (yyval.expr) = create_expression (1, IMMEDIATE);
                        else
                           (yyval.expr) = create_expression (0, IMMEDIATE);
   ;}
    break;

  case 76:
#line 659 "Acse.y"
    {
   		int r_reg = gen_load_immediate(program, 1); // Init register with value 1
   		int i_reg = getNewRegister(program); // Register used as decrementing counter

   		// inseert into i_reg the value of $1 exp i <- $1.value
   		if( (yyvsp[-1].expr).expression_type == IMMEDIATE){
   			gen_addi_instruction(program,i_reg,REG_0,(yyvsp[-1].expr).value);
   		}
   		else{
   			gen_add_instruction(program,i_reg,REG_0,(yyvsp[-1].expr).value,CG_DIRECT_ALL);
   		}

   		// create a label and jump to it if the value of $1 is equal to 0
   		t_axe_label* l_end = newLabel(program);
   		gen_beq_instruction(program,l_end,0);
   		
   		t_axe_label* l_cond = assignNewLabel(program);// create a label to which jump when performing iteration 
   		gen_mul_instruction(program,r_reg,r_reg,i_reg,CG_DIRECT_ALL); // r <- r * i
   		gen_subi_instruction(program,i_reg,i_reg,1); // i <- i - 1
   		gen_bgt_instruction(program,l_cond,0); // if i is still positive repeate iteration

   		assignLabel(program, l_end);

   		(yyval.expr) = create_expression(r_reg, REGISTER);
   ;}
    break;

  case 77:
#line 684 "Acse.y"
    {

        if ((yyvsp[-1].expr).expression_type == IMMEDIATE)
           (yyval.expr) = create_expression((yyvsp[-1].expr).value > 0 ? (yyvsp[-1].expr).value : - (yyvsp[-1].expr).value, IMMEDIATE); 
        else
        {
          int r_reg = getNewRegister(program);
          gen_add_instruction(program,r_reg,REG_0,(yyvsp[-1].expr).value,CG_DIRECT_ALL);

          t_axe_label* l_end = newLabel(program);
          gen_bpl_instruction(program,l_end,0);

          gen_muli_instruction(program,r_reg,r_reg,-1);

          assignLabel(program, l_end);

          (yyval.expr) = create_expression(r_reg, REGISTER);
        }
   ;}
    break;

  case 78:
#line 703 "Acse.y"
    {
                           int identifier_location;
                           int output_register;
   
                           /* get the location of the symbol with the given ID */
                           identifier_location =
                                 get_symbol_location(program, (yyvsp[0].svalue), 0);

                           /* generate a NOT instruction. In order to do this,
                            * at first we have to ask for a free register where
                            * to store the result of the NOT instruction. */
                           output_register = getNewRegister(program);

                           /* Now we are able to generate a NOT instruction */
                           gen_notl_instruction (program, output_register
                                 , identifier_location);

                           (yyval.expr) = create_expression (output_register, REGISTER);

                           /* free the memory associated with the IDENTIFIER */
                           free((yyvsp[0].svalue));
   ;}
    break;

  case 79:
#line 725 "Acse.y"
    {;}
    break;

  case 80:
#line 726 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ANDB);
   ;}
    break;

  case 81:
#line 729 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ORB);
   ;}
    break;

  case 82:
#line 732 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ADD);
   ;}
    break;

  case 83:
#line 735 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SUB);
   ;}
    break;

  case 84:
#line 738 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), MUL);
   ;}
    break;

  case 85:
#line 741 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), DIV);
   ;}
    break;

  case 86:
#line 744 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _LT_);
   ;}
    break;

  case 87:
#line 747 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _GT_);
   ;}
    break;

  case 88:
#line 750 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _EQ_);
   ;}
    break;

  case 89:
#line 753 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _NOTEQ_);
   ;}
    break;

  case 90:
#line 756 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _LTEQ_);
   ;}
    break;

  case 91:
#line 759 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _GTEQ_);
   ;}
    break;

  case 92:
#line 762 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SHL); ;}
    break;

  case 93:
#line 763 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SHR); ;}
    break;

  case 94:
#line 764 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ANDL); ;}
    break;

  case 95:
#line 765 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ORL); ;}
    break;

  case 96:
#line 766 "Acse.y"
    { (yyval.expr) = (yyvsp[-1].expr); ;}
    break;

  case 97:
#line 767 "Acse.y"
    {
                        if ((yyvsp[0].expr).expression_type == IMMEDIATE)
                        {
                           (yyval.expr) = (yyvsp[0].expr);
                           (yyval.expr).value = - ((yyval.expr).value);
                        }
                        else
                        {
                           t_axe_expression exp_r0;

                           /* create an expression for regisrer REG_0 */
                           exp_r0.value = REG_0;
                           exp_r0.expression_type = REGISTER;
                           
                           (yyval.expr) = handle_bin_numeric_op
                                 (program, exp_r0, (yyvsp[0].expr), SUB);
                        }
                     ;}
    break;

  case 98:
#line 785 "Acse.y"
    {
                    int e_c = getNewRegister(program);

                    if( (yyvsp[0].expr).value > 32)
                      e_c = 0;
                    else
                      e_c = 32 - (yyvsp[0].expr).value;

                    int r_e2 = gen_load_immediate(program, 0); // r_e2 <- 0
                    int r_index = gen_load_immediate(program, e_c); // r_index <-  e_c

                    (yyvsp[-1].label) = newLabel(program); // label end
                    (yyvsp[-3].label) = assignNewLabel(program); // label condition

                    /* at the end of this loop r_e2 will have all 0's and (32 - k) 1's has l.s. digits */
                    gen_beq_instruction(program, (yyvsp[-1].label), 0); // if r_index is 0 jump to $4 label
                    gen_shli_instruction(program, r_e2, r_e2, 1); // r_e2 <- shtl(r_e2)
                    gen_addi_instruction(program, r_e2, r_e2, 1); /// r_e2 <- r_e2 + 1
                    gen_subi_instruction(program, r_index, r_index, 1); // r_index <- r_index - 1
                    gen_bt_instruction(program, (yyvsp[-3].label), 0); // jump to $2 label
                    assignLabel(program, (yyvsp[-1].label));



                    int r_e1 = getNewRegister(program);
                    gen_notb_instruction(program, r_e1, r_e2); /*define mask for e1 through*/

                    /*get r_e1 bits of exp1*/
                    if ((yyvsp[-4].expr).expression_type == IMMEDIATE)
                      gen_andb_instruction(program, r_e1, r_e1, gen_load_immediate(program, (yyvsp[-4].expr).value), CG_DIRECT_ALL);
                    else
                      gen_andb_instruction(program, r_e1, r_e1, (yyvsp[-4].expr).value, CG_DIRECT_ALL);

                    /*get 32-e1 bits of exp2*/
                    if ((yyvsp[-2].expr).expression_type == IMMEDIATE)
                      gen_andb_instruction(program, r_e2, r_e2, gen_load_immediate(program, (yyvsp[-2].expr).value), CG_DIRECT_ALL);
                    else
                      gen_andb_instruction(program, r_e2, r_e2, (yyvsp[-2].expr).value, CG_DIRECT_ALL);
                    
                    int r = getNewRegister(program);
                    gen_orb_instruction(program, r, r_e1, r_e2, CG_DIRECT_ALL);
                    (yyval.expr) = create_expression(r, REGISTER);
                  ;}
    break;

  case 99:
#line 828 "Acse.y"
    {
          int q_reg = getNewRegister(program);
          t_axe_expression q = create_expression(q_reg, REGISTER); // Quotient of the division

          q = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), DIV); // d <- a / b (integer)
          (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), handle_bin_numeric_op(program, (yyvsp[0].expr), q, MUL), SUB);
  ;}
    break;

  case 100:
#line 835 "Acse.y"
    {
          t_axe_label *label_false = newLabel(program);
          t_axe_label *label_end = newLabel(program);
          int cmpReg = getNewRegister(program);

          if((yyvsp[-5].expr).expression_type == IMMEDIATE)
            (yyval.expr) = (yyvsp[-5].expr).value ? (yyvsp[-2].expr) : (yyvsp[0].expr);
          else
            gen_andb_instruction(program, (yyvsp[-5].expr).value, (yyvsp[-5].expr).value, (yyvsp[-5].expr).value, CG_DIRECT_ALL);

          gen_beq_instruction(program, label_false, 0); 
          
          // If the condition is true
          if((yyvsp[-2].expr).expression_type == IMMEDIATE)
             gen_addi_instruction(program, cmpReg, REG_0, (yyvsp[-2].expr).value);
          else
            gen_add_instruction(program, cmpReg, REG_0, (yyvsp[-2].expr).value, CG_DIRECT_ALL);
          
          gen_bt_instruction(program, label_end, 0);

          assignLabel(program, label_false);
          // If the condition is false
          if((yyvsp[0].expr).expression_type == IMMEDIATE)
             gen_addi_instruction(program, cmpReg, REG_0, (yyvsp[0].expr).value);
          else
            gen_add_instruction(program, cmpReg, REG_0, (yyvsp[0].expr).value, CG_DIRECT_ALL);
          assignLabel(program, label_end);
          
          (yyval.expr) = create_expression(cmpReg, REGISTER);
  ;}
    break;

  case 101:
#line 865 "Acse.y"
    {
          int index = getNewRegister(program);
          int result = gen_load_immediate(program, 1); // result <- 1
          int base = getNewRegister(program);
          t_axe_label* label_cond = newLabel(program);
          t_axe_label* label_end = newLabel(program);
          
          /* base <- $1.value */
          if ((yyvsp[-2].expr).expression_type == IMMEDIATE)
            gen_addi_instruction(program, base, REG_0, (yyvsp[-2].expr).value);
          else
            gen_add_instruction(program, base, REG_0, (yyvsp[-2].expr).value, CG_DIRECT_ALL);

          /* index <- $3.value */
          if ((yyvsp[0].expr).expression_type == IMMEDIATE)
            gen_addi_instruction(program, index, REG_0, (yyvsp[0].expr).value);
          else
            gen_add_instruction(program, index, REG_0, (yyvsp[0].expr).value, CG_DIRECT_ALL);

          assignLabel(program, label_cond);
          gen_beq_instruction(program, label_end, 0);

          gen_mul_instruction(program, result, result, base, CG_DIRECT_ALL);
          gen_subi_instruction(program, index, index, 1);

          gen_bt_instruction(program, label_cond, 0);

          assignLabel(program, label_end);
          (yyval.expr) = create_expression(result, REGISTER);
  ;}
    break;

  case 102:
#line 895 "Acse.y"
    {
        int result, temp_register;
        t_axe_expression counter;
        /* getting a register where to store the result */
        result = gen_load_immediate(program, 0);
        /* initialize the counter to 0 */
        counter = create_expression(0, IMMEDIATE);

        temp_register = getNewRegister(program);

        /* iterate over the exp_list */
        while((yyvsp[-1].list)!=NULL){
          /* t <- v[i] */
          temp_register = loadArrayElement(program, (yyvsp[-3].svalue), counter);
          /* t <- t * w[i] */
          gen_mul_instruction(program, temp_register, temp_register, (*(int*)(yyvsp[-1].list)->data), CG_DIRECT_ALL);
          /* r <- r + t */
          gen_add_instruction(program, result, temp_register, result, CG_DIRECT_ALL);
          /* i++ */
          counter.value++;
          (yyvsp[-1].list) = (yyvsp[-1].list)->next;
        }
        (yyval.expr) = create_expression(result, REGISTER);
  ;}
    break;

  case 103:
#line 921 "Acse.y"
    {
            int *temp_register = (int *) malloc(sizeof(int));
            if((yyvsp[0].expr).expression_type==IMMEDIATE)
              *temp_register =  gen_load_immediate(program, (yyvsp[0].expr).value);
            else
              *temp_register = (yyvsp[0].expr).value;

            (yyvsp[-2].list) = addLast((yyvsp[-2].list), temp_register);
            (yyval.list) = (yyvsp[-2].list);
          ;}
    break;

  case 104:
#line 931 "Acse.y"
    {
            t_list * head = NULL;
            int *temp_register = (int *) malloc(sizeof(int));
            if((yyvsp[0].expr).expression_type==IMMEDIATE)
              *temp_register = gen_load_immediate(program, (yyvsp[0].expr).value);
            else
              *temp_register = (yyvsp[0].expr).value;
            head = addLast(head, temp_register);
            (yyval.list) = head;
          ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 2703 "Acse.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
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
	  yydestruct ("Error: discarding", yytoken, &yylval);
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
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 942 "Acse.y"

/*=========================================================================
                                  MAIN
=========================================================================*/
int main (int argc, char **argv)
{
   /* initialize all the compiler data structures and global variables */
   init_compiler(argc, argv);
   
   /* start the parsing procedure */
   yyparse();
   
#ifndef NDEBUG
   fprintf(stdout, "Parsing process completed. \n");
#endif

   /* test if the parsing process completed succesfully */
   checkConsistency();
   
#ifndef NDEBUG
   fprintf(stdout, "Creating a control flow graph. \n");
#endif

   /* create the control flow graph */
   graph = createFlowGraph(program->instructions);
   checkConsistency();

#ifndef NDEBUG
   assert(program != NULL);
   assert(program->sy_table != NULL);
   assert(file_infos != NULL);
   assert(file_infos->syTable_output != NULL);
   printSymbolTable(program->sy_table, file_infos->syTable_output);
   printGraphInfos(graph, file_infos->cfg_1, 0);
      
   fprintf(stdout, "Updating the basic blocks. \n");
#endif
      
   /* update the control flow graph by inserting load and stores inside
   * every basic block */
   graph = insertLoadAndStoreInstr(program, graph);

#ifndef NDEBUG
   fprintf(stdout, "Executing a liveness analysis on the intermediate code \n");
#endif
   performLivenessAnalysis(graph);
   checkConsistency();

#ifndef NDEBUG
   printGraphInfos(graph, file_infos->cfg_2, 1);
#endif
      
#ifndef NDEBUG
   fprintf(stdout, "Starting the register allocation process. \n");
#endif
   /* initialize the register allocator by using the control flow
    * informations stored into the control flow graph */
   RA = initializeRegAlloc(graph);
      
   /* execute the linear scan algorythm */
   execute_linear_scan(RA);
      
#ifndef NDEBUG
   printRegAllocInfos(RA, file_infos->reg_alloc_output);
#endif

#ifndef NDEBUG
   fprintf(stdout, "Updating the control flow informations. \n");
#endif
   /* apply changes to the program informations by using the informations
   * of the register allocation process */
   updateProgramInfos(program, graph, RA);

#ifndef NDEBUG
   fprintf(stdout, "Writing the assembly file... \n");
#endif
   writeAssembly(program, file_infos->output_file_name);
      
#ifndef NDEBUG
   fprintf(stdout, "Assembly written on file \"%s\".\n", file_infos->output_file_name);
#endif
   
   /* shutdown the compiler */
   shutdownCompiler(0);

   return 0;
}

/*=========================================================================
                                 YYERROR
=========================================================================*/
int yyerror(const char* errmsg)
{
   errorcode = AXE_SYNTAX_ERROR;
   
   return 0;
}

