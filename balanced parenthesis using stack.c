#include<stdio.h>
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

    }
    else
    {
        return stack[top--];
    }
}

void main()
{
    char arr[100],*e,x;
    printf("Enter the paranthese to check : ");
    gets(arr);
    printf("%s\n",arr);
    printf("\nThe result is : ");
    e=arr;
    if(*e=='\0' && top==-1)
    {
        printf("U DID NOT ENTERED ANY DATA...\n\n");
    }
    else
    {
        while(*e!='\0')
    {
        if(*e=='(' || *e=='[' || *e=='{')
            {
                push(*e);
            }
            else
            {
                x=pop();
                if(*e==')')
                {
                    if(x!='(')
                    {
                      printf("UNBALANCED\n\n");
                      break;
                    }
                }
                if(*e=='}')
                {
                    if(x!='{')
                    {
                      printf("UNBALANCED\n\n");
                      break;
                    }
                }
                if(*e==']')
                {
                    if(x!='[')
                    {
                      printf("UNBALANCED\n\n");
                      break;
                    }
                }
                }
                e++;
            }
            if(*e=='\0' && top==-1){
             printf("BALANCED\n\n");
            }
            if(top!=-1)
            {
                printf("Unbalanced");
            }
    }

    }


