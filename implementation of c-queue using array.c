#include<stdio.h>
#define N 5
int queue[N];
int front,rear,x;
front=-1;
rear=-1;
void enqueue();
void dequeue();
void peek();
void display();

void enqueue()
{
    printf("Enter the element to insert : ");
    scanf("%d",&x);
    if(front==-1&&rear==-1)
    {
       front=rear=0;
       queue[rear]=x;
    }
    else if((rear+1)%N==front)
    {
        printf("Queue is full");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

void peek()
{
   if(front==-1&&rear==-1)
   {
       printf("Queue is empty...");
   }
   else
   {
       printf("%d",queue[front]);
   }
}

void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("queue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%N;
    }
}
void display()
{
    int i=front;
    if(front==-1&&rear==-1)
    {
        printf("Queue is empty...");
    }
    else
        printf("The Queue is : ");
    {
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
         printf("%d ",queue[i]);
    }
}
void main()
{
    int choice=1;
   while(choice)
   {
       printf("\nEnter UR choice \n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n");
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
       default:
        printf("Invalid option");
       }
       printf("\nEnter greater than 1 to continue else 0  :  ");
       scanf("%d",&choice);
   }

}

