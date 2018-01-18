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
     DEFINE = 299,
     DO = 300,
     WHILE = 301,
     IF = 302,
     ELSE = 303,
     TYPE = 304,
     IDENTIFIER = 305,
     NUMBER = 306,
     EVAL = 307,
     UNLESS = 308,
     FOREACH = 309,
     FOR = 310,
     SWITCH = 311,
     DOLLAR = 312,
     AT = 313,
     COND = 314,
     MAP = 315,
     REDUCE = 316,
     NOT = 317
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
#define DEFINE 299
#define DO 300
#define WHILE 301
#define IF 302
#define ELSE 303
#define TYPE 304
#define IDENTIFIER 305
#define NUMBER 306
#define EVAL 307
#define UNLESS 308
#define FOREACH 309
#define FOR 310
#define SWITCH 311
#define DOLLAR 312
#define AT 313
#define COND 314
#define MAP 315
#define REDUCE 316
#define NOT 317




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

t_list *defines = NULL;
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
#line 113 "Acse.y"
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
#line 332 "Acse.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 344 "Acse.tab.c"

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
#define YYLAST   1070

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  60
/* YYNRULES -- Number of rules. */
#define YYNRULES  124
/* YYNRULES -- Number of states. */
#define YYNSTATES  260

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     7,    10,    11,    15,    18,    19,    23,
      27,    29,    33,    38,    40,    44,    49,    51,    55,    58,
      60,    63,    65,    68,    70,    72,    74,    76,    79,    81,
      83,    86,    88,    91,    93,    95,    98,   100,   102,   103,
     107,   109,   116,   120,   121,   122,   134,   136,   137,   142,
     143,   144,   152,   153,   154,   161,   162,   163,   171,   172,
     180,   181,   182,   192,   193,   194,   195,   196,   210,   211,
     220,   222,   225,   228,   230,   231,   237,   238,   244,   245,
     250,   252,   253,   259,   261,   264,   265,   273,   274,   275,
     290,   292,   297,   302,   304,   306,   311,   317,   320,   323,
     327,   330,   332,   336,   340,   344,   348,   352,   356,   360,
     364,   368,   372,   376,   380,   384,   388,   392,   396,   400,
     403,   409,   413,   421,   425
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      64,     0,    -1,    65,    67,    72,    -1,    65,    66,    -1,
      -1,    44,    50,    51,    -1,    67,    68,    -1,    -1,    49,
      69,     9,    -1,    69,    31,    70,    -1,    70,    -1,    50,
      19,    51,    -1,    50,     7,    51,     8,    -1,    50,    -1,
      50,    19,    50,    -1,    50,     7,    50,     8,    -1,    73,
      -1,     3,    72,     4,    -1,    72,    73,    -1,    73,    -1,
      77,     9,    -1,    74,    -1,    75,     9,    -1,     9,    -1,
      80,    -1,    85,    -1,    88,    -1,    91,     9,    -1,    93,
      -1,    96,    -1,   119,     9,    -1,   101,    -1,   110,     9,
      -1,   111,    -1,   114,    -1,   116,     9,    -1,   120,    -1,
     121,    -1,    -1,    76,    31,    77,    -1,    77,    -1,    50,
       7,   122,     8,    19,   122,    -1,    50,    19,   122,    -1,
      -1,    -1,    50,    19,    78,     7,   122,    79,    55,    50,
      40,    50,     8,    -1,    82,    -1,    -1,    82,    48,    81,
      71,    -1,    -1,    -1,    47,    83,     5,   122,     6,    84,
      71,    -1,    -1,    -1,    52,    86,    71,    87,    53,   122,
      -1,    -1,    -1,    46,    89,     5,   122,     6,    90,    71,
      -1,    -1,    45,    92,    71,    46,     5,   122,     6,    -1,
      -1,    -1,    54,    94,     5,    50,    10,    50,     6,    95,
      71,    -1,    -1,    -1,    -1,    -1,    55,    97,     5,    76,
       9,    98,   122,     9,    99,    76,     6,   100,    71,    -1,
      -1,    56,     5,    50,     6,     3,   102,   103,     4,    -1,
     104,    -1,   104,   108,    -1,   104,   105,    -1,   105,    -1,
      -1,    35,    51,    10,   106,    72,    -1,    -1,    35,   122,
      10,   107,    72,    -1,    -1,    36,    10,   109,    72,    -1,
      37,    -1,    -1,    59,     3,   112,   113,     4,    -1,   104,
      -1,   104,   108,    -1,    -1,    60,    50,    41,    50,    42,
     115,    71,    -1,    -1,    -1,    61,    50,    43,    50,   117,
      42,     7,     7,   122,     8,     8,   118,    41,    50,    -1,
      32,    -1,    33,     5,    50,     6,    -1,    34,     5,   122,
       6,    -1,    51,    -1,    50,    -1,    50,     7,   122,     8,
      -1,   122,    47,   122,    48,   122,    -1,    18,    51,    -1,
     122,    18,    -1,    17,   122,    17,    -1,    18,    50,    -1,
      77,    -1,   122,    16,   122,    -1,   122,    17,   122,    -1,
     122,    11,   122,    -1,   122,    12,   122,    -1,   122,    13,
     122,    -1,   122,    14,   122,    -1,   122,    21,   122,    -1,
     122,    22,   122,    -1,   122,    25,   122,    -1,   122,    26,
     122,    -1,   122,    27,   122,    -1,   122,    28,   122,    -1,
     122,    23,   122,    -1,   122,    24,   122,    -1,   122,    29,
     122,    -1,   122,    30,   122,    -1,     5,   122,     6,    -1,
      12,   122,    -1,   122,    57,   122,    58,   122,    -1,   122,
      15,   122,    -1,     5,   122,     6,    38,   122,    10,   122,
      -1,   122,    39,   122,    -1,    50,    20,    50,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   205,   205,   218,   219,   221,   232,   233,   236,   243,
     247,   254,   263,   272,   281,   282,   288,   289,   293,   294,
     299,   300,   301,   302,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   319,   320,   323,   324,
     325,   327,   333,   348,   358,   348,   394,   400,   399,   419,
     425,   418,   438,   446,   438,   463,   472,   462,   500,   499,
     522,   530,   521,   551,   552,   554,   562,   551,   573,   573,
     612,   615,   620,   620,   622,   622,   630,   630,   652,   652,
     658,   669,   669,   679,   679,   681,   681,   721,   731,   721,
     768,   775,   795,   814,   815,   828,   841,   857,   862,   887,
     906,   928,   929,   932,   935,   938,   941,   944,   947,   950,
     953,   956,   959,   962,   965,   966,   967,   968,   969,   970,
     988,  1031,  1038,  1068,  1098
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
  "QMARK", "HAT", "IN", "ON", "AS", "INTO", "DEFINE", "DO", "WHILE", "IF",
  "ELSE", "TYPE", "IDENTIFIER", "NUMBER", "EVAL", "UNLESS", "FOREACH",
  "FOR", "SWITCH", "DOLLAR", "AT", "COND", "MAP", "REDUCE", "NOT",
  "$accept", "program", "def_declarations", "def_declaration",
  "var_declarations", "var_declaration", "declaration_list", "declaration",
  "code_block", "statements", "statement", "control_statement",
  "read_write_statement", "assign_list", "assign_statement", "@1", "@2",
  "if_statement", "@3", "if_stmt", "@4", "@5", "unless_statement", "@6",
  "@7", "while_statement", "@8", "@9", "do_while_statement", "@10",
  "foreach_statement", "@11", "@12", "for_statement", "@13", "@14", "@15",
  "@16", "switch_statement", "@17", "switch_block", "case_statements",
  "case_statement", "@18", "@19", "default_statement", "@20",
  "break_statement", "cond_statement", "@21", "cond_block",
  "map_statement", "@22", "reduce_statement", "@23", "@24",
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
     315,   316,   317
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    63,    64,    65,    65,    66,    67,    67,    68,    69,
      69,    70,    70,    70,    70,    70,    71,    71,    72,    72,
      73,    73,    73,    73,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    78,    79,    77,    80,    81,    80,    83,
      84,    82,    86,    87,    85,    89,    90,    88,    92,    91,
      94,    95,    93,    97,    98,    99,   100,    96,   102,   101,
     103,   103,   104,   104,   106,   105,   107,   105,   109,   108,
     110,   112,   111,   113,   113,   115,   114,   117,   118,   116,
     119,   120,   121,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     3,     2,     0,     3,     2,     0,     3,     3,
       1,     3,     4,     1,     3,     4,     1,     3,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       2,     1,     2,     1,     1,     2,     1,     1,     0,     3,
       1,     6,     3,     0,     0,    11,     1,     0,     4,     0,
       0,     7,     0,     0,     6,     0,     0,     7,     0,     7,
       0,     0,     9,     0,     0,     0,     0,    13,     0,     8,
       1,     2,     2,     1,     0,     5,     0,     5,     0,     4,
       1,     0,     5,     1,     2,     0,     7,     0,     0,    14,
       1,     4,     4,     1,     1,     4,     5,     2,     2,     3,
       2,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       5,     3,     7,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       4,     0,     7,     1,     0,     3,     0,     0,    23,    90,
       0,     0,    80,    58,    55,    49,     0,     0,    52,    60,
      63,     0,     0,     0,     0,     6,     2,    19,    21,     0,
       0,    24,    46,    25,    26,     0,    28,    29,    31,     0,
      33,    34,     0,     0,    36,    37,     5,     0,     0,     0,
       0,     0,    13,     0,    10,     0,    43,     0,     0,     0,
       0,    81,     0,     0,    18,    22,    20,    47,    27,    32,
      35,    30,     0,     0,     0,     0,     0,    94,    93,   101,
       0,     0,     0,    16,     0,     0,     0,     0,     8,     0,
       0,     0,    42,    53,     0,    38,     0,     0,     0,     0,
       0,    91,     0,   119,     0,   100,    97,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    11,     9,
       0,     0,     0,     0,     0,    40,     0,     0,    83,    73,
       0,     0,    87,    48,   118,    99,     0,   124,   104,   105,
     106,   107,   121,   102,   103,   108,   109,   114,   115,   110,
     111,   112,   113,   116,   117,   123,     0,     0,    17,     0,
      56,    50,    15,    12,     0,    44,     0,     0,    64,     0,
      68,    93,     0,     0,    72,    84,    82,    85,     0,     0,
      95,     0,     0,     0,     0,     0,    41,     0,    54,     0,
       0,    39,     0,    74,    76,    78,     0,     0,     0,    96,
     120,    59,    57,    51,     0,    61,     0,     0,    70,     0,
       0,     0,    86,     0,     0,     0,     0,    65,    69,    71,
      75,    77,    79,     0,   122,     0,    62,    38,     0,     0,
       0,     0,    45,    66,    88,     0,     0,    67,     0,    89
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,     5,     6,    25,    53,    54,    82,    26,
      83,    28,    29,   144,    79,    91,   207,    31,   100,    32,
      51,   205,    33,    57,   142,    34,    50,   204,    35,    49,
      36,    58,   236,    37,    59,   210,   247,   255,    38,   212,
     227,   148,   149,   229,   230,   195,   231,    39,    40,    97,
     150,    41,   216,    42,   198,   256,    43,    44,    45,   164
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const short int yypact[] =
{
    -148,     5,   -26,  -148,   -12,  -148,   241,   -15,  -148,  -148,
      42,    47,  -148,  -148,  -148,  -148,     7,    46,  -148,  -148,
    -148,    58,    63,    19,    29,  -148,   271,  -148,  -148,    75,
      81,  -148,    43,  -148,  -148,    83,  -148,  -148,  -148,    86,
    -148,  -148,    93,    94,  -148,  -148,  -148,    71,    32,   157,
     117,   118,    48,     8,  -148,    32,    32,   157,   119,   121,
      82,  -148,    95,    92,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,   131,    32,    32,    32,   -43,     2,  -148,  -148,
     322,   271,    96,  -148,    32,    32,   -40,    26,  -148,     7,
     507,   132,   806,  -148,    88,    90,   137,   109,    97,    98,
     157,  -148,   359,   116,   843,  -148,  -148,    32,   101,  -148,
      32,    32,    32,    32,    32,    32,    32,  -148,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32,
      32,   210,   140,   396,   433,   138,   148,  -148,  -148,  -148,
     139,    32,   104,   152,    37,  -148,   161,    68,    52,  -148,
     163,   126,  -148,  -148,   133,    32,   544,  -148,   116,   116,
      17,    17,   806,   991,   954,     1,     1,    15,    15,  1013,
    1013,     1,     1,   917,   880,   806,   768,   655,  -148,    32,
    -148,  -148,  -148,  -148,    32,   806,    32,   124,  -148,    90,
    -148,   159,   693,   165,  -148,  -148,  -148,  -148,   134,    32,
     139,    32,    32,   470,   157,   157,   806,   122,   806,   172,
      32,  -148,   109,  -148,  -148,  -148,   157,   173,   731,   102,
     806,  -148,  -148,  -148,   129,  -148,   618,   178,    52,   271,
     271,   271,  -148,   177,    32,   146,   157,  -148,  -148,  -148,
     271,   271,   271,    32,   806,   142,  -148,    90,   581,   185,
       0,   187,  -148,  -148,  -148,   157,   156,  -148,   151,  -148
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   143,   -55,   -77,
      -3,  -148,  -148,   -42,    -6,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,    -4,  -147,  -148,  -148,   -22,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,   -14
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
      30,   194,    93,    27,   131,     3,   253,   105,   106,   107,
     135,   136,   110,   111,   112,   113,   114,    88,     4,   117,
      30,    56,   108,    64,   120,   121,   110,   111,   112,   113,
     114,   189,   114,   117,    80,   117,    46,    73,     7,    89,
     128,    90,    92,    30,    74,   153,   188,    47,   129,    75,
      76,    30,    48,    55,   128,    86,   128,    52,   130,   102,
     103,   104,   129,    60,   129,    56,    61,    87,   189,    62,
     133,   134,   130,    73,   130,    30,   137,   138,    27,    63,
      74,   194,    77,    78,    65,    75,    76,   147,   193,   145,
      66,    67,    68,   156,    30,    69,   158,   159,   160,   161,
     162,   163,    70,    71,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   114,    77,   191,
     117,    72,    84,    85,    94,    30,    95,   185,    64,   112,
     113,   114,    96,   192,   117,    99,    98,   101,   143,   141,
      17,   128,   132,   146,   147,   179,   182,   151,   152,   222,
     223,   157,   240,   241,   242,   128,   183,   186,   184,   130,
      81,   232,   187,   129,   190,   203,     8,   196,   197,   213,
     206,   199,   208,   130,   209,   215,   217,   224,   225,   235,
     233,   246,   238,   211,   243,   218,   245,   219,   220,     9,
      10,    11,   249,   252,    12,   254,   226,   258,    30,    30,
     257,   259,    13,    14,    15,   250,   239,    17,   228,    18,
      30,    19,    20,    21,   178,     0,    22,    23,    24,     8,
     244,     0,     0,    30,    30,    30,    27,    27,    27,   248,
      30,     0,   139,     0,    30,    30,    30,    64,    64,    64,
       0,   145,     9,    10,    11,     0,     0,    12,     0,    30,
       8,     0,     0,     0,     0,    13,    14,    15,     0,     0,
      17,     0,    18,     0,    19,    20,    21,     0,     0,    22,
      23,    24,     0,     9,    10,    11,     0,     0,    12,     0,
       8,     0,     0,     0,     0,     0,    13,    14,    15,     0,
      16,    17,     0,    18,     0,    19,    20,    21,     0,     0,
      22,    23,    24,     9,    10,    11,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,     0,
       0,    17,     0,    18,     0,    19,    20,    21,   109,     0,
      22,    23,    24,   110,   111,   112,   113,   114,   115,   116,
     117,     0,     0,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,     0,     0,   154,     0,     0,     0,   129,
     110,   111,   112,   113,   114,   115,   116,   117,     0,   130,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,   128,     0,
       0,     0,   180,     0,     0,     0,   129,   110,   111,   112,
     113,   114,   115,   116,   117,     0,   130,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,   181,
       0,     0,     0,   129,   110,   111,   112,   113,   114,   115,
     116,   117,     0,   130,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,   221,     0,     0,     0,
     129,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     130,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,   140,     0,   129,   110,   111,
     112,   113,   114,   115,   116,   117,     0,   130,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,   200,     0,   129,   110,   111,   112,   113,   114,
     115,   116,   117,     0,   130,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,   251,
       0,   129,   110,   111,   112,   113,   114,   115,   116,   117,
       0,   130,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,   237,   129,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   130,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,   129,   110,   111,   112,   113,
     114,   115,   116,   117,     0,   130,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,   129,   214,   110,   111,   112,   113,   114,   115,
     116,   117,   130,   202,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,   234,   110,   111,   112,   113,   114,   115,   116,   117,
     130,     0,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   129,   110,
     111,   112,   113,   114,   115,   116,   117,     0,   130,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,   129,   201,   110,   111,   112,
     113,   114,   115,   116,   117,   130,     0,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   129,   110,   111,   112,   113,   114,   115,
     155,   117,     0,   130,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,   110,   111,   112,   113,   114,   115,   116,   117,     0,
     130,   118,   119,   120,   121,   122,   123,   124,   125,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   129,   110,   111,
     112,   113,   114,   115,   116,   117,     0,   130,   118,   119,
     120,   121,   122,   123,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,     0,   129,   110,   111,   112,   113,   114,
     115,     0,   117,     0,   130,   118,   119,   120,   121,   122,
     123,   124,   125,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,   129,   110,   111,   112,   113,   114,     0,     0,   117,
       0,   130,   118,   119,   120,   121,   122,   123,   124,   125,
       0,     0,     0,     0,   110,   111,   112,   113,   114,     0,
     128,   117,     0,     0,   118,   119,   120,   121,   129,     0,
     124,   125,     0,     0,     0,     0,     0,     0,   130,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
     129,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130
};

