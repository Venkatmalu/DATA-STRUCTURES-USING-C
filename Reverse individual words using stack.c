#include<stdio.h>
#include<string.h>

char stack[100],x;
int top=-1;

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    if(top==-1)
    {
        printf("stack is empty...");
    }
    else
    {
        return stack[top--];
    }
}

void main()
{
    char str[100],x,*e;
    int len,i=0,s=0;
    printf("Enter the string to reverse : ");
    gets(str);
    len=strlen(str);
    e=str;
    while(i!=len+1)
    {
        if(*e!=' ' || *e!='\0')
        {
            push(*e);
        }
        if(*e==' ' || *e=='\0')
        {
            if(s==0)
                pop();
          while(top!=-1)
           {
              x=pop();
              printf("%c",x);
           }
           s=e;
        }
       e++;
       i++;
    }
}
