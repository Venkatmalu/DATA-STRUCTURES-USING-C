#include<stdio.h>
#define N 5
int stack[N],top=-1,queue[N],front,rear,x;
front=-1;
rear=-1;

void push(int x)
{
    if(top==N-1)
    {
        printf("stack is full...");
    }
    else
    {
        stack[++top]=x;
    }
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty...");
    }
    else
    {
        return stack[top--];
    }
}

void enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
       front=rear=0;
       queue[rear]=x;
    }
    else if(rear==N-1)
    {
        printf("Queue is full...");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

int dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("Queue is empty...");
    }
    else if(front==rear)
    {
       return queue[front];
    }
    else
    {
        return queue[front++];
    }
}

void reverse()
{
   if(front==-1&&rear==-1)
   {
       printf("queue is empty...");
   }
   else if(front==rear)
   {
       printf("%d",queue[rear]);
   }
   else
   {
       do
       {
           x=dequeue();
           push(x);
       }while(front!=rear);
       if(front==rear)
       {
           x=dequeue();
           front=rear=-1;
           push(x);
       }
       while(top!=-1)
       {
           x=pop();
           enqueue(x);
       }
   }
}

void display()
{
    int i=front;
    if(front==-1&&rear==-1)
    {
        printf("Queue ie empty...");
    }
    else
    {
        printf("the queue is : ");
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[i]);
    }
}

void main()
{
    int choice=1,choose;
    while(choice)
    {
        printf("choose ur option \n1.enqueue\n2.Dequeue\n3.Reverse\n4.Display\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            {
                printf("Enter the element to insert : ");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                reverse();
                break;
            }
        case 4:
            {
                display();
                break;
            }
        default :
            {
                printf("Invalid option");
            }
        }
        printf("\nEnter greater then 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
}
