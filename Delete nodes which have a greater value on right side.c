#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail,*prev;
int choice=1,choose,count;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
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

void deleteelement()
{
   temp=head;
   prev=head;
   if(head==0)
   {
       printf("The List is empty...");
   }
   else
   {
       while(temp!=NULL)
       {
           if(temp==head)
           {
               if((prev->data)<(temp->next->data))
                {
                    head=temp->next;
                    prev=head;
                    free(temp);
                    temp=prev;
                    if(temp->next==NULL)
                    {
                        break;
                    }
                }
                else
                {
                    prev=temp;
                    temp=temp->next;
                }
           }
           else
           {
               if((temp->data)<(temp->next->data))
               {
                   prev->next=temp->next;
                   free(temp);
                   prev=prev->next;
                   temp=prev->next;
               }
               else
               {
                   prev=temp;
                   temp=temp->next;
                   if(temp->next==NULL)
                   {
                      break;
                   }
               }
           }
       }
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
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.delete element \n 3.Display\n");
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
                deleteelement();
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



