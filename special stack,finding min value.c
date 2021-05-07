#include<stdio.h>
#define N 5
int stack[N],stack2[N],top1=-1,top2=-1;x,i;

void push();
void pop();
void peek();
void display();

void push()
{
    int x;
    printf("Enter the value to push : ");
    scanf("%d",&x);
    if(top1==N-1)
    {
        printf("occuring overflow...");
    }
    else
    {
        top1++;
        stack[top1]=x;
        if(top2==-1)
        {
            top2++;
            stack2[top2]=x;
        }
        else
        {
            if(x<stack[top2])
            {
                top2++;
                stack2[top2]=x;
            }
            else
            {
                top2++;
                stack2[top2]=stack2[top2-1];
            }
        }
    }
}

void pop()
{
    if(top1==-1)
    {
        printf("underflow situation occuring");
    }
    else
    {
            top1--;
            top2--;
    }
}

void peek()
{
    if(top1==-1)
    {
        printf("\nThe is no elements,so insert....");
    }
    else
    {
        printf("\nThe top = %d",stack[top1]);
    }
}
void display()
{
    for(i=top1;i>=0;i--)
    {
        printf("\n%d ",stack[i]);
        printf("\nMin : %d ",stack2[i]);
    }
}

int main()
{
    int choice=1;
    while(choice)
    {
        printf("\nEnter UR choice \n1.push\n2.pop\n3.peek\n4.display \n");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                push();
                break;
            }
        case 2:
            {
                pop();
                break;
            }
        case 3:
            {
                peek();
                break;
            }
        case 4:
            {
                display();
                break;
            }
        default:
        printf("Entered invalid option");
    }
    printf("\nEnter greater than 1 to continue else 0 : ");
    scanf("%d",&choice);
    }
}

