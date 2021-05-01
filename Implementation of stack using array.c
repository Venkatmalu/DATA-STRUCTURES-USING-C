#include<stdio.h>
#define N 5
int stack[N],top=-1,x,i;

void push();
void pop();
void peek();
void display();

void push()
{
    int x;
    printf("Enter the value to push : ");
    scanf("%d",&x);
    if(top==N-1)
    {
        printf("occuring overflow...");
    }
    else
    {
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("underflow situation occuring");
    }
    else
    {
        top--;
    }
}

void peek()
{
    if(top==-1)
    {
        printf("\nThe is no elements,so insert....");
    }
    else
    {
        printf("\nThe top = %d",stack[top]);
    }
}
void display()
{
    for(i=top;i>=0;i--)
    {
        printf("%d ",stack[i]);
    }
}

int main()
{
    int choice=1;
    while(choice)
    {
        printf("Enter UR choice \n1.push\n2.pop\n3.peek\n4.display\n");
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