static const short int yycheck[] =
{
       6,   148,    57,     6,    81,     0,     6,    50,    51,     7,
      50,    51,    11,    12,    13,    14,    15,     9,    44,    18,
      26,    19,    20,    26,    23,    24,    11,    12,    13,    14,
      15,    31,    15,    18,    48,    18,    51,     5,    50,    31,
      39,    55,    56,    49,    12,   100,     9,     5,    47,    17,
      18,    57,     5,     7,    39,     7,    39,    50,    57,    73,
      74,    75,    47,     5,    47,    19,     3,    19,    31,    50,
      84,    85,    57,     5,    57,    81,    50,    51,    81,    50,
      12,   228,    50,    51,     9,    17,    18,    35,    36,    95,
       9,    48,     9,   107,   100,     9,   110,   111,   112,   113,
     114,   115,     9,     9,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,    15,    50,    51,
      18,    50,     5,     5,     5,   131,     5,   141,   131,    13,
      14,    15,    50,   147,    18,    43,    41,     6,    50,     7,
      50,    39,    46,     6,    35,     5,     8,    50,    50,   204,
     205,    50,   229,   230,   231,    39,     8,    53,    19,    57,
       3,   216,    10,    47,     3,   179,     9,     4,    42,    10,
     184,    38,   186,    57,    50,    10,    42,    55,     6,    50,
       7,   236,     4,   189,     7,   199,    40,   201,   202,    32,
      33,    34,    50,     8,    37,     8,   210,    41,   204,   205,
     255,    50,    45,    46,    47,   247,   228,    50,   212,    52,
     216,    54,    55,    56,     4,    -1,    59,    60,    61,     9,
     234,    -1,    -1,   229,   230,   231,   229,   230,   231,   243,
     236,    -1,    89,    -1,   240,   241,   242,   240,   241,   242,
      -1,   247,    32,    33,    34,    -1,    -1,    37,    -1,   255,
       9,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      50,    -1,    52,    -1,    54,    55,    56,    -1,    -1,    59,
      60,    61,    -1,    32,    33,    34,    -1,    -1,    37,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      49,    50,    -1,    52,    -1,    54,    55,    56,    -1,    -1,
      59,    60,    61,    32,    33,    34,    -1,    -1,    37,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    50,    -1,    52,    -1,    54,    55,    56,     6,    -1,
      59,    60,    61,    11,    12,    13,    14,    15,    16,    17,
      18,    -1,    -1,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,     6,    -1,    -1,    -1,    47,
      11,    12,    13,    14,    15,    16,    17,    18,    -1,    57,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    -1,     6,    -1,    -1,    -1,    47,    11,    12,    13,
      14,    15,    16,    17,    18,    -1,    57,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,     6,
      -1,    -1,    -1,    47,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    57,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,     6,    -1,    -1,    -1,
      47,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      57,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    47,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    57,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,     8,    -1,    47,    11,    12,    13,    14,    15,
      16,    17,    18,    -1,    57,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,     8,
      -1,    47,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    57,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,     9,    47,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    57,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    57,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    57,    58,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      57,    -1,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    11,
      12,    13,    14,    15,    16,    17,    18,    -1,    57,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    11,    12,    13,
      14,    15,    16,    17,    18,    57,    -1,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    57,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      57,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    57,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    47,    11,    12,    13,    14,    15,
      16,    -1,    18,    -1,    57,    21,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    11,    12,    13,    14,    15,    -1,    -1,    18,
      -1,    57,    21,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    -1,
      39,    18,    -1,    -1,    21,    22,    23,    24,    47,    -1,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    64,    65,     0,    44,    66,    67,    50,     9,    32,
      33,    34,    37,    45,    46,    47,    49,    50,    52,    54,
      55,    56,    59,    60,    61,    68,    72,    73,    74,    75,
      77,    80,    82,    85,    88,    91,    93,    96,   101,   110,
     111,   114,   116,   119,   120,   121,    51,     5,     5,    92,
      89,    83,    50,    69,    70,     7,    19,    86,    94,    97,
       5,     3,    50,    50,    73,     9,     9,    48,     9,     9,
       9,     9,    50,     5,    12,    17,    18,    50,    51,    77,
     122,     3,    71,    73,     5,     5,     7,    19,     9,    31,
     122,    78,   122,    71,     5,     5,    50,   112,    41,    43,
      81,     6,   122,   122,   122,    50,    51,     7,    20,     6,
      11,    12,    13,    14,    15,    16,    17,    18,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    39,    47,
      57,    72,    46,   122,   122,    50,    51,    50,    51,    70,
       8,     7,    87,    50,    76,    77,     6,    35,   104,   105,
     113,    50,    50,    71,     6,    17,   122,    50,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   122,     4,     5,
       6,     6,     8,     8,    19,   122,    53,    10,     9,    31,
       3,    51,   122,    36,   105,   108,     4,    42,   117,    38,
       8,    48,    58,   122,    90,    84,   122,    79,   122,    50,
      98,    77,   102,    10,    10,    10,   115,    42,   122,   122,
     122,     6,    71,    71,    55,     6,   122,   103,   104,   106,
     107,   109,    71,     7,    10,    50,    95,     9,     4,   108,
      72,    72,    72,     7,   122,    40,    71,    99,   122,    50,
      76,     8,     8,     6,     8,   100,   118,    71,    41,    50
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
#line 206 "Acse.y"
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
#line 218 "Acse.y"
    {/* does nothing*/;}
    break;

  case 4:
#line 219 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 5:
#line 221 "Acse.y"
    {

            t_axe_define *def = malloc(sizeof(t_axe_define));
            def->id = strdup((yyvsp[-1].svalue));
            def->val = (yyvsp[0].intval);

            defines = addFirst(defines, def);
            ;}
    break;

  case 6:
#line 232 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 7:
#line 233 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 8:
#line 237 "Acse.y"
    {
                     /* update the program infos by adding new variables */
                     set_new_variables(program, (yyvsp[-2].intval), (yyvsp[-1].list));
                  ;}
    break;

  case 9:
#line 244 "Acse.y"
    {  /* add the new declaration to the list of declarations */
                     (yyval.list) = addElement((yyvsp[-2].list), (yyvsp[0].decl), -1);
                  ;}
    break;

  case 10:
#line 248 "Acse.y"
    {
                     /* add the new declaration to the list of declarations */
                     (yyval.list) = addElement(NULL, (yyvsp[0].decl), -1);
                  ;}
    break;

  case 11:
#line 255 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[-2].svalue), 0, 0, (yyvsp[0].intval));

               /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 12:
#line 264 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[-3].svalue), 1, (yyvsp[-1].intval), 0);

                  /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 13:
#line 273 "Acse.y"
    {
               /* create a new instance of t_axe_declaration */
               (yyval.decl) = alloc_declaration((yyvsp[0].svalue), 0, 0, 0);
               
               /* test if an `out of memory' occurred */
               if ((yyval.decl) == NULL)
                  notifyError(AXE_OUT_OF_MEMORY);
            ;}
    break;

  case 16:
#line 288 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 17:
#line 289 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 18:
#line 293 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 19:
#line 294 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 20:
#line 299 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 21:
#line 300 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 22:
#line 301 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 23:
#line 302 "Acse.y"
    { gen_nop_instruction(program); ;}
    break;

  case 24:
#line 305 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 25:
#line 306 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 26:
#line 307 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 27:
#line 308 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 28:
#line 309 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 29:
#line 310 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 30:
#line 311 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 31:
#line 312 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 32:
#line 313 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 33:
#line 314 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 34:
#line 315 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 35:
#line 316 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 36:
#line 319 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 37:
#line 320 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 38:
#line 323 "Acse.y"
    {;}
    break;

  case 39:
#line 324 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 40:
#line 325 "Acse.y"
    { /* does nothing */ ;}
    break;

  case 41:
#line 328 "Acse.y"
    {
               storeArrayElement(program, (yyvsp[-5].svalue), (yyvsp[-3].expr), (yyvsp[0].expr));
			   (yyval.expr) = create_expression((yyvsp[0].expr).value, IMMEDIATE);
               free((yyvsp[-5].svalue));
            ;}
    break;

  case 42:
#line 334 "Acse.y"
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

  case 43:
#line 348 "Acse.y"
    {
               /* Init the gloabal struct */
               ac.l_cond = newLabel(program);
               ac.l_body = newLabel(program);
               ac.index = gen_load_immediate(program, 0);
               

               gen_bt_instruction(program, ac.l_cond, 0);

               assignLabel(program, ac.l_body);
             ;}
    break;

  case 44:
#line 358 "Acse.y"
    {

               /* $1[i] = exp_i */
               storeArrayElement(program, (yyvsp[-4].svalue), create_expression(ac.index, REGISTER), (yyvsp[0].expr));
               gen_addi_instruction(program, ac.index, ac.index, 1); 

             ;}
    break;

  case 45:
#line 364 "Acse.y"
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

  case 46:
#line 395 "Acse.y"
    {
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[0].label));
               ;}
    break;

  case 47:
