#include<stdio.h>
#include<stdlib.h>
struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*newnode,*prev,*currentnode,*nextnode,*temp;
    int choice=1;
void insert();
void reverse();

void insert()
{
    while(choice)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data :");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
    {
      head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    printf("\nEnter greater than 1 to continue else 0 :");
    scanf("%d",&choice);
  }
}

void reverse()
{
    if(head->next==0)
    {
        printf("List is empty");
    }
    else
    {
        prev=0;
        nextnode=currentnode=head;
        while(nextnode!=0)
        {
            nextnode=nextnode->next;
            currentnode->next=prev;
            prev=currentnode;
            currentnode=nextnode;
         }
    }
      head=prev;
    printf("\nAfter reversing the linked list is : ");
    print();
}

void print()
{
    temp=head;
    while(temp!=0)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void main()
{
    insert();
    print();
    reverse();
}

