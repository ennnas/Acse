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
     DO = 296,
     WHILE = 297,
     IF = 298,
     ELSE = 299,
     TYPE = 300,
     IDENTIFIER = 301,
     NUMBER = 302,
     EVAL = 303,
     UNLESS = 304,
     FOREACH = 305,
     FOR = 306,
     SWITCH = 307,
     DOLLAR = 308,
     AT = 309,
     COND = 310,
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
#define DO 296
#define WHILE 297
#define IF 298
#define ELSE 299
#define TYPE 300
#define IDENTIFIER 301
#define NUMBER 302
#define EVAL 303
#define UNLESS 304
#define FOREACH 305
#define FOR 306
#define SWITCH 307
#define DOLLAR 308
#define AT 309
#define COND 310
#define NOT 311




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
} YYSTYPE;
/* Line 1447 of yacc.c.  */
#line 165 "Acse.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



