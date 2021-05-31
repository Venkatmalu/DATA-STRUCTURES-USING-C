#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail,*prev;
int choice=1,choose,count=0;

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

void deleteall()

{
  if(head==0)
  {
      printf("List is empty...");
  }
  else
  {
      int k;
      temp=head;
      printf("Enter the k value : ");
      scanf("%d",&k);
      if(k<=count)
      {
        if(k==1)
        {
            while(head!=0)
            {
                head=head->next;
            }
        }
        else
        {
            while(temp!=NULL)
            {
               int i=k-1;
               while(i!=0&&temp!=NULL)
               {
                  prev=temp;
                  temp=temp->next;
                  i--;
               }
               if(temp==NULL)
               {
                   break;
               }
               prev->next=temp->next;
               temp->next=0;
               free(temp);
               temp=prev->next;
            }
        }
      }
      else
      {
          printf("Invalid k value there is %d elements only ",&count);
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
        printf("Enter ur choice\n 1.insert\n 2.Remove \n 3.Display\n");
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
              deleteall();
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
