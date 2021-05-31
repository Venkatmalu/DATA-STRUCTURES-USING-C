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
   printf("Enter the first value : ");
   scanf("%d",&x);
   printf("Enter the second value : ");
   scanf("%d",&y);
   temp=head;
   while(temp!=NULL)
   {
       if((temp->data)==x)
       {
           count++;
           prev=temp;
           break;
       }
       else
       {
           temp=temp->next;
       }
   }
   temp=head;
   while(temp!=NULL)
   {
       if((temp->data)==y)
       {
           count++;
           prev1=temp;
           break;
       }
       else
       {
           temp=temp->next;
       }
   }
   if(count==2)
   {
       prev->data=y;
       prev1->data=x;
   }
   else
   {
       printf("\n***Entered keys are not present in the list***\n");
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


