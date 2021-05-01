#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*tail;
int choice=1,count,pos,j=1;

void insert();
void display();
void insertatstart();
void insertatend();

void insert()
{

    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data to insert : ");
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
        temp->next=head;
        printf("Enter greater the 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
    display();
}

void insertatstart()
{
    tail=temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        head=newnode;
    }
    display();
}

void insertatmid()
{
    temp=head;
   printf("\nEnter the position to insert the element : ");
   scanf("%d",&pos);
   if(pos>1&&pos<count)
   {
       newnode=(struct node*)malloc(sizeof(struct node));
       printf("\nEnter the element to insert :");
       scanf("%d",&newnode->data);
       while(j<pos-1)
       {
           temp=temp->next;
           j++;
       }
       newnode->next=temp->next;
       temp->next=newnode;
   }
   else
   {
        printf("\nThe position is invalid");
   }
   display();
}

void insertatend()
{
    tail=temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element to insert last : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(tail==0)
    {
        tail=newnode;
    }
    else
    {
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    display();
}
void display()
{
    count=0;
    temp=head;
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
        printf("%d ",temp->data);
    }
}

int main()
{
    head=0;
    insert();
    insertatstart();
    insertatmid();
    insertatend();
}

