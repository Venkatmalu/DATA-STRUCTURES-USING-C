#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*nextnode,*head,*tail,*prev;
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

void reverse()
{
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        prev=0;
        nextnode=currentnode=head;
        while(nextnode!=0)
        {
            nextnode=nextnode->next;
            currentnode->next=prev;
            prev=currentnode;
            currentnode=nextnode;
         }
    }
      head=prev;
}

void add()
{
  if(head==0)
  {
      printf("List is empty...");
  }
  else
  {
       reverse();
       temp=head;
       int sum=1;
       while(temp!=NULL)
       {
           sum=sum+(temp->data);
           if(sum<9)
           {
               temp->data=sum;
               sum=0;
           }
           else
           {
               temp->data=sum%2;
               sum=1;
           }
           temp=temp->next;
       }
       reverse();
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
        printf("Enter ur choice\n 1.insert\n 2.Add\n 3.Display\n");
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
               add();
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