#line 400 "Acse.y"
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

  case 48:
#line 412 "Acse.y"
    {
                  /* fix the `label_else' */
                  assignLabel(program, (yyvsp[-2].label));
               ;}
    break;

  case 49:
#line 419 "Acse.y"
    {
                  /* the label that points to the address where to jump if
                   * `exp' is not verified */
                  (yyvsp[0].label) = newLabel(program);
               ;}
    break;

  case 50:
#line 425 "Acse.y"
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

  case 51:
#line 435 "Acse.y"
    { (yyval.label) = (yyvsp[-6].label); ;}
    break;

  case 52:
#line 438 "Acse.y"
    {
				(yyvsp[0].unless_stmt) = create_unless_statement();
				(yyvsp[0].unless_stmt).condition = newLabel(program);
				(yyvsp[0].unless_stmt).code_block = newLabel(program);
				(yyvsp[0].unless_stmt).end = newLabel(program);
				gen_bt_instruction(program, (yyvsp[0].unless_stmt).condition, 0);
				assignLabel(program, (yyvsp[0].unless_stmt).code_block);
			;}
    break;

  case 53:
#line 446 "Acse.y"
    {
				gen_bt_instruction(program, (yyvsp[-2].unless_stmt).end, 0);
				assignLabel(program, (yyvsp[-2].unless_stmt).condition);
			;}
    break;

  case 54:
