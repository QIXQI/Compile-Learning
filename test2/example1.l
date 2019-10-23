%{
	#include <stdlib.h>
	#include <stdio.h>
	#define NUM 201792179
	int num_chars = 0;
	int num_ids = 0;
	int num_nums = 0;
%}
delim [ ]
letter [A-Za-z]
digit [0-9]
number {digit}+
id {letter}+
%%
{number} {int r = atoi(yytext); if(r==NUM) printf("灰太狼"); else printf("%s ", yytext); num_nums+=yyleng; num_chars += yyleng;}
{delim} {printf(" "); num_chars += yyleng;}
{id} {printf("%s ", yytext); ++num_ids; num_chars+=yyleng;}
%%
main(){
	yylex();
	printf("\n# of ids = %d, # of letters = %d,# of numbers = %d", num_ids, num_chars, num_nums);
}