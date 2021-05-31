#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail,*prev;
int choice=1,choose,count=0,d;

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

void Rearrange()
{
   temp=head;
   if(count%2==0)
   {
       d=((count-1)/2)+1;
   }
   else
   {
       d=(count-1)/2;
   }
   if(head==0)
   {
       printf("\nList is empty\n");
   }
   else if(head->next==0)
   {
       printf("The output is : ");
       printf("%d",temp->data);
   }
   else if(head->next->next==0)
   {
        printf("The output is : ");
       while(temp!=NULL)
       {
           printf("%d ",temp->data);
           temp=temp->next;
       }
   }
   else
   {
       printf("%d",d);
       while(d)
       {
          tail->next=temp->next;
          temp->next=temp->next->next;
          tail=tail->next;
          tail->next=0;
          temp=temp->next;
          d--;
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
        printf("Enter ur choice\n 1.insert\n 2.Rearrange\n 3.Display\n");
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
                Rearrange();
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

