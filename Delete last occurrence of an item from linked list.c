#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*prev,*head,*tail,*temp1;
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
   int key;
   count=0;
   temp=head;
   if(head==0)
   {
       printf("list is empty...");
   }
   else
   {
       printf("Enter the key value : ");
       scanf("%d",&key);
       while(temp!=NULL)
       {
           if(key==(temp->data))
              {
                 count++;
                 temp1=temp;
                 temp=temp->next;
              }
              else
              {
                  temp=temp->next;
              }
       }
       if(count==1)
       {
           printf("\n***There is only one element in the list as similar as key element***\n");
       }
       else
       {
           if(temp1==tail)
           {
               temp=head;
               while(temp->next!=tail)
               {
                   temp=temp->next;
               }
               temp->next=0;
               tail=temp;
           }
           else
           {
               temp=head;
               while(temp!=NULL)
               {
                   if(temp1==temp)
                   {
                       prev->next=temp->next;
                       temp1->next=0;
                       free(temp1);
                       break;
                   }
                   else
                   {
                       prev=temp;
                       temp=temp->next;
                   }
               }
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
        printf("Enter ur choice\n 1.insert\n 2. Delete element \n 3.Display \n");
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
