#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail,*prev1,*prev;
int choice=1,choose,count=0,x,y;

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

void swap()
{
   temp=head;
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
       while(temp!=NULL && temp->next!=NULL)
       {
           x=temp->data;
           temp->data=temp->next->data;
           temp->next->data=x;
           temp=temp->next->next;
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
         }
    }
}

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.swap \n 3.Display\n");
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
                swap();
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



