#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    int priority;
    struct node *next;
    struct node *prev;
};
struct node *newnode,*temp;
struct node *head=0;
int choice=1;

void enqueue()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert : ");
    scanf("%d",&newnode->data);
    printf("Enter the priority of the data : ");
    scanf("%d",&newnode->priority);
    newnode->next=0;
    newnode->prev=0;
    if(head==0)
    {
        head=newnode;
    }
    else
    {
        if(head->priority>newnode->priority)
        {
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
        else
        {
            temp=head;
            while(temp->next!=NULL && temp->next->priority<=newnode->priority)
            {
                temp=temp->next;
            }
           if(temp->next!=NULL)
           {
                temp->next->prev=newnode;
                newnode->next=temp->next;
                newnode->prev=temp;
                temp->next=newnode;
           }
           else
           {
               temp->next=newnode;
               newnode->prev=temp;
           }
        }
    }
}

void dequeue()
{
    temp=head;
    if(head==0)
    {
        printf("Queue is empty...");
    }
    else
    {
        head=head->next;
        free(temp);
    }
}

void peek()
{
    if(head==0)
    {
        printf("Queue is empty...");
    }
    else
    {
        printf("The peek value is : %d",head->data);
    }
}

void display()
{
    temp=head;
    if(head==0)
    {
        printf("Queue is empty...");
    }
    else
    {
        printf("The queue is : ");
        while(temp->next!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
    }
}

void main()
{
    int choose;
    while(choice)
    {
        printf("Choose any one option \n1.Enqueue\n2.Dequeue\n3.Peek value\n4.Display\n");
        scanf("%d",&choose);
        switch(choose)
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
            {
                printf("Invalid option");
            }
        }
        printf("\nEnter greater than 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
}


