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
     EQARRAY = 275,
     LT = 276,
     GT = 277,
     SHL_OP = 278,
     SHR_OP = 279,
     EQ = 280,
     NOTEQ = 281,
     LTEQ = 282,
     GTEQ = 283,
     ANDAND = 284,
     OROR = 285,
     COMMA = 286,
     RETURN = 287,
     READ = 288,
     WRITE = 289,
     CASE = 290,
     DEFAULT = 291,
     BREAK = 292,
     QMARK = 293,
     HAT = 294,
     IN = 295,
     ON = 296,
     AS = 297,
     INTO = 298,
     DO = 299,
     WHILE = 300,
     IF = 301,
     ELSE = 302,
     TYPE = 303,
     IDENTIFIER = 304,
     NUMBER = 305,
     EVAL = 306,
     UNLESS = 307,
     FOREACH = 308,
     FOR = 309,
     SWITCH = 310,
     DOLLAR = 311,
     AT = 312,
     COND = 313,
     MAP = 314,
     REDUCE = 315,
     NOT = 316
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
#define EQARRAY 275
#define LT 276
#define GT 277
#define SHL_OP 278
#define SHR_OP 279
#define EQ 280
#define NOTEQ 281
#define LTEQ 282
#define GTEQ 283
#define ANDAND 284
#define OROR 285
#define COMMA 286
#define RETURN 287
#define READ 288
#define WRITE 289
#define CASE 290
#define DEFAULT 291
#define BREAK 292
#define QMARK 293
#define HAT 294
#define IN 295
#define ON 296
#define AS 297
#define INTO 298
#define DO 299
#define WHILE 300
#define IF 301
#define ELSE 302
#define TYPE 303
#define IDENTIFIER 304
#define NUMBER 305
#define EVAL 306
#define UNLESS 307
#define FOREACH 308
#define FOR 309
#define SWITCH 310
#define DOLLAR 311
#define AT 312
#define COND 313
#define MAP 314
#define REDUCE 315
#define NOT 316




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

t_list *condStack = NULL;

