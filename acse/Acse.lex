/***************************************************************************

                                    Scanner 

***************************************************************************/
%option noyywrap

%{
/*
 * Andrea Di Biagio
 * Politecnico di Milano, 2007
 * 
 * Axe.lex
 * Formal Languages & Compilers Machine, 2007/2008
 * 
 */

#include <string.h>
#include "axe_struct.h"
#include "collections.h"
#include "Acse.tab.h"
#include "axe_constants.h"

/* Variables declared in the lexer for error tracking */
extern int line_num;
extern int num_error;

/* Variable declared for defines */
extern t_list *defines;

/* extern declaration of function yyerror */
extern int yyerror(const char* errmsg);

%}
/*=========================================================================
                          TOKEN DEFINITIONS
=========================================================================*/
DIGIT    [0-9]
ID       [a-zA-Z_][a-zA-Z0-9_]*


/*=========================================================================
      TOKENS
=========================================================================*/

%option noyywrap

%x comment

%%

"\r\n"            { ++line_num; }
"\n"              { ++line_num; }

[ \t\f\v]+        { /* Ignore whitespace. */ }

"//"[^\n]*        { ++line_num; /* ignore comment lines */ }
"/*"              BEGIN(comment);

<comment>[^*\n]*
<comment>[^*\n]*\n      { ++line_num; }
<comment>"*"+[^*/\n]*   
<comment>"*"+[^*/\n]*\n { ++line_num; }
<comment>"*"+"/"        BEGIN(INITIAL);

"{"               { return LBRACE; 	}
"}"               { return RBRACE; 	}
"["               { return LSQUARE; }
"]"               { return RSQUARE; }
"("               { return LPAR; 	}
")"               { return RPAR; 	}
";"               { return SEMI; 	}
":"               { return COLON; 	}
"+"               { return PLUS; 	}
"-"               { return MINUS; 	}
"*"               { return MUL_OP; 	}
"/"               { return DIV_OP; 	}
"%"               { return MOD_OP; 	}
"&"               { return AND_OP; 	}
"|"               { return OR_OP; 	}
"!"               { return NOT_OP; 	}
"="               { return ASSIGN; 	}
"<"               { return LT; 		}
">"               { return GT; 		}
"<<"              { return SHL_OP; 	}
">>"              { return SHR_OP; 	}
"=="              { return EQ; 		}
"!="              { return NOTEQ; 	}
"<="              { return LTEQ; 	}
">="              { return GTEQ; 	}
"&&"              { return ANDAND; 	}
"||"              { return OROR; 	}
","               { return COMMA; 	}
"$"				  { return DOLLAR; 	}
"@"				  { return AT; 		}
"?"				  { return QMARK; 	}
"^"				  { return HAT; 	}

"do"              { return DO; 		}
"else"            { return ELSE; 	}
"for"             { return FOR; 	}	
"foreach"		  { return FOREACH; }
"if"              { return IF; 		}
"int"             { yylval.intval = INTEGER_TYPE; return TYPE; }
"while"           { return WHILE; 	}
"return"          { return RETURN; 	}
"read"            { return READ; 	}
"write"           { return WRITE; 	}
"eval"            { return EVAL; 	}
"unless"          { return UNLESS; 	}
"switch"		  { return SWITCH; 	}
"case"			  { return CASE; 	}
"break"			  { return BREAK; 	}
"default"		  { return DEFAULT; }
"cond"			  { return COND; 	}
"=a="			  { return EQARRAY; }
"in"			  { return IN; 		}
"map"    		  { return MAP; 	}
"on"			  { return ON; 		}
"as"			  { return AS;		}
"reduce"		  { return REDUCE; 	}
"into"			  { return INTO; 	}
"define"		  { return DEFINE;  }

{ID}              { 
					t_list *l;
					for(l=defines; l; l=LNEXT(l)){
						t_axe_define *d = (t_axe_define*)(LDATA(l));
						if( strcmp(d->id,yytext)==0){
							yylval.intval = d->val;
							return NUMBER;
						}
					}
					yylval.svalue=strdup(yytext); return IDENTIFIER; 
				  }

{DIGIT}+          { yylval.intval = atoi( yytext );
                    return(NUMBER); }

.                 { yyerror("Error: unexpected token");
                    num_error++;
                    return (-1); /* invalid token */
                  }
