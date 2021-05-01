#include<stdio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*newnode,*temp,*tail;
int choice=1,count,pos,j=1;

void insert();
void insertatfirst();
void insertatmid();
void insertatlast();
void display();

void insert()
{
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element to insert : ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else
        {
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Enter greater than 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
    printf("The inserted elements are : ");
    display();
}

void insertatfirst()
{
    if(head==0)
    {
        printf("List is empty,create a list....");
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the element to insert at first : ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        newnode->next=head;
        newnode->prev=tail;
        tail->next=newnode;
        head=newnode;
    }
    display();
}

void insertatmid()
{
    temp=head;
    printf("Enter the position to insert element : ");
    scanf("%d",&pos);
    if(pos>=1&&pos<=count)
    {
        if(pos==1)
        {
            insertatfirst();
        }
        else if(pos==count)
        {
            insertatlast();
        }
        else
        {
            newnode=(struct node*)malloc(sizeof(struct node));
            printf("Enter the element to insert : ");
            scanf("%d",&newnode->data);
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
    display();
}

void insertatlast()
{
    temp=head;
    if(tail==0)
    {
        printf("List is empty,create a list...");
    }
    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element to insert at last : ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        tail->next=newnode;
        tail=newnode;
    }
    display();
}

void display()
{
    temp=head;
    count=0;
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        count++;
        while(temp->next!=head)
        {
            count++;
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        printf("\ncount=%d",count);
    }
}

int main()
{
    head=0;
    insert();
    insertatfirst();
    insertatmid();
    insertatlast();
}