/* struct used for array comprehension */
struct ac {
  t_axe_label *l_cond;
  t_axe_label *l_body;
  int index;
} ac;



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
#line 112 "Acse.y"
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
   t_cond_statement *cond_stmt;
   t_map_statement map_stmt;
   t_reduce_statement reduce_stmt;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 329 "Acse.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 341 "Acse.tab.c"

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
#define YYLAST   1058

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  58
/* YYNRULES -- Number of rules. */
#define YYNRULES  119
/* YYNRULES -- Number of states. */
#define YYNSTATES  252

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   316

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
      55,    56,    57,    58,    59,    60,    61
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    14,    18,    20,    24,
      29,    31,    33,    37,    40,    42,    45,    47,    50,    52,
      54,    56,    58,    61,    63,    65,    68,    70,    73,    75,
      77,    80,    82,    84,    85,    89,    91,    98,   102,   103,
     104,   116,   118,   119,   124,   125,   126,   134,   135,   136,
     143,   144,   145,   153,   154,   162,   163,   164,   174,   175,
     176,   177,   178,   192,   193,   202,   204,   207,   210,   212,
     213,   219,   220,   226,   227,   232,   234,   235,   241,   243,
     246,   247,   255,   256,   257,   272,   274,   279,   284,   286,
     288,   293,   299,   302,   305,   309,   312,   314,   318,   322,
     326,   330,   334,   338,   342,   346,   350,   354,   358,   362,
     366,   370,   374,   378,   382,   385,   391,   395,   403,   407
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      63,     0,    -1,    64,    69,    -1,    64,    65,    -1,    -1,
      48,    66,     9,    -1,    66,    31,    67,    -1,    67,    -1,
      49,    19,    50,    -1,    49,     7,    50,     8,    -1,    49,
      -1,    70,    -1,     3,    69,     4,    -1,    69,    70,    -1,
      70,    -1,    74,     9,    -1,    71,    -1,    72,     9,    -1,
       9,    -1,    77,    -1,    82,    -1,    85,    -1,    88,     9,
      -1,    90,    -1,    93,    -1,   116,     9,    -1,    98,    -1,
     107,     9,    -1,   108,    -1,   111,    -1,   113,     9,    -1,
     117,    -1,   118,    -1,    -1,    73,    31,    74,    -1,    74,
      -1,    49,     7,   119,     8,    19,   119,    -1,    49,    19,
     119,    -1,    -1,    -1,    49,    19,    75,     7,   119,    76,
      54,    49,    40,    49,     8,    -1,    79,    -1,    -1,    79,
      47,    78,    68,    -1,    -1,    -1,    46,    80,     5,   119,
       6,    81,    68,    -1,    -1,    -1,    51,    83,    68,    84,
      52,   119,    -1,    -1,    -1,    45,    86,     5,   119,     6,
      87,    68,    -1,    -1,    44,    89,    68,    45,     5,   119,
       6,    -1,    -1,    -1,    53,    91,     5,    49,    10,    49,
       6,    92,    68,    -1,    -1,    -1,    -1,    -1,    54,    94,
       5,    73,     9,    95,   119,     9,    96,    73,     6,    97,
      68,    -1,    -1,    55,     5,    49,     6,     3,    99,   100,
       4,    -1,   101,    -1,   101,   105,    -1,   101,   102,    -1,
     102,    -1,    -1,    35,    50,    10,   103,    69,    -1,    -1,
      35,   119,    10,   104,    69,    -1,    -1,    36,    10,   106,
      69,    -1,    37,    -1,    -1,    58,     3,   109,   110,     4,
      -1,   101,    -1,   101,   105,    -1,    -1,    59,    49,    41,
      49,    42,   112,    68,    -1,    -1,    -1,    60,    49,    43,
      49,   114,    42,     7,     7,   119,     8,     8,   115,    41,
      49,    -1,    32,    -1,    33,     5,    49,     6,    -1,    34,
       5,   119,     6,    -1,    50,    -1,    49,    -1,    49,     7,
     119,     8,    -1,   119,    46,   119,    47,   119,    -1,    18,
      50,    -1,   119,    18,    -1,    17,   119,    17,    -1,    18,
      49,    -1,    74,    -1,   119,    16,   119,    -1,   119,    17,
     119,    -1,   119,    11,   119,    -1,   119,    12,   119,    -1,
     119,    13,   119,    -1,   119,    14,   119,    -1,   119,    21,
     119,    -1,   119,    22,   119,    -1,   119,    25,   119,    -1,
     119,    26,   119,    -1,   119,    27,   119,    -1,   119,    28,
     119,    -1,   119,    23,   119,    -1,   119,    24,   119,    -1,
     119,    29,   119,    -1,   119,    30,   119,    -1,     5,   119,
       6,    -1,    12,   119,    -1,   119,    56,   119,    57,   119,
      -1,   119,    15,   119,    -1,     5,   119,     6,    38,   119,
      10,   119,    -1,   119,    39,   119,    -1,    49,    20,    49,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   203,   203,   216,   217,   220,   227,   231,   238,   247,
     256,   270,   271,   275,   276,   281,   282,   283,   284,   287,
     288,   289,   290,   291,   292,   293,   294,   295,   296,   297,
     298,   301,   302,   305,   306,   307,   309,   315,   330,   340,
     330,   376,   382,   381,   401,   407,   400,   420,   428,   420,
     445,   454,   444,   482,   481,   504,   512,   503,   533,   534,
     536,   544,   533,   555,   555,   594,   597,   602,   602,   604,
     604,   612,   612,   634,   634,   640,   651,   651,   661,   661,
     663,   663,   703,   713,   703,   750,   757,   777,   796,   797,
     810,   823,   839,   844,   869,   888,   910,   911,   914,   917,
     920,   923,   926,   929,   932,   935,   938,   941,   944,   947,
     948,   949,   950,   951,   952,   970,  1013,  1020,  1050,  1080
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LBRACE", "RBRACE", "LPAR", "RPAR",
  "LSQUARE", "RSQUARE", "SEMI", "COLON", "PLUS", "MINUS", "MUL_OP",
  "DIV_OP", "MOD_OP", "AND_OP", "OR_OP", "NOT_OP", "ASSIGN", "EQARRAY",
  "LT", "GT", "SHL_OP", "SHR_OP", "EQ", "NOTEQ", "LTEQ", "GTEQ", "ANDAND",
  "OROR", "COMMA", "RETURN", "READ", "WRITE", "CASE", "DEFAULT", "BREAK",
  "QMARK", "HAT", "IN", "ON", "AS", "INTO", "DO", "WHILE", "IF", "ELSE",
  "TYPE", "IDENTIFIER", "NUMBER", "EVAL", "UNLESS", "FOREACH", "FOR",
  "SWITCH", "DOLLAR", "AT", "COND", "MAP", "REDUCE", "NOT", "$accept",
  "program", "var_declarations", "var_declaration", "declaration_list",
  "declaration", "code_block", "statements", "statement",
  "control_statement", "read_write_statement", "assign_list",
  "assign_statement", "@1", "@2", "if_statement", "@3", "if_stmt", "@4",
  "@5", "unless_statement", "@6", "@7", "while_statement", "@8", "@9",
  "do_while_statement", "@10", "foreach_statement", "@11", "@12",
  "for_statement", "@13", "@14", "@15", "@16", "switch_statement", "@17",
  "switch_block", "case_statements", "case_statement", "@18", "@19",
  "default_statement", "@20", "break_statement", "cond_statement", "@21",
  "cond_block", "map_statement", "@22", "reduce_statement", "@23", "@24",
  "return_statement", "read_statement", "write_statement", "exp", 0
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    62,    63,    64,    64,    65,    66,    66,    67,    67,
      67,    68,    68,    69,    69,    70,    70,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    75,    76,
      74,    77,    78,    77,    80,    81,    79,    83,    84,    82,
      86,    87,    85,    89,    88,    91,    92,    90,    94,    95,
      96,    97,    93,    99,    98,   100,   100,   101,   101,   103,
     102,   104,   102,   106,   105,   107,   109,   108,   110,   110,
     112,   111,   114,   115,   113,   116,   117,   118,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     2,     0,     3,     3,     1,     3,     4,
       1,     1,     3,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     2,     1,     1,     2,     1,     2,     1,     1,
       2,     1,     1,     0,     3,     1,     6,     3,     0,     0,
      11,     1,     0,     4,     0,     0,     7,     0,     0,     6,
       0,     0,     7,     0,     7,     0,     0,     9,     0,     0,
       0,     0,    13,     0,     8,     1,     2,     2,     1,     0,
       5,     0,     5,     0,     4,     1,     0,     5,     1,     2,
       0,     7,     0,     0,    14,     1,     4,     4,     1,     1,
       4,     5,     2,     2,     3,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     5,     3,     7,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       4,     0,     0,     1,    18,    85,     0,     0,    75,    53,
      50,    44,     0,     0,    47,    55,    58,     0,     0,     0,
       0,     3,     2,    14,    16,     0,     0,    19,    41,    20,
      21,     0,    23,    24,    26,     0,    28,    29,     0,     0,
      31,    32,     0,     0,     0,     0,     0,    10,     0,     7,
       0,    38,     0,     0,     0,     0,    76,     0,     0,    13,
      17,    15,    42,    22,    27,    30,    25,     0,     0,     0,
       0,     0,    89,    88,    96,     0,     0,     0,    11,     0,
       0,     0,     0,     5,     0,     0,     0,    37,    48,     0,
      33,     0,     0,     0,     0,     0,    86,     0,   114,     0,
      95,    92,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,    93,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     6,     0,     0,     0,     0,     0,    35,     0,
       0,    78,    68,     0,     0,    82,    43,   113,    94,     0,
     119,    99,   100,   101,   102,   116,    97,    98,   103,   104,
     109,   110,   105,   106,   107,   108,   111,   112,   118,     0,
       0,    12,     0,    51,    45,     9,     0,    39,     0,     0,
      59,     0,    63,    88,     0,     0,    67,    79,    77,    80,
       0,     0,    90,     0,     0,     0,     0,     0,    36,     0,
      49,     0,     0,    34,     0,    69,    71,    73,     0,     0,
       0,    91,   115,    54,    52,    46,     0,    56,     0,     0,
      65,     0,     0,     0,    81,     0,     0,     0,     0,    60,
      64,    66,    70,    72,    74,     0,   117,     0,    57,    33,
       0,     0,     0,     0,    40,    61,    83,     0,     0,    62,
       0,    84
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,    21,    48,    49,    77,    22,    78,    24,
      25,   137,    74,    86,   199,    27,    95,    28,    46,   197,
      29,    52,   135,    30,    45,   196,    31,    44,    32,    53,
     228,    33,    54,   202,   239,   247,    34,   204,   219,   141,
     142,   221,   222,   187,   223,    35,    36,    92,   143,    37,
     208,    38,   190,   248,    39,    40,    41,   157
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -138
static const short int yypact[] =
{
    -138,     7,    77,  -138,  -138,  -138,     4,     8,  -138,  -138,
    -138,  -138,   -20,     3,  -138,  -138,  -138,    27,    30,   -11,
      -8,  -138,   107,  -138,  -138,    34,    54,  -138,    20,  -138,
    -138,    62,  -138,  -138,  -138,    63,  -138,  -138,    66,    69,
    -138,  -138,    35,     9,     2,    49,    87,     5,    -1,  -138,
       9,     9,     2,    92,    93,    50,  -138,    60,    59,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,    97,     9,     9,
       9,   -33,    45,  -138,  -138,   279,   107,    67,  -138,     9,
       9,    55,    56,  -138,   -20,   484,   101,   775,  -138,    64,
      70,    98,    80,    71,    84,     2,  -138,   340,  1002,   811,
    -138,  -138,     9,    85,  -138,     9,     9,     9,     9,     9,
       9,     9,  -138,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,    36,   113,   376,   412,
     121,  -138,  -138,   119,     9,    90,   133,     6,  -138,   147,
     231,   -17,  -138,   150,   117,  -138,  -138,   125,     9,   520,
    -138,  1002,  1002,    61,    61,   775,   955,   919,   158,   158,
     994,   994,   975,   975,   158,   158,   883,   847,   775,   738,
     628,  -138,     9,  -138,  -138,  -138,     9,   775,     9,   106,
    -138,    70,  -138,   154,   665,   164,  -138,  -138,  -138,  -138,
     126,     9,   119,     9,     9,   448,     2,     2,   775,   124,
     775,   169,     9,  -138,    80,  -138,  -138,  -138,     2,   173,
     702,    10,   775,  -138,  -138,  -138,   134,  -138,   592,   180,
     -17,   107,   107,   107,  -138,   178,     9,   146,     2,  -138,
    -138,  -138,   107,   107,   107,     9,   775,   138,  -138,    70,
     556,   181,     0,   182,  -138,  -138,  -138,     2,   151,  -138,
     139,  -138
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -138,  -138,  -138,  -138,  -138,   109,   -51,   -74,     1,  -138,
    -138,   -39,    -2,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,    -3,
    -137,  -138,  -138,   -18,  -138,  -138,  -138,  -138,  -138,  -138,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,   148
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned char yytable[] =
{
      26,    88,   126,    23,   186,    76,   245,     3,    83,    42,
      50,     4,    81,    43,    68,   180,   100,   101,   140,   185,
      26,    69,    51,    59,    82,   109,    70,    71,   112,    47,
      84,   181,    55,    56,     5,     6,     7,   181,    57,     8,
     171,    58,    26,    60,   146,     4,     9,    10,    11,   123,
      26,    13,   102,    14,    79,    15,    16,    17,    72,    73,
      18,    19,    20,    61,    51,   103,   125,    62,     5,     6,
       7,    63,    64,     8,    26,    65,   109,    23,    66,   112,
       9,    10,    11,   186,    67,    13,     4,    14,   138,    15,
      16,    17,    80,    26,    18,    19,    20,    89,    90,    91,
     123,    93,    94,    96,   139,   130,   131,   124,   134,     5,
       6,     7,   127,   136,     8,   140,     4,   125,   172,    13,
     144,     9,    10,    11,    26,    12,    13,    59,    14,   175,
      15,    16,    17,   145,   150,    18,    19,    20,   176,     5,
       6,     7,   178,   179,     8,   214,   215,   232,   233,   234,
     182,     9,    10,    11,   188,   201,    13,   224,    14,   189,
      15,    16,    17,   191,   205,    18,    19,    20,   209,   105,
     106,   107,   108,   109,   207,   217,   112,   238,   216,   203,
     225,   115,   116,   227,   230,   235,   237,   241,   251,   244,
     246,    75,   250,   132,    26,    26,   249,   123,    85,    87,
     242,   220,   231,     0,   124,     0,    26,     0,     0,     0,
       0,     0,     0,     0,   125,     0,    97,    98,    99,    26,
      26,    26,    23,    23,    23,     0,    26,   128,   129,     0,
      26,    26,    26,    59,    59,    59,    68,   138,     0,     0,
       0,     0,     0,    69,     0,    26,     0,     0,    70,    71,
     149,     0,     0,   151,   152,   153,   154,   155,   156,     0,
       0,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,     0,     0,     0,     0,     0,     0,
      72,   183,   177,     0,     0,   104,     0,     0,   184,     0,
     105,   106,   107,   108,   109,   110,   111,   112,     0,     0,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0,
     195,     0,     0,     0,   198,   124,   200,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,     0,   210,
       0,   211,   212,     0,     0,     0,   147,     0,     0,     0,
     218,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,   236,     0,     0,     0,     0,   123,
       0,     0,   173,   240,     0,     0,   124,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   125,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,   174,     0,
       0,     0,   124,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   125,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,   213,     0,     0,     0,   124,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   125,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,   133,     0,   124,   105,   106,   107,   108,   109,
     110,   111,   112,     0,   125,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,   192,     0,
     124,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     125,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,     0,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,   243,     0,   124,   105,   106,   107,
     108,   109,   110,   111,   112,     0,   125,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,   229,   124,   105,   106,   107,   108,   109,   110,   111,
     112,     0,   125,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,   124,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   125,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,   124,   206,   105,   106,   107,   108,
     109,   110,   111,   112,   125,   194,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,   124,   226,   105,   106,   107,   108,   109,   110,   111,
     112,   125,     0,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,     0,     0,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,   124,   105,
     106,   107,   108,   109,   110,   111,   112,     0,   125,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,   124,   193,   105,   106,   107,   108,
     109,   110,   111,   112,   125,     0,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,     0,     0,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,   124,   105,   106,   107,   108,   109,   110,   148,   112,
       0,   125,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,     0,     0,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,   124,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   125,   113,   114,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,   124,   105,   106,   107,   108,   109,   110,
     111,   112,     0,   125,   113,   114,   115,   116,   117,   118,
     119,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,   124,
     105,   106,   107,   108,   109,   110,     0,   112,     0,   125,
     113,   114,   115,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,   124,   105,   106,   107,   108,
     109,     0,     0,   112,     0,   125,   113,   114,   115,   116,
     117,   118,   119,   120,     0,     0,   105,   106,   107,   108,
     109,     0,     0,   112,   123,     0,   113,   114,   115,   116,
       0,   124,   119,   120,     0,   105,   106,   107,   108,   109,
       0,   125,   112,     0,   123,   107,   108,   109,     0,     0,
     112,   124,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   125,     0,   123,     0,     0,     0,     0,     0,     0,
     124,   123,     0,     0,     0,     0,     0,     0,   124,     0,
     125,     0,     0,     0,     0,     0,     0,     0,   125
};

static const short int yycheck[] =
{
       2,    52,    76,     2,   141,     3,     6,     0,     9,     5,
       7,     9,     7,     5,     5,     9,    49,    50,    35,    36,
      22,    12,    19,    22,    19,    15,    17,    18,    18,    49,
      31,    31,     5,     3,    32,    33,    34,    31,    49,    37,
       4,    49,    44,     9,    95,     9,    44,    45,    46,    39,
      52,    49,     7,    51,     5,    53,    54,    55,    49,    50,
      58,    59,    60,     9,    19,    20,    56,    47,    32,    33,
      34,     9,     9,    37,    76,     9,    15,    76,     9,    18,
      44,    45,    46,   220,    49,    49,     9,    51,    90,    53,
      54,    55,     5,    95,    58,    59,    60,     5,     5,    49,
      39,    41,    43,     6,     6,    50,    50,    46,     7,    32,
      33,    34,    45,    49,    37,    35,     9,    56,     5,    49,
      49,    44,    45,    46,   126,    48,    49,   126,    51,     8,
      53,    54,    55,    49,    49,    58,    59,    60,    19,    32,
      33,    34,    52,    10,    37,   196,   197,   221,   222,   223,
       3,    44,    45,    46,     4,    49,    49,   208,    51,    42,
      53,    54,    55,    38,    10,    58,    59,    60,    42,    11,
      12,    13,    14,    15,    10,     6,    18,   228,    54,   181,
       7,    23,    24,    49,     4,     7,    40,    49,    49,     8,
       8,    43,    41,    84,   196,   197,   247,    39,    50,    51,
     239,   204,   220,    -1,    46,    -1,   208,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    68,    69,    70,   221,
     222,   223,   221,   222,   223,    -1,   228,    79,    80,    -1,
     232,   233,   234,   232,   233,   234,     5,   239,    -1,    -1,
      -1,    -1,    -1,    12,    -1,   247,    -1,    -1,    17,    18,
     102,    -1,    -1,   105,   106,   107,   108,   109,   110,    -1,
      -1,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,   134,    -1,    -1,     6,    -1,    -1,   140,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    -1,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
     172,    -1,    -1,    -1,   176,    46,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,   191,
      -1,   193,   194,    -1,    -1,    -1,     6,    -1,    -1,    -1,
     202,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    39,
      -1,    -1,     6,   235,    -1,    -1,    46,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    56,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,     6,    -1,
      -1,    -1,    46,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    56,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,     6,    -1,    -1,    -1,    46,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    56,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,     8,    -1,    46,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    56,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,     8,    -1,
      46,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      56,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,     8,    -1,    46,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    56,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,     9,    46,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    56,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    56,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    56,    57,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    56,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    56,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    11,    12,    13,    14,
      15,    16,    17,    18,    56,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    56,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    56,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    56,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      11,    12,    13,    14,    15,    16,    -1,    18,    -1,    56,
      21,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    11,    12,    13,    14,
      15,    -1,    -1,    18,    -1,    56,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    11,    12,    13,    14,
      15,    -1,    -1,    18,    39,    -1,    21,    22,    23,    24,
      -1,    46,    27,    28,    -1,    11,    12,    13,    14,    15,
      -1,    56,    18,    -1,    39,    13,    14,    15,    -1,    -1,
      18,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    63,    64,     0,     9,    32,    33,    34,    37,    44,
      45,    46,    48,    49,    51,    53,    54,    55,    58,    59,
      60,    65,    69,    70,    71,    72,    74,    77,    79,    82,
      85,    88,    90,    93,    98,   107,   108,   111,   113,   116,
     117,   118,     5,     5,    89,    86,    80,    49,    66,    67,
       7,    19,    83,    91,    94,     5,     3,    49,    49,    70,
       9,     9,    47,     9,     9,     9,     9,    49,     5,    12,
      17,    18,    49,    50,    74,   119,     3,    68,    70,     5,
       5,     7,    19,     9,    31,   119,    75,   119,    68,     5,
       5,    49,   109,    41,    43,    78,     6,   119,   119,   119,
      49,    50,     7,    20,     6,    11,    12,    13,    14,    15,
      16,    17,    18,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    39,    46,    56,    69,    45,   119,   119,
      50,    50,    67,     8,     7,    84,    49,    73,    74,     6,
      35,   101,   102,   110,    49,    49,    68,     6,    17,   119,
      49,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     119,     4,     5,     6,     6,     8,    19,   119,    52,    10,
       9,    31,     3,    50,   119,    36,   102,   105,     4,    42,
     114,    38,     8,    47,    57,   119,    87,    81,   119,    76,
     119,    49,    95,    74,    99,    10,    10,    10,   112,    42,
     119,   119,   119,     6,    68,    68,    54,     6,   119,   100,
     101,   103,   104,   106,    68,     7,    10,    49,    92,     9,
       4,   105,    69,    69,    69,     7,   119,    40,    68,    96,
     119,    49,    73,     8,     8,     6,     8,    97,   115,    68,
      41,    49
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
#line 204 "Acse.y"
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
#line 216 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 4:
#line 217 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 5:
#line 221 "Acse.y"
    {
                     /* update the program infos by adding new variables */
                     set_new_variables(program, (yyvsp[-2].intval), (yyvsp[-1].list));
                  ;}
    break;

  case 6:
#line 228 "Acse.y"
    {  /* add the new declaration to the list of declarations */
                     (yyval.list) = addElement((yyvsp[-2].list), (yyvsp[0].decl), -1);
                  ;}
    break;

  case 7:
#line 232 "Acse.y"
    {
                     /* add the new declaration to the list of declarations */
                     (yyval.list) = addElement(NULL, (yyvsp[0].decl), -1);
                  ;}
    break;

  case 8:
#line 239 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[-2].svalue), 0, 0, (yyvsp[0].intval));

               /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 9:
#line 248 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[-3].svalue), 1, (yyvsp[-1].intval), 0);

                  /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 10:
#line 257 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[0].svalue), 0, 0, 0);
               
               /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 11:
#line 270 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 12:
#line 271 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 13:
#line 275 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 14:
#line 276 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 15:
#line 281 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 16:
#line 282 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 17:
#line 283 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 18:
#line 284 "Acse.y"
    { gen_nop_instruction(program); ;}
    break;

  case 19:
#line 287 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 20:
#line 288 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 21:
#line 289 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 22:
#line 290 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 23:
#line 291 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 24:
#line 292 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 25:
#line 293 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 26:
#line 294 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 27:
#line 295 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 28:
#line 296 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 29:
#line 297 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 30:
#line 298 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 31:
#line 301 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 32:
#line 302 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 33:
#line 305 "Acse.y"
    {;}
    break;

  case 34:
#line 306 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 35:
#line 307 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 36:
#line 310 "Acse.y"
    {
               storeArrayElement(program, (yyvsp[-5].svalue), (yyvsp[-3].expr), (yyvsp[0].expr));
			   (yyval.expr) = create_expression((yyvsp[0].expr).value, IMMEDIATE);
               free((yyvsp[-5].svalue));
            ;}
    break;

  case 37:
#line 316 "Acse.y"
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

  case 38:
#line 330 "Acse.y"
    {
               /* Init the gloabal struct */
               ac.l_cond = newLabel(program);
               ac.l_body = newLabel(program);
               ac.index = gen_load_immediate(program, 0);
               

               gen_bt_instruction(program, ac.l_cond, 0);

               assignLabel(program, ac.l_body);
             ;}
    break;

  case 39:
#line 340 "Acse.y"
    {

               /* $1[i] = exp_i */
               storeArrayElement(program, (yyvsp[-4].svalue), create_expression(ac.index, REGISTER), (yyvsp[0].expr));
               gen_addi_instruction(program, ac.index, ac.index, 1); 

             ;}
    break;

  case 40:
#line 346 "Acse.y"
    {
               t_axe_label *l_end = newLabel(program);

               t_axe_variable *src = getVariable(program, (yyvsp[-1].svalue));
               t_axe_variable *dest = getVariable(program, (yyvsp[-10].svalue));
               
               if(!src->isArray || !dest->isArray)
                 exit(-1);


               /* check if ac.index is equal to $10->arraySize and eventually finish */
               t_axe_expression min_size = create_expression(dest->arraySize < src->arraySize ? dest->arraySize : src->arraySize, IMMEDIATE);
               int iv_reg = get_symbol_location(program, (yyvsp[-3].svalue), 0);
               t_axe_expression index_expr = create_expression(ac.index, REGISTER);

               assignLabel(program, ac.l_cond); 
               t_axe_expression cmp = handle_binary_comparison(program, index_expr, min_size, _LT_); 
               gen_beq_instruction(program, l_end, 0);
               
               int elem = loadArrayElement(program, (yyvsp[-1].svalue), index_expr); 
               gen_addi_instruction(program, iv_reg, elem, 0);
               gen_bt_instruction(program, ac.l_body, 0); 
               assignLabel(program, l_end);
               free((yyvsp[-10].svalue));
               free((yyvsp[-3].svalue));
               free((yyvsp[-1].svalue));
             ;}
    break;

  case 41:
#line 377 "Acse.y"
    {
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[0].label));
               ;}
    break;

  case 42:
#line 382 "Acse.y"
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

  case 43:
#line 394 "Acse.y"
    {
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[-2].label));
               ;}
    break;

  case 44:
#line 401 "Acse.y"
    {
                  /* the label that points to the address where to jump if
                   * `exp' is not verified */
                  (yyvsp[0].label) = newLabel(program);
               ;}
    break;

  case 45:
#line 407 "Acse.y"
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

  case 46:
#line 417 "Acse.y"
    { (yyval.label) = (yyvsp[-6].label); ;}
    break;

  case 47:
#line 420 "Acse.y"
    {
				(yyvsp[0].unless_stmt) = create_unless_statement();
				(yyvsp[0].unless_stmt).condition = newLabel(program);
				(yyvsp[0].unless_stmt).code_block = newLabel(program);
				(yyvsp[0].unless_stmt).end = newLabel(program);
				gen_bt_instruction(program, (yyvsp[0].unless_stmt).condition, 0);
				assignLabel(program, (yyvsp[0].unless_stmt).code_block);
			;}
    break;

  case 48:
#line 428 "Acse.y"
    {
				gen_bt_instruction(program, (yyvsp[-2].unless_stmt).end, 0);
				assignLabel(program, (yyvsp[-2].unless_stmt).condition);
			;}
    break;

  case 49:
#line 432 "Acse.y"
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

  case 50:
#line 445 "Acse.y"
    {
                     /* initialize the value of the non-terminal */
                     (yyvsp[0].while_stmt) = create_while_statement();

                     /* reserve and fix a new label */
                     (yyvsp[0].while_stmt).label_condition
                           = assignNewLabel(program);
                  ;}
    break;

  case 51:
#line 454 "Acse.y"
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

  case 52:
#line 470 "Acse.y"
    {
                     /* jump to the beginning of the loop */
                     gen_bt_instruction
                           (program, (yyvsp[-6].while_stmt).label_condition, 0);

                     /* fix the label `label_end' */
                     assignLabel(program, (yyvsp[-6].while_stmt).label_end);

                  ;}
    break;

  case 53:
#line 482 "Acse.y"
    {
                        /* the label that points to the address where to jump if
                         * `exp' is not verified */
                        (yyvsp[0].label) = newLabel(program);
                        
                        /* fix the label */
                        assignLabel(program, (yyvsp[0].label));
                     ;}
    break;

  case 54:
#line 491 "Acse.y"
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

  case 55:
#line 504 "Acse.y"
    {
				(yyvsp[0].foreach_stmt).counter = getNewRegister(program);
				gen_addi_instruction(program, (yyvsp[0].foreach_stmt).counter, REG_0, 0);
				(yyvsp[0].foreach_stmt).iteration = newLabel(program);
				(yyvsp[0].foreach_stmt).end = newLabel(program);
				assignLabel(program, (yyvsp[0].foreach_stmt).iteration);
			;}
    break;

  case 56:
