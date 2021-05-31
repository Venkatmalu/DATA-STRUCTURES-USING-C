#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*prev,*currentnode,*head,*tail;
int choice=1,choose,count=0,N;

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
void insertnode()
{
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
       int n,d;
       printf("Enter the nth node from last node : ");
       scanf("%d",&n);
      if(n<=count)
      {
          newnode=(struct node*)malloc(sizeof(struct node));
         printf("Enter the element to insert : ");
         scanf("%d",&newnode->data);
         newnode->next=0;
         temp=head;
         d=(count-n)+1;
         while(d)
         {
             prev=temp;
             temp=temp->next;
             d--;
         }
         prev->next=newnode;
         newnode->next=temp;
      }
      else
      {
          printf("There are %d nodes only....");
      }

   }
}

void deleteelement()
{
   temp=head;
   currentnode=head;
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
         while(temp!=tail)
         {
             currentnode=temp;
             temp=temp->next;
         }
         tail=currentnode;
         tail->next=0;
         free(temp);
         count--;
         if(count==0)
         {
             head=0;
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
         printf("c=%d",count);
    }
}

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.Insert \n 3.delete element \n 4.Display\n");
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
               insertnode();
                break;
            }
        case 3:
            {
                deleteelement();
                break;
            }
        case 4:
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
