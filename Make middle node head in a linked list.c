#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail,*prev;
int choice=1,choose,count=0,N;

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
void middleelement()
{
    temp=head;
    if(count%2==0)
    {
        int i=0;
        N=count/2;
        while(i!=N)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        temp->next=head;
        head=temp;
    }
    else
    {
        int i=0;
        N=count/2;
        while(i!=N)
        {
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=temp->next;
        temp->next=head;
        head=temp;
    }
}

void deleteelement()
{
   temp=head;
   currentnode=head;
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
         while(temp!=tail)
         {
             currentnode=temp;
             temp=temp->next;
         }
         tail=currentnode;
         tail->next=0;
         free(temp);
         count--;
         if(count==0)
         {
             head=0;
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
        printf("Enter ur choice \n 1.insert \n 2.Make middle node head in a linked list \n 3.delete element \n 4.Display\n");
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
                middleelement();
                break;
            }
        case 3:
            {
                deleteelement();
                break;
            }
        case 4:
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


