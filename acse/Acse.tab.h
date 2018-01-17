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
/* Line 1447 of yacc.c.  */
#line 177 "Acse.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



