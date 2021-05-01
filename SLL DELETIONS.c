#include<stdio.h>
#include<stdlib.h>
struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*temp,*newnode,*prev;
    int choice=1,count,j,pos;
void insert();
void deleteatstart();
void deleteatmid();
void deleteatend();

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

void deleteatstart()
{
   if(head==0)
   {
       printf("List is empty");
   }
   else
   {
       temp=head;
       head=head->next;
       free(temp);
   }
   printf("\nAfter deleting first element,the remaining elements are :");
   print();
}

void deleteatmid()
{
    temp=head;
    j=1;
    printf("\nEnter the position to delete : ");
    scanf("%d",&pos);
    if(pos>count)
    {
        printf("Invalid position");
    }
    else
    {
      while(j<pos)
      {
        prev=temp;
        temp=temp->next;
        j++;
      }
      prev->next=temp->next;
      free(temp);
    }
    printf("\nAfter deleting the specified position element,the remaining elements are : ");
    print();
}

void deleteatend()
{
    temp=head;
    while(temp->next!=0)
    {
        prev=temp;
        temp=temp->next;
    }
    if(head==temp)
    {
        head=0;
    }
    else
    {
        prev->next=0;
    }
    free(temp);
    printf("\nAfter deleting last element,the remaining elements are : ");
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
    insert();
    deleteatstart();
    deleteatend();
    deleteatmid();
}
