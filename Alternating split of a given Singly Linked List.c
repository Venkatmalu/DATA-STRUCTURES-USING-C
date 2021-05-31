#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail,*head1,*tail1,*prev;
int choice=1,choose,count=0,k,x;

void insert(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(head==0)
    {
        head=tail=newnode;
        count++;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
        count++;
    }
}

void insert1(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(head1==0)
    {
        head1=tail1=newnode;
    }
    else
    {
        tail1->next=newnode;
        tail1=newnode;
    }
}

void remov()
{
  temp=head;
  prev=head;
  if(head==0)
  {
      printf("List is empty...");
  }
  else
  {
      while(temp!=NULL)
      {
          temp=temp->next;
          if(temp==NULL)
          {
              break;
          }
          prev->next=temp->next;
          insert1((temp->data));
          free(temp);
          prev=prev->next;
          temp=prev;
      }
  }
}

void display()
{
    temp=head;
    if(head==0)
    {
        printf("List1 is epmty...");
    }
    else
    {
        printf("The List1 is : ");
        while(temp!=NULL)
         {
           printf("%d ",temp->data);
           temp=temp->next;
         }
    }
    display1();
}

void display1()
{
    temp=head1;
    if(head1==0)
    {
        printf("List2 is epmty...");
    }
    else
    {
        printf("The List2 is : ");
        while(temp!=NULL)
         {
           printf("%d ",temp->data);
           temp=temp->next;
         }
    }
}

int main()
{
    head=0,head1=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.reverse  \n 3.Display\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            {
                  printf("Enter the element to insert : ");
                  scanf("%d",&x);
                insert(x);
                break;
            }
        case 2:
            {
                remov();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        default :
            {
                printf("Invalid option");
                break;
            }
        }
        printf("\nEnter greater than 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
}
