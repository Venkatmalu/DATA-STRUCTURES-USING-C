#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*head,*tail,*smallfirst,*smallend,*equalfirst,*equalend,*greaterfirst,*greaterend;
int choice=1,choose,count=0,count1=0,checkcount=0;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
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
    if(smallfirst==0)
    {
        smallfirst=smallend=newnode;
    }
    else
    {
        smallend->next=newnode;
        smallend=newnode;
    }
}

void insert2(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(equalfirst==0)
    {
        equalfirst=equalend=newnode;
    }
    else
    {
        equalend->next=newnode;
        equalend=newnode;
    }
}

void insert3(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(greaterfirst==0)
    {
        greaterfirst=greaterend=newnode;
    }
    else
    {
        greaterend->next=newnode;
        greaterend=newnode;
    }
}

void rearrange()
{
  temp=head;
  if(head==0)
  {
      printf("List is empty...");
  }
  else
  {
      int x;
      printf("Enter the x value : ");
      scanf("%d",&x);
      while(temp!=NULL)
      {
          if((temp->data)<x)
          {
              insert1((temp->data));
          }
          else if((temp->data)==x)
          {
              insert2((temp->data));
          }
          else
          {
              insert3((temp->data));
          }
          temp=temp->next;
      }
     smallend->next=equalfirst;
     equalend->next=greaterfirst;
     head=smallfirst;
  }
}

void display()
{
    count=0;
    temp=head;
    if(head==0)
    {
        printf("List is epmty...");
    }
    else
    {
        printf("The List is : ");
        while(temp!=NULL)
         {
           printf("%d ",temp->data);
           temp=temp->next;
           count++;
         }
    }
}

int main()
{
    head=0;
    smallfirst=0;
    equalfirst=0;
    greaterfirst=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.Rearrange \n 3.Display\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            {
                insert();
                break;
            }
        case 2:
            {
             rearrange();
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
