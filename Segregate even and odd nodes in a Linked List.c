#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail,*even,*prev,*temp1;
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
        count++;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
        count++;
    }
}

void sugregate()
{
    int count1=0;
   temp=head;
   while(temp!=NULL)
   {
       if(((temp->data)%2)!=0)
       {
           count1++;
       }
       temp=temp->next;
   }
   if(head==0)
   {
       printf("List is empty...");
   }
   else if(count1==count)
   {
       printf("\n***U Entered all odd numbers...Try Again...***\n");
   }
   else
   {
       temp=head;
       while(temp->next!=NULL)
       {
           if((temp->data)%2==0)
           {
              even=temp;
              break;
           }
           else
           {
               temp=temp->next;
           }
       }
      temp=prev=head;
      temp1=tail;
      while(temp!=temp1)
      {
          if((temp->data)%2==0)
          {
             prev=temp;
             temp=temp->next;
          }
          else if(temp==head)
          {
             prev=temp->next;
             tail->next=temp;
             tail=tail->next;
             tail->next=0;
             temp=prev;
             head=temp;
          }
          else
          {
              prev->next=temp->next;
              tail->next=temp;
              tail=tail->next;
              tail->next=0;
              temp=prev->next;
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
        printf("Enter ur choice\n 1.insert\n 2.sugregate \n 3.Display\n");
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
                sugregate();
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




