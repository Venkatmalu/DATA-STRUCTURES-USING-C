#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*temp,*newnode,*tail;
int choice=1,count=0,pos,x;

void insert();
void print();
void insertatstart();
void insertatmid();
void insertatend();

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
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=tail->next;
        }
        printf("Enter choice graeter then 1 to continue else 0 :");
        scanf("%d",&choice);
    }
}

void insertatstart()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert : ");
    scanf("%d",&x);
    newnode->data=x;
    newnode->prev=0;
    newnode->next=0;
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
    }
    print();
}

void insertatend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to insert : ");
    scanf("%d",&x);
    newnode->data=x;
    newnode->prev=0;
    newnode->next=0;
    if(tail==0)
    {
        printf("List is empty");
    }
    else
    {
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    print();
}

void insertatmid()
{
    temp=head;
    int j=1;
    printf("\nEnter the position to insert : ");
    scanf("%d",&pos);
    if(pos<1&&pos>count)
    {
        printf("Entered position is invalid");
    }
    else
    {
       if(pos==1)
       {
           insertatstart();
       }
       else
       {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("\nEnter the element to insert : ");
            scanf("%d",&x);
            newnode->data=x;
            newnode->prev=0;
            newnode->next=0;
            while(j<pos-1)
             {
                temp=temp->next;
                j++;
             }
             newnode->prev=temp;
             newnode->next=temp->next;
             temp->next=newnode;
             newnode->next->prev=newnode;
       }
    }
    print();
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
int main()
{
    head=0;
    insert();
    print();
    printf("\n count=%d",count);
    insertatstart();
    insertatend();
    insertatmid();
}

