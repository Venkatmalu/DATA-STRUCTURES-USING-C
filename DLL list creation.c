#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*temp,*newnode;
int choice=1,count=0;

void insert()
{
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data to insert : ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
        printf("Enter choice graeter then 1 to continue else 0 :");
        scanf("%d",&choice);
    }
}

void print()
{
    temp=head;
    while(temp!=0)
    {
        count++;
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    head=0;
    insert();
    print();
    printf("\ncount=%d",count);
}
