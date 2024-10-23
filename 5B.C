#include<stdio.h>
#include<conio.h>
#include<string.h>
#define stacksize 10
struct stack
{
int top;
int item[stacksize];
}s;
void push(struct stack*,int);
int pop(struct stack*);
void main()
{
char exp[10],postex;
int len,val,result,a,b,c,i;
clrscr();
s.top=-1;
printf("\nEnter the postfix expression:");
scanf("%s",exp);
len=strlen(exp);
printf("\nlength :%d",len);
printf("\npostfix expression %s",exp);
for(i=0;i<len;i++)
{
postex=exp[i];
if(postex=='+'|postex=='-'|postex=='*'|postex=='/')
{
a=pop(&s);
b=pop(&s);
switch(postex)
{
case '+':
c=a+b;
break;
case '-':
c=b-a;
break;
case'*':
c=a*b;
break;
case '/':
c=b/a;
break;
}
push(&s,c);
result=c;
}
else
{
printf("\nEnter the value of %c=",postex);
scanf("%d",&val);
push(&s,val);
}
}
printf("\nresult=%d",result);
getch();
}
void push(struct stack* sptr,int data)
{
if(sptr->top==stacksize-1)
{
printf("\nstack overflow");
}
else
{
++sptr->top;
sptr->item[sptr->top]=data;
}
}
int pop(struct stack* sptr)
{
if(sptr->top==-1)
return -1;
else
{
return(sptr->item[sptr->top--]);
}
}

