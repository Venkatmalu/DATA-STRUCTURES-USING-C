#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*tail,*prev;
int choice=1,count,pos,j=1;

void insert();
void display();
void deleteatfirst();
void deleteatmid();
void deleteatlast();

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

void deleteatfirst()
{
    tail=temp;
    temp=head;
    if(head==0)
    {
        printf("There is no nodes to delete");
    }
    else if(head->next==tail)
    {
        tail=0;
        free(temp);
        head=0;
    }
    else
    {
        head=head->next;
        tail->next=head;
        free(temp);
    }
    printf("\nAfter deleting the first element : ");
    display();
}

void deleteatmid()
{
    printf("\nEnter the position to delete the element : ");
    scanf("%d",&pos);
  if(pos>0&&pos<count+1)
   {
    if(pos==1)
    {
        deleteatfirst();
    }
    else if(pos==count)
    {
        deleteatlast();
    }
    else
    {
        temp=head;
        while(j<pos)
        {
            prev=temp;
            temp=temp->next;
            j++;
        }
        prev->next=temp->next;
        free(temp);
        printf("\nAfter deleting the specified element : ");
        display();
    }
   }
   else
   {
       printf("\nPosition is invalid");
   }
}

void deleteatlast()
{
    temp=head;
    if(count==0)
    {
        printf("\nThere is no nodes to delete");
    }
    else if(head->next==tail)
    {
        tail=0;
        free(temp);
        head=0;
    }
    else
    {
        while(temp->next!=tail)
         {
            temp=temp->next;
         }
         temp->next=tail->next;
         free(tail);
         tail=temp;
    }
    printf("\nAfter deleting the last element : ");
   display();
}
void display()
{
    temp=head;
    count=0;
    if(head==0)
    {
        printf("\nList is empty");
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
    }
}

int main()
{
    head=0;
    insert();
    deleteatfirst();
    deleteatmid();
    deleteatlast();
}
