#include<stdio.h>
#include<stdlib.h>
struct node
{
    int x,y;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail,*prev,*temp1;
int choice=1,choose,count;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the x value : ");
    scanf("%d",&newnode->x);
    printf("Enter the y value : ");
    scanf("%d",&newnode->y);
    newnode->next=0;
    if(head==0)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}

void deletekeyelementatposition()
{
   if(head==0 || head->next==0)
   {
       printf("Given list is not a valid to perform operations");
   }
   else
   {
       temp1=head;
   temp=head;
   prev=head;
   while(temp!=NULL)
   {
       if(temp!=NULL&&(prev->y)==(temp->y))
       {
            if(head==prev&&prev==temp)
             {
                prev=temp->next;
                temp=prev->next;
             }
             else
             {
               head=prev;
               prev=temp;
               temp=temp->next;
             }
          while(temp!=NULL&&(prev->y)==(temp->y))
          {
               head->next=prev->next;
               prev->next=0;
               free(prev);
               prev=temp;
               temp=temp->next;
               if(temp==NULL)
               {
                   break;
               }
          }
       }
       else if(temp!=NULL&&(prev->x)==(temp->x))
       {
           head=prev;
           prev=temp;
           temp=temp->next;
           while(temp!=NULL&&(prev->x)==(temp->x))
           {
               head->next=prev->next;
               prev->next=0;
               free(prev);
               prev=temp;
               temp=temp->next;
               if(temp==NULL)
               {
                   break;
               }
           }
       }
       else
       {
           printf("Given linked list is not valid");
           temp=0;
       }
   }
   head=temp1;
   }
}

void display()
{
    count=-1;
    temp=head;
    if(head==0)
    {
        printf("List is epmty...");
    }
    else
    {
        printf("The List is : ");
        while(temp->next!=NULL)
         {
           printf("(%d,%d)->",temp->x,temp->y);
           temp=temp->next;
           count++;
         }
         printf("(%d,%d)",temp->x,temp->y);
    }
}

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.Delete key position element\n 3.Display\n");
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
                deletekeyelementatposition();
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
