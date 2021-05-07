#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char stack[100];
int top=-1;

void push(char);
char pop();
int priority(char);

void push(char x)
{
    stack[++top]=x;
}

char pop()
{
    if(top==-1)
    {
        printf("Stack is empty");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
    if(x=='^')
        return 3;
}

int main()
{
    char arr[100],*e,x;
    printf("Enter the infix Expression : ");
    gets(arr);
    e=arr;
    printf("\nThe Postfix Expression is : ");
    while(*e!='\0')
    {
        if(*e=='(')
        {
            push(*e);
        }else if(48<=*e&&57>=*e || 65<=*e&&90>=*e || 97<=*e&&122>=*e)
        {
            printf("%c",*e);
        }else if(*e==')')
        {
            while((x=pop())!='(')
            {
                printf("%c",x);
            }
        }
        else
        {
            if(*e!='^')
            {
               while(priority(stack[top])>=priority(*e))
               {
                  printf("%c",pop());
               }
               push(*e);
            }
            else
            {
                if(priority(stack[top])<=priority(*e))
                {
                      push(*e);
                }
                else
                {
                  printf("%c",pop());
                }
            }
        }
        e++;
    }
    while(top!=-1)
      {
        printf("%c",pop());
      }
    return 0;
}
