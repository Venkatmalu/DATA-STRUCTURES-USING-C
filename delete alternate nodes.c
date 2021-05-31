#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail,*prev;
int choice=1,choose,count=0,k;

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

void remov()
{
  temp=prev=head;
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
        printf("List is epmty...");
    }
    else
    {
        printf("The List is : ");
        while(temp!=NULL)
         {
           printf("%d ",temp->data);
           temp=temp->next;
         }
    }
}

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.reverse  \n 3.Display\n");
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







