#include<stdio.h>
#define N 5
int queue[N];
int front,rear,x;
front=-1;
rear=-1;
void Push();
void Pop();
void Peek();
void display();

void Push()
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
        printf("Stack is full");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

void Peek()
{
   if(front==-1&&rear==-1)
   {
       printf("Stack is empty...");
   }
   else
   {
       printf("The Peek value is : %d",queue[rear]);
   }
}

void Pop()
{
    if(front==-1&&rear==-1)
    {
        printf("Stack is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        rear--;
    }
}
void display()
{
    int i=(front+rear)%N;
    if(front==-1&&rear==-1)
    {
        printf("Stack is empty...");
    }
    else
    {
        printf("The stack is : ");
        while(i!=front)
        {
            printf("%d ",queue[i]);
            i=(i-1)%N;
        }
         printf("%d ",queue[i]);
    }
}
void main()
{
    int choice=1;
   while(choice)
   {
       printf("\nEnter UR choice \n1.Push\n2.Pop\n3.Peek\n4.Display\n");
       scanf("%d",&choice);
       switch(choice)
       {
       case 1:
        {
            Push();
            break;
        }
       case 2:
        {
            Pop();
            break;
        }
       case 3:
        {
            Peek();
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

