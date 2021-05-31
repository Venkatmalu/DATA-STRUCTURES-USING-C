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

void sort()
{
  temp=head;
  int n0=0,n1=0,n2=0;
  if(head==0)
  {
      printf("List is empty.....");
  }
  else
  {
      while(temp!=NULL)
      {
          if((temp->data)==0)
          {
              n0++;
          }
          else if((temp->data)==1)
          {
              n1++;
          }
          else
          {
              n2++;
          }
          temp=temp->next;
      }
      temp=head;
      while(n0!=0 || n1!=0 || n2!=0)
      {
          if(n0!=0)
          {
              temp->data=0;
              temp=temp->next;
              n0--;
          }
          else if(n1!=0)
          {
              temp->data=1;
              temp=temp->next;
              n1--;
          }
          else
          {
              temp->data=2;
              temp=temp->next;
              n2--;
          }
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
        printf("Enter ur choice\n 1.insert\n 2.sort  \n 3.Display\n");
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
               sort();
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
