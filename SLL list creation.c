#include<stdio.h>
#include<stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *head,*temp,*newnode;
    head=0;
    int choice=1;
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
    printf("Enter 1 to continue else 0 :");
    scanf("%d",&choice);
  }
  temp=head;
  while(temp!=0)
  {
      printf("%d ",temp->data);
      temp=temp->next;
  }
  getch();
}
