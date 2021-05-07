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
    char arr[100],*e,x,*rev,reverse[100];
    int i=0;
    printf("Enter the infix expression : ");
    gets(arr);
    rev=arr;
    while(*rev!='\0')
    {
        push(*rev);
        rev++;
    }
    while(top!=-1)
    {
       reverse[i]=pop();
       i++;
    }
    e=reverse;
    i=0;
    while(*e!='\0')
    {
        if(*e=='(')
        {
            push(*e);
        }else if(48<=*e&&57>=*e || 65<=*e&&90>=*e || 97<=*e&&122>=*e)
        {
            arr[i]=*e;
            i++;
        }else if(*e==')')
        {
            while((x=pop())!='(')
            {
                arr[i]=x;
                i++;
            }
        }
        else
        {
            if(*e!='^')
            {
               while(priority(stack[top])>=priority(*e))
               {
                   arr[i]=pop();
                   i++;
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
                    arr[i]=pop();
                    i++;
                }
            }
        }
        e++;
    }
    while(top!=-1)
      {
        arr[i]=pop();
      }
    rev=arr;
    while(*rev!='\0')
    {
        push(*rev);
        rev++;
    }
    i=0;
    while(top!=-1)
    {
       reverse[i]=pop();
       i++;
    }
    printf("\nThe Prefix Expression is : %s\n",reverse);
    return 0;
}

