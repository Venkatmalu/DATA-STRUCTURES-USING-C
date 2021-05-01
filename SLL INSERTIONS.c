#include<stdio.h>
#include<stdlib.h>
struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*temp,*newnode;
    int choice=1,count,j;
void insert();
void insertatstart(int);
void insertatmid(int,int);
void insertatend(int);

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

void insertatstart(x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=head;
    head=newnode;
    print();
}

void insertatmid(x,pos)
{
    temp=head;
    if(pos>count)
    {
        printf("\nInvalid position");
    }
    else
    {
        j=1;
       while(j<pos)
       {
           temp=temp->next;
           j++;
       }
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=temp->next;
    temp->next=newnode;
    print();
}

void insertatend(x)
{
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    temp->next=newnode;
     print();
}
void print()
{
    count=0;
    temp=head;
   while(temp!=0)
  {
      printf("%d ",temp->data);
      temp=temp->next;
      count++;
  }
}
void main()
{
   head=0;
   int n,x,i,pos;
   insert();
   print();
   printf("\nEnter the number of elements to insert :");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("\nEnter the element to insert : ");
      scanf("%d",&x);
      insertatstart(x);
   }
   printf("\nEnter the number of elements to insert :");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("\nEnter the element to insert : ");
      scanf("%d",&x);
      printf("\nEnter the position to insert : ");
      scanf("%d",&pos);
      insertatmid(x,pos);
   }
   printf("\nEnter the number of elements to insert :");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("\nEnter the element to insert : ");
      scanf("%d",&x);
      insertatend(x);
   }
}

