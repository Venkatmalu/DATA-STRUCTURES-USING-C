#include<stdio.h>
#define N 5
int stack1[N],stack2[N],data;
int count=0,top1=-1,top2=-1,a,i;

void push1(int);
int pop1();
void push2(int);
int pop2();
void enqueue();
void dequeue();
void peek();
void display();

void push1(int data)
{
    if(top1==N-1)
    {
        printf("overflow situation");
    }
    else
    {
        top1++;
        stack1[top1]=data;
    }
}

int pop1()
{
    return stack1[top1--];
}

void push2(int data)
{
    if(top2==N-1)
    {
        printf("overflow condition");
    }
    else
    {
        top2++;
        stack2[top2]=data;
    }
}

int pop2()
{
    return stack2[top2--];
}

void enqueue()
{
    printf("Enter the data to insert : ");
    scanf("%d",&data);
    push1(data);
    count++;
}

void dequeue()
{
    if(top1==-1&&top2==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        for(i=0;i<count;i++)
        {
            a=pop1();
            push2(a);
        }
        pop2();
        count--;
        for(i=0;i<count;i++)
        {
            a=pop2();
            push1(a);
        }
    }
}

void peek()
{
    printf("Peek value is : %d",stack1[0]);
}
void display()
{
    if(top1==-1)
    {
        printf("Queue is empty...");
    }
    else
    {
        printf("The Queue is : ");
        for(i=0;i<=top1;i++)
         {
            printf("%d ",stack1[i]);
         }
    }
}
void main()
{
    int choice=1;
    while(choice)
    {
        printf("Enter UR choice \n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                enqueue();
                break;
            }
        case 2:
            {
                dequeue();
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
        default :
            printf("Invalid option");
    }
    printf("\nEnter greater than 1 to continue else 0 : ");
    scanf("%d",&choice);
}
}
