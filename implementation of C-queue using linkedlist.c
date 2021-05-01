#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp,*newnode;
struct node *front=0;
struct node *rear=0;

void enqueue();
void dequeue();
void peek();
void display();

void enqueue()
{
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("Enter the data to insert : ");
   scanf("%d",&newnode->data);
   newnode->next=0;
   if(front==0&&rear==0)
   {
       front=rear=newnode;
   }
   else
   {
       rear->next=newnode;
       newnode->next=rear;
       rear=newnode;
   }
}

void dequeue()
{
    if(front==0&&rear==0)
    {
        printf("Queue is empty...");
    }
    else if(front==rear)
    {
        front=rear=0;
    }
    else
    {
        rear->next=front->next;
        front=front->next;
    }
}
void peek()
{
    if(front==0&&rear==0)
    {
        printf("Queue is empty...");
    }
    else
    {
        printf("Peek = %d",front->data);
    }
}

void display()
{
    temp=front;
    if(front==0&&rear==0)
    {
        printf("Queue is empty...");
    }
    else
    {
       while(temp!=rear)
       {
        printf("%d ",temp->data);
        temp=temp->next;
       }
        printf("%d",temp->data);
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
