#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp;
struct node *front=0;
struct node *rear=0;
int choice=1,x;

void enqueue();
void dequeue();
void peek();
void display();

void enqueue()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
   if(front==0&&rear==0)
   {
       rear=front=newnode;
   }
   else
   {
       rear->next=newnode;
       rear=newnode;
   }
}

void dequeue()
{
    temp=front;
    if(front==0)
    {
        printf("Queue is empty...");
    }
    else
    {
        front=front->next;
        free(temp);
    }
}

void peek()
{
    if(front==0)
     {
         printf("Queue is empty...");
     }
     else
     {
           printf("Peek value = %d",front->data);
     }
}

void display()
{
    temp=front;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
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
        default :
            printf("Invalid option");
        }
        printf("\nEnter greater then 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
}
