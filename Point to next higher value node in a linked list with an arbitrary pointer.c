#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*arbit;
};
struct node *newnode,*temp,*currentnode,*head,*tail,*prev;
int choice=1,choose,count=0,N;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    newnode->arbit=0;
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
void point()
{
   temp=prev=head;
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
     while(prev!=NULL)
     {
           temp=prev->next;
           if(temp==NULL)
           {
               if((prev->data)<(head->data))
               {
                   prev->arbit=head;
               }
           }
       while(temp!=NULL)
       {
           if((prev->data)<(temp->data))
           {
               prev->arbit=temp;
               break;
           }
           else
           {
               temp=temp->next;
           }
       }
       prev=prev->next;
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
        printf("Enter ur choice\n 1.insert\n 2.Point Arbitary \n 3.Display\n");
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
               point();
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


