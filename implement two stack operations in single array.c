#include<stdio.h>
#define N 5
int stack[N],top1=N/2,top2=N/2+1,x,i;

void push1();
void push2();
void pop1();
void pop2();
void peek1();
void peek2();
void displaystack1();
void displaystack2();

void push1()
{
    int x;
    printf("Enter the value to push : ");
    scanf("%d",&x);
    if(top1==-1)
    {
        printf("occuring overflow...NO ENOIUGH SPACE FOR %d",x);
    }
    else
    {
        stack[top1]=x;
        top1--;
    }
}

void push2()
{
    int x;
    printf("Enter the value to push : ");
    scanf("%d",&x);
    if(top2==N)
    {
        printf("occuring overflow...NO ENOUGH SPACE FOR %d",x);
    }
    else
    {
        stack[top2]=x;
        top2++;
    }
}

void pop1()
{
    if(top1==N/2)
    {
        printf("underflow situation occuring");
    }
    else
    {
        top1++;
    }
}

void pop2()
{
    if(top2==N/2+1)
    {
        printf("underflow situation occuring");
    }
    else
    {
        top2--;
    }
}

void peek1()
{
    if(top1==N/2)
    {
        printf("\nThe is no elements,so insert....");
    }
    else
    {
        printf("\nThe top1 = %d",stack[top1+1]);
    }
}

void peek2()
{
    if(top2==N/2+1)
    {
        printf("\nThe is no elements,so insert....");
    }
    else
    {
        printf("\nThe top2 = %d",stack[top2-1]);
    }
}

void displaystack1()
{
    if(top1==N/2)
    {
        printf("Stack1 is empty...");
    }
    for(i=top1+1;i<=N/2;i++)
    {
        printf("%d ",stack[i]);
    }
}

void displaystack2()
{
    if(top2==N/2+1)
    {
        printf("Stack2 is empty..");
    }
    for(i=top2-1;i>=N/2+1;i--)
    {
        printf("%d ",stack[i]);
    }
}

int main()
{
    int choice=1;
    while(choice)
    {
        printf("Enter UR choice \n1.push into stack1\n2.pop from stack1\n3.peek for stack1\n4.display stack1\n5.push into stack2 \n6.pop from stack2\n7.peek for stack2\n8.display stack2\n");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                push1();
                break;
            }
        case 2:
            {
                pop1();
                break;
            }
        case 3:
            {
                peek1();
                break;
            }
        case 4:
            {
                displaystack1();
                break;
            }
        case 5:
            {
                push2();
                break;
            }
        case 6:
            {
                pop2();
                break;
            }
        case 7:
            {
                peek2();
                break;
            }
        case 8:
            {
                displaystack2();
                break;
            }
        default:
        printf("Entered invalid option");
    }
    printf("\nEnter greater than 1 to continue else 0 : ");
    scanf("%d",&choice);
    }
}
