#include<stdio.h>
// #include<conio.h>
#include<string.h>
#include<stdlib.h>
void strrev(char *str1)  
{ 
    int i, len, temp;  
    len = strlen(str1); 
    for (i = 0; i < len/2; i++)  
    { 
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  
void main()
{
//e,e'=E,t,t'=T
char input[7]="i+i*i$",m[6][7][9]={" ","+","*","(",")","i","$","e","","","e->tE","","e->tE","", "E","E->+tE","","","E->@","","E->@", "t","","","t->fT","","t->fT","", "T","T->@","T->*fT","","T->@","","", "f","","","f->(e)","","f->i",""};
char stack[20],x,a,prod[6];
int i,j,k,inp=0,top=0,xp,ap,max=6;
stack[0]='$';
printf("Predictive Parser\n");
printf("\nStack\tInput\n");
printf("-----\t-----\n");
printf(" ");
top++;
stack[top]='e';
do
{
a=input[inp];
x=stack[top];
if(x==a)
{
printf("\n");
for(i=0;i<top;i++)
printf("%c",stack[i]);
printf("\t%s",input);
stack[top]=' ';
input[inp]=' ';
top--;
inp++;
}
else
{
//finding positions
for(i=0;i<7;i++)
if(m[0][i][0]==a)
{
ap=i;
// printf("%d\n",ap);
break;
}
for(i=0;i<6;i++)
if(m[i][0][0]==x)
{
xp=i;
// printf("%d\n",xp);
break;
}
// reading entry from parsing table
if(m[xp][ap][0]==' ')
{
    printf("error");
exit(1);
}
else
{
for(i=0,k=3;k<8;k++,i++)
{
prod[i]=m[xp][ap][k];
}
strrev(prod);
}
//stack operations
if(prod[0]=='@')
{
printf("\n");
for(i=0;i<=top;i++)
printf("%c",stack[i]);
printf("\t%s",input);
stack[top]=' ';
top--;
}
else
{
printf("\n");
for(i=0;i<=top;i++)
printf("%c",stack[i]);
printf("\t%s",input);
//pop
stack[top]=' ';
top--;
//push
for(i=0;i<strlen(prod);i++)
{
top++;
stack[top]=prod[i];
}
}
}
}
while(stack[top]!='$');
if(stack[top]=='$'&&input[inp]=='$')
{
printf("\n%c\t\\ %c\nString is accepted",stack[top],input[inp]);
}
else
{
printf("not accepted");
}
// getch();
}
