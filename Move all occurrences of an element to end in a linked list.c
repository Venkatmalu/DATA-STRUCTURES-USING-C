#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail;
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

void move()
{
    int key;
   temp=head;
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
       printf("Enter the Key value(Key value Must Exist in The List) : ");
       scanf("%d",&key);
       int temp1=count;
       while(count)
       {
               if(head==temp)
               {
                   if(key==(temp->data))
                   {
                     tail->next=temp;
                     tail=tail->next;
                     temp=temp->next;
                     head=temp;
                   }
                   else
                   {
                       tail->next=temp;
                       temp=temp->next;
                   }
               }
               else
               {
                   if(key==(temp->data))
                   {
                       tail->next->next=temp->next;
                       temp->next=tail->next;
                       tail->next=temp;
                       tail=tail->next;
                       temp=tail->next->next;
                   }
                   else
                   {
                       tail->next=temp;
                       temp=temp->next;
                   }
               }
               count--;
       }
       tail->next=0;
       count=temp1;
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
        printf("Enter ur choice\n 1.insert\n 2.Move \n 3.Display\n");
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
             move();
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