#line 512 "Acse.y"
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

  case 57:
#line 526 "Acse.y"
    {
				gen_addi_instruction(program, (yyvsp[-8].foreach_stmt).counter, (yyvsp[-8].foreach_stmt).counter, 1);
				gen_bt_instruction(program, (yyvsp[-8].foreach_stmt).iteration, 0);
				assignLabel(program, (yyvsp[-8].foreach_stmt).end);
			;}
    break;

  case 58:
#line 533 "Acse.y"
    { (yyvsp[0].for_stmt) = create_for_statement();;}
    break;

  case 59:
#line 534 "Acse.y"
    {(yyvsp[-4].for_stmt).label_exp = assignNewLabel(program);;}
    break;

  case 60:
#line 536 "Acse.y"
    {
          (yyvsp[-7].for_stmt).label_end = newLabel(program);
          gen_beq_instruction(program, (yyvsp[-7].for_stmt).label_end, 0);
          (yyvsp[-7].for_stmt).label_code = newLabel(program);
          gen_bt_instruction(program, (yyvsp[-7].for_stmt).label_code, 0);
          (yyvsp[-7].for_stmt).label_epilogue = assignNewLabel(program);
        ;}
    break;

  case 61:
#line 544 "Acse.y"
    {
          gen_bt_instruction(program, (yyvsp[-10].for_stmt).label_exp, 0);
          assignLabel(program, (yyvsp[-10].for_stmt).label_code);
        ;}
    break;

  case 62:
#line 549 "Acse.y"
    {
          gen_bt_instruction(program, (yyvsp[-12].for_stmt).label_epilogue, 0);
          assignLabel(program, (yyvsp[-12].for_stmt).label_end);
        ;}
    break;

  case 63:
#line 555 "Acse.y"
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

  case 64:
#line 569 "Acse.y"
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

  case 65:
#line 594 "Acse.y"
    {
					gen_bt_instruction(program, ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->switch_end, 0);
				;}
    break;

  case 66:
#line 597 "Acse.y"
    {
					gen_bt_instruction(program, ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->switch_end, 0);
				;}
    break;

  case 69:
#line 604 "Acse.y"
    {
          /* allocate memory for the test_case */
					t_case_statement *c = (t_case_statement *)malloc(sizeof(t_case_statement));
					c->number = (yyvsp[-1].intval); // assign number to c
					c->begin_case = assignNewLabel(program);
					/* update list of cases with c as last element */
          ((t_switch_statement *)LDATA(getElementAt(switchStack, 0)))->cases = addLast(((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->cases, c);
				;}
    break;

  case 71:
#line 612 "Acse.y"
    {
          /* checko if expression type and if the exp is true or false */ 
          if ((yyvsp[-1].expr).expression_type == IMMEDIATE)
            gen_load_immediate(program, (yyvsp[-1].expr).value);
          else
            gen_andb_instruction(program, (yyvsp[-1].expr).value, (yyvsp[-1].expr).value, (yyvsp[-1].expr).value, CG_DIRECT_ALL);

          t_axe_label *l = newLabel(program);
          ((t_cond_statement*)LDATA(getElementAt(condStack, 0)))->l_next = l;

          /* if exp is false jump to next case */
          gen_beq_instruction(program, l, 0);

        ;}
    break;

  case 72:
#line 625 "Acse.y"
    {

          /* this instruction is reached if the exp has been evaluated to true */
          gen_bt_instruction(program, ((t_cond_statement*)LDATA(getElementAt(condStack,0)))->l_end, 0);
          
          assignLabel(program, ((t_cond_statement*)LDATA(getElementAt(condStack, 0)))->l_next);
        ;}
    break;

  case 73:
#line 634 "Acse.y"
    {
          if(switchStack!=NULL) // I might be in the cond statement case
            ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->default_label = assignNewLabel(program);
					;}
    break;

  case 75:
#line 640 "Acse.y"
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

  case 76:
#line 651 "Acse.y"
    {
                      (yyvsp[-1].cond_stmt) = (t_cond_statement *)malloc(sizeof(t_cond_statement));
                      (yyvsp[-1].cond_stmt)->l_end = newLabel(program);
                      condStack = addFirst(condStack, (yyvsp[-1].cond_stmt));
                  ;}
    break;

  case 77:
#line 655 "Acse.y"
    {
                      assignLabel(program, (yyvsp[-4].cond_stmt)->l_end);
                      condStack = removeFirst(condStack);
                  ;}
    break;

  case 80:
#line 663 "Acse.y"
    {
                t_axe_variable *array = getVariable(program, (yyvsp[-1].svalue));
                int cmp = getNewRegister(program);
                (yyvsp[-4].map_stmt).index = gen_load_immediate(program, 0);
                (yyvsp[-4].map_stmt).l_end = newLabel(program);

                if(!array->isArray) exit(-1);

                /* lookup the symbol table and fetch the register location
                * associated with the IDENTIFIER $2. */
                int elem = get_symbol_location(program, (yyvsp[-3].svalue), 0);

                (yyvsp[-4].map_stmt).l_iter = assignNewLabel(program);

                /* check if the index has reached the size of the array and jump to end */
                gen_subi_instruction(program, cmp, (yyvsp[-4].map_stmt).index, array->arraySize);
                gen_beq_instruction(program, (yyvsp[-4].map_stmt).l_end, 0);

                /* load the value of array[i] into elem */
                t_axe_expression idx = create_expression((yyvsp[-4].map_stmt).index, REGISTER);
                gen_addi_instruction(program, elem, loadArrayElement(program, (yyvsp[-1].svalue), idx), 0);
              
              ;}
    break;

  case 81:
#line 685 "Acse.y"
    {

                /* reload the location of elem */
                int elem = get_symbol_location(program, (yyvsp[-5].svalue), 0);
                t_axe_expression idx = create_expression((yyvsp[-6].map_stmt).index, REGISTER);

                /* store the UPDATED value of elem into the array */
                storeArrayElement(program, (yyvsp[-3].svalue), idx, create_expression(elem, REGISTER));

                gen_addi_instruction(program, (yyvsp[-6].map_stmt).index, (yyvsp[-6].map_stmt).index, 1);
                gen_bt_instruction(program, (yyvsp[-6].map_stmt).l_iter, 0);

                assignLabel(program, (yyvsp[-6].map_stmt).l_end);
                free((yyvsp[-5].svalue));
                free((yyvsp[-3].svalue));
              ;}
    break;

  case 82:
#line 703 "Acse.y"
    {
                      /* init reduce structure */
                      (yyvsp[-3].reduce_stmt).l_cond = newLabel(program);
                      (yyvsp[-3].reduce_stmt).l_end = newLabel(program);
                      (yyvsp[-3].reduce_stmt).counter = gen_load_immediate(program, 0);
                      /* go to the vector and add the variable to the structure */
                      gen_bt_instruction(program, (yyvsp[-3].reduce_stmt).l_cond, 0);
                      
                      (yyvsp[-3].reduce_stmt).l_exp = assignNewLabel(program);

                    ;}
    break;

  case 83:
#line 713 "Acse.y"
    {

                      int res = get_symbol_location(program, (yyvsp[-7].svalue), 0);
                      /* update the current result with the new exp value */
                      if((yyvsp[-2].expr).expression_type == IMMEDIATE)
                        gen_addi_instruction(program, res, REG_0, (yyvsp[-2].expr).value);
                      else
                        gen_addi_instruction(program, res, (yyvsp[-2].expr).value, 0);

                      /* update the counter and end if array size is reached */
                      gen_addi_instruction(program, (yyvsp[-10].reduce_stmt).counter, (yyvsp[-10].reduce_stmt).counter, 1);
                      
                    ;}
    break;

  case 84:
#line 725 "Acse.y"
    {
                      assignLabel(program, (yyvsp[-13].reduce_stmt).l_cond);
                      t_axe_variable *array = getVariable(program, (yyvsp[0].svalue));
                      if(!array->isArray) exit(-1);
                      
                      /* check if the counter has reached the array size and end */
                      int cmp = getNewRegister(program);
                      gen_subi_instruction(program, cmp, (yyvsp[-13].reduce_stmt).counter, array->arraySize);
                      gen_beq_instruction(program, (yyvsp[-13].reduce_stmt).l_end, 0);

                      /* load elem location */
                      int elem = get_symbol_location(program, (yyvsp[-12].svalue), 0);
                      /* elem = array[counter] */
                      t_axe_expression idx = create_expression((yyvsp[-13].reduce_stmt).counter, REGISTER);
                      gen_addi_instruction(program, elem, loadArrayElement(program, (yyvsp[0].svalue), idx), 0);

                      /* jump to evaluating expression */
                      gen_bt_instruction(program, (yyvsp[-13].reduce_stmt).l_exp, 0);

                      assignLabel(program, (yyvsp[-13].reduce_stmt).l_end );
                      free((yyvsp[-12].svalue));
                      free((yyvsp[-10].svalue));
                      free((yyvsp[0].svalue));
                    ;}
    break;

  case 85:
#line 751 "Acse.y"
    {
               /* insert an HALT instruction */
               gen_halt_instruction(program);
            ;}
    break;

  case 86:
#line 758 "Acse.y"
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

  case 87:
#line 778 "Acse.y"
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

  case 88:
#line 796 "Acse.y"
    { (yyval.expr) = create_expression ((yyvsp[0].intval), IMMEDIATE); ;}
    break;

  case 89:
#line 797 "Acse.y"
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

  case 90:
#line 810 "Acse.y"
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

  case 91:
#line 823 "Acse.y"
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

  case 92:
#line 839 "Acse.y"
    {  if ((yyvsp[0].intval) == 0)
                           (yyval.expr) = create_expression (1, IMMEDIATE);
                        else
                           (yyval.expr) = create_expression (0, IMMEDIATE);
   ;}
    break;

  case 93:
#line 844 "Acse.y"
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

  case 94:
#line 869 "Acse.y"
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

  case 95:
#line 888 "Acse.y"
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

  case 96:
#line 910 "Acse.y"
    {;}
    break;

  case 97:
#line 911 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ANDB);
   ;}
    break;

  case 98:
#line 914 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ORB);
   ;}
    break;

  case 99:
#line 917 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ADD);
   ;}
    break;

  case 100:
#line 920 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SUB);
   ;}
    break;

  case 101:
#line 923 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), MUL);
   ;}
    break;

  case 102:
#line 926 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), DIV);
   ;}
    break;

  case 103:
#line 929 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _LT_);
   ;}
    break;

  case 104:
#line 932 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _GT_);
   ;}
    break;

  case 105:
#line 935 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _EQ_);
   ;}
    break;

  case 106:
#line 938 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _NOTEQ_);
   ;}
    break;

  case 107:
#line 941 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _LTEQ_);
   ;}
    break;

  case 108:
#line 944 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _GTEQ_);
   ;}
    break;

  case 109:
#line 947 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SHL); ;}
    break;

  case 110:
#line 948 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SHR); ;}
    break;

  case 111:
#line 949 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ANDL); ;}
    break;

  case 112:
#line 950 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ORL); ;}
    break;

  case 113:
#line 951 "Acse.y"
    { (yyval.expr) = (yyvsp[-1].expr); ;}
    break;

  case 114:
#line 952 "Acse.y"
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

  case 115:
#line 970 "Acse.y"
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

  case 116:
#line 1013 "Acse.y"
    {
          int q_reg = getNewRegister(program);
          t_axe_expression q = create_expression(q_reg, REGISTER); // Quotient of the division

          q = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), DIV); // d <- a / b (integer)
          (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), handle_bin_numeric_op(program, (yyvsp[0].expr), q, MUL), SUB);
  ;}
    break;

  case 117:
#line 1020 "Acse.y"
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

  case 118:
#line 1050 "Acse.y"
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

  case 119:
#line 1080 "Acse.y"
    {
    t_axe_variable *id1 = getVariable(program, (yyvsp[-2].svalue));
    if(!id1->isArray) exit(-1);

    t_axe_variable *id2 = getVariable(program, (yyvsp[0].svalue));
    if(!id2->isArray) exit(-1);

    if(id1->arraySize != id2->arraySize)
      (yyval.expr) = create_expression(0, IMMEDIATE);

    else{
      int idx = id1->arraySize;
      int e1 = getNewRegister(program); // later used to store elements from first array
      int e2 = getNewRegister(program); // later used to store elements from second array

      t_axe_label *l_end = newLabel(program);
      t_axe_label *l_diff = newLabel(program); // label used in case the two array are different
      t_axe_label *l_iter = assignNewLabel(program);

      e1 = loadArrayElement(program, (yyvsp[-2].svalue), create_expression(idx, IMMEDIATE));
      e2 = loadArrayElement(program, (yyvsp[0].svalue), create_expression(idx, IMMEDIATE));

      gen_sub_instruction(program, e1, e1, e2, CG_DIRECT_ALL);
      
      /* if it is not zero e1 != e2 */
      gen_bne_instruction(program, l_diff, 0);

      gen_subi_instruction(program, idx, idx, 1);

      gen_bne_instruction(program, l_iter, 0);

      (yyval.expr) = create_expression(0, IMMEDIATE); // true
      gen_bt_instruction(program, l_end, 0);

      assignLabel(program, l_diff);
      (yyval.expr) = create_expression(1, IMMEDIATE); // false

      assignLabel(program, l_end);
      
    }

  ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 3001 "Acse.tab.c"

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


#line 1123 "Acse.y"

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