#line 450 "Acse.y"
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

  case 55:
#line 463 "Acse.y"
    {
                     /* initialize the value of the non-terminal */
                     (yyvsp[0].while_stmt) = create_while_statement();

                     /* reserve and fix a new label */
                     (yyvsp[0].while_stmt).label_condition
                           = assignNewLabel(program);
                  ;}
    break;

  case 56:
#line 472 "Acse.y"
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

  case 57:
#line 488 "Acse.y"
    {
                     /* jump to the beginning of the loop */
                     gen_bt_instruction
                           (program, (yyvsp[-6].while_stmt).label_condition, 0);

                     /* fix the label `label_end' */
                     assignLabel(program, (yyvsp[-6].while_stmt).label_end);

                  ;}
    break;

  case 58:
#line 500 "Acse.y"
    {
                        /* the label that points to the address where to jump if
                         * `exp' is not verified */
                        (yyvsp[0].label) = newLabel(program);
                        
                        /* fix the label */
                        assignLabel(program, (yyvsp[0].label));
                     ;}
    break;

  case 59:
#line 509 "Acse.y"
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

  case 60:
#line 522 "Acse.y"
    {
				(yyvsp[0].foreach_stmt).counter = getNewRegister(program);
				gen_addi_instruction(program, (yyvsp[0].foreach_stmt).counter, REG_0, 0);
				(yyvsp[0].foreach_stmt).iteration = newLabel(program);
				(yyvsp[0].foreach_stmt).end = newLabel(program);
				assignLabel(program, (yyvsp[0].foreach_stmt).iteration);
			;}
    break;

  case 61:
#line 530 "Acse.y"
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

  case 62:
#line 544 "Acse.y"
    {
				gen_addi_instruction(program, (yyvsp[-8].foreach_stmt).counter, (yyvsp[-8].foreach_stmt).counter, 1);
				gen_bt_instruction(program, (yyvsp[-8].foreach_stmt).iteration, 0);
				assignLabel(program, (yyvsp[-8].foreach_stmt).end);
			;}
    break;

  case 63:
#line 551 "Acse.y"
    { (yyvsp[0].for_stmt) = create_for_statement();;}
    break;

  case 64:
#line 552 "Acse.y"
    {(yyvsp[-4].for_stmt).label_exp = assignNewLabel(program);;}
    break;

  case 65:
#line 554 "Acse.y"
    {
          (yyvsp[-7].for_stmt).label_end = newLabel(program);
          gen_beq_instruction(program, (yyvsp[-7].for_stmt).label_end, 0);
          (yyvsp[-7].for_stmt).label_code = newLabel(program);
          gen_bt_instruction(program, (yyvsp[-7].for_stmt).label_code, 0);
          (yyvsp[-7].for_stmt).label_epilogue = assignNewLabel(program);
        ;}
    break;

  case 66:
#line 562 "Acse.y"
    {
          gen_bt_instruction(program, (yyvsp[-10].for_stmt).label_exp, 0);
          assignLabel(program, (yyvsp[-10].for_stmt).label_code);
        ;}
    break;

  case 67:
