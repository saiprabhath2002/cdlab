#include<stdio.h>
#include <stdlib.h>
#include<string.h>
void strrev(char *str1)  
{  
    // declare variable  
    int i, len, temp;  
    len = strlen(str1); // use strlen() to get the length of str string  
      
    // use for loop to iterate the string   
    for (i = 0; i < len/2; i++)  
    {  
        // temp variable use to temporary hold the string  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}
void pm();
void plus();
void div1();
int i,ch,j,l,addr=100;
char ex[10], temp[10] ,temp1[10],temp2[10],id1[5],op[5],id2[5];
int main()
{
while(1)
{
printf("\n1.assignment\n2.arithmetic\n3.relational\n4.Exit\nEnter the choice:");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nEnter the expression with assignment operator:");
scanf("%s",temp);
l=strlen(temp);
temp2[0]='\0';
i=0;
while(temp[i]!='=')
{
i++;
}
strncat(temp2,temp,i);
strrev(temp);
temp1[0]='\0';
strncat(temp1,temp,l-(i+1));
strrev(temp1);
printf("Three address code:\ntemp=%s\n%s=temp\n",temp1,temp2);
break;
case 2:
printf("\nEnter the expression with arithmetic operator:");
scanf("%s",ex);
strcpy(temp,ex);
l=strlen(temp);
temp1[0]='\0';
for(i=0;i<l;i++)
{
if(temp[i]=='+'||temp[i]=='-')
{
if(temp[i+2]=='/'||temp[i+2]=='*')
{
pm();
break;
}
else
{
plus();
break;
}
}
else if(temp[i]=='/'||temp[i]=='*')
{
div1();
break;
}
}
break;
case 3:
printf("Enter the expression with relational operator");
scanf("%s%s%s",id1,op,id2);
if(((strcmp(op,"<")==0)||(strcmp(op,">")==0)||(strcmp(op,"<=")==0)||(strcmp(op,">=")==0)||(strcmp(op,"==" )==0)||(strcmp(op,"!=")==0))==0)
printf("expression is error");
else
{
printf("\n%d\tif %s%s%s goto %d",addr,id1,op,id2,addr+3);
addr++;
printf("\n%d\t T:=0",addr);
addr++;
printf("\n%d\t goto %d",addr,addr+2);
addr++;
printf("\n%d\t T:=1",addr);
}
break;
case 4:
exit(0);
}
} //closing while loop
}
void pm()
{
strrev(temp);
j=l-i-1;
strncat(temp1,temp,j);
strrev(temp1);
printf("Three address code:\ntemp=%s \ntemp1=%c%ctemp \n ", temp1
,temp[j+1] ,temp[j]);
}
void div1()
{
strncat(temp1,temp,i+2);
printf("Three address code:\ntemp=%s \ntemp1=temp%c%c \n", temp1 ,
temp[i+2] ,temp[i+3]);
}
void plus()
{
strncat(temp1,temp,i+2);
printf("Three address code:\ntemp=%s \ntemp1=temp%c%c \n",temp1 ,
temp[i+2],temp[i+3]);
}
