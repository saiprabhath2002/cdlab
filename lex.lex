%{
int n=0;
%}
%%
"if"|"else"|"while"|"for" {
printf(" keyword %s",yytext);
}
[a-zA-Z_][a-zA-Z_]* {
printf(" identifier %s",yytext);
}
"<"|"<="|">"|">="|"=="|"="|"+"|"-"|"*" {
printf(" operator %s",yytext);
}
[(){},;] {
printf(" separator %s",yytext);
}
[0-9]+ {
printf("digits %s",yytext);}
%%
int main()
{
yylex();
}
int yywrap(){
return 1;
}