#line 567 "Acse.y"
    {
          gen_bt_instruction(program, (yyvsp[-12].for_stmt).label_epilogue, 0);
          assignLabel(program, (yyvsp[-12].for_stmt).label_end);
        ;}
    break;

  case 68:
#line 573 "Acse.y"
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

  case 69:
#line 587 "Acse.y"
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

  case 70:
#line 612 "Acse.y"
    {
					gen_bt_instruction(program, ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->switch_end, 0);
				;}
    break;

  case 71:
#line 615 "Acse.y"
    {
					gen_bt_instruction(program, ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->switch_end, 0);
				;}
    break;

  case 74:
#line 622 "Acse.y"
    {
          /* allocate memory for the test_case */
					t_case_statement *c = (t_case_statement *)malloc(sizeof(t_case_statement));
					c->number = (yyvsp[-1].intval); // assign number to c
					c->begin_case = assignNewLabel(program);
					/* update list of cases with c as last element */
          ((t_switch_statement *)LDATA(getElementAt(switchStack, 0)))->cases = addLast(((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->cases, c);
				;}
    break;

  case 76:
#line 630 "Acse.y"
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

  case 77:
#line 643 "Acse.y"
    {

          /* this instruction is reached if the exp has been evaluated to true */
          gen_bt_instruction(program, ((t_cond_statement*)LDATA(getElementAt(condStack,0)))->l_end, 0);
          
          assignLabel(program, ((t_cond_statement*)LDATA(getElementAt(condStack, 0)))->l_next);
        ;}
    break;

  case 78:
#line 652 "Acse.y"
    {
          if(switchStack!=NULL) // I might be in the cond statement case
            ((t_switch_statement*)LDATA(getElementAt(switchStack, 0)))->default_label = assignNewLabel(program);
					;}
    break;

  case 80:
#line 658 "Acse.y"
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

  case 81:
#line 669 "Acse.y"
    {
                      (yyvsp[-1].cond_stmt) = (t_cond_statement *)malloc(sizeof(t_cond_statement));
                      (yyvsp[-1].cond_stmt)->l_end = newLabel(program);
                      condStack = addFirst(condStack, (yyvsp[-1].cond_stmt));
                  ;}
    break;

  case 82:
#line 673 "Acse.y"
    {
                      assignLabel(program, (yyvsp[-4].cond_stmt)->l_end);
                      condStack = removeFirst(condStack);
                  ;}
    break;

  case 85:
#line 681 "Acse.y"
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

  case 86:
#line 703 "Acse.y"
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

  case 87:
#line 721 "Acse.y"
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

  case 88:
#line 731 "Acse.y"
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

  case 89:
#line 743 "Acse.y"
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

  case 90:
#line 769 "Acse.y"
    {
               /* insert an HALT instruction */
               gen_halt_instruction(program);
            ;}
    break;

  case 91:
#line 776 "Acse.y"
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

  case 92:
#line 796 "Acse.y"
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

  case 93:
#line 814 "Acse.y"
    { (yyval.expr) = create_expression ((yyvsp[0].intval), IMMEDIATE); ;}
    break;

  case 94:
#line 815 "Acse.y"
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

  case 95:
#line 828 "Acse.y"
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

  case 96:
#line 841 "Acse.y"
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

  case 97:
#line 857 "Acse.y"
    {  if ((yyvsp[0].intval) == 0)
                           (yyval.expr) = create_expression (1, IMMEDIATE);
                        else
                           (yyval.expr) = create_expression (0, IMMEDIATE);
   ;}
    break;

  case 98:
#line 862 "Acse.y"
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

  case 99:
#line 887 "Acse.y"
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

  case 100:
#line 906 "Acse.y"
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

  case 101:
#line 928 "Acse.y"
    {;}
    break;

  case 102:
#line 929 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ANDB);
   ;}
    break;

  case 103:
#line 932 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ORB);
   ;}
    break;

  case 104:
#line 935 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ADD);
   ;}
    break;

  case 105:
#line 938 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SUB);
   ;}
    break;

  case 106:
#line 941 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), MUL);
   ;}
    break;

  case 107:
#line 944 "Acse.y"
    {
                           (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), DIV);
   ;}
    break;

  case 108:
#line 947 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _LT_);
   ;}
    break;

  case 109:
#line 950 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _GT_);
   ;}
    break;

  case 110:
#line 953 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _EQ_);
   ;}
    break;

  case 111:
#line 956 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _NOTEQ_);
   ;}
    break;

  case 112:
#line 959 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _LTEQ_);
   ;}
    break;

  case 113:
#line 962 "Acse.y"
    {
                        (yyval.expr) = handle_binary_comparison (program, (yyvsp[-2].expr), (yyvsp[0].expr), _GTEQ_);
   ;}
    break;

  case 114:
#line 965 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SHL); ;}
    break;

  case 115:
#line 966 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), SHR); ;}
    break;

  case 116:
#line 967 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ANDL); ;}
    break;

  case 117:
#line 968 "Acse.y"
    {  (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), ORL); ;}
    break;

  case 118:
#line 969 "Acse.y"
    { (yyval.expr) = (yyvsp[-1].expr); ;}
    break;

  case 119:
#line 970 "Acse.y"
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

  case 120:
#line 988 "Acse.y"
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

  case 121:
#line 1031 "Acse.y"
    {
          int q_reg = getNewRegister(program);
          t_axe_expression q = create_expression(q_reg, REGISTER); // Quotient of the division

          q = handle_bin_numeric_op(program, (yyvsp[-2].expr), (yyvsp[0].expr), DIV); // d <- a / b (integer)
          (yyval.expr) = handle_bin_numeric_op(program, (yyvsp[-2].expr), handle_bin_numeric_op(program, (yyvsp[0].expr), q, MUL), SUB);
  ;}
    break;

  case 122:
#line 1038 "Acse.y"
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

  case 123:
#line 1068 "Acse.y"
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

  case 124:
#line 1098 "Acse.y"
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
#line 3036 "Acse.tab.c"

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


#line 1141 "Acse.y"

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

