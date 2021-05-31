#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail,*currentnode,*prev,*prev1;
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
   temp=head;
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
       prev1=0;
       while(temp!=NULL)
       {
           int c=0;
           currentnode=temp->next;
           while(currentnode!=NULL)
           {
               if((temp->data)==(currentnode->data))
               {
                   if(currentnode=temp->next)
                   {
                       temp->next=currentnode->next;
                       currentnode->next=0;
                       free(currentnode);
                       currentnode=temp->next;
                   }
                   else
                   {
                        prev1->next=currentnode->next;
                        currentnode->next=0;
                        free(currentnode);
                        currentnode=prev1->next;
                   }
                   c++;
               }
               else
               {
                    prev1=currentnode;
                    currentnode=currentnode->next;
               }
           }
           if(c!=0)
           {
               prev->next=temp->next;
               temp->next=0;
               free(temp);
               temp=prev->next;
           }
           else
           {
               prev=temp;
               temp=temp->next;
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
