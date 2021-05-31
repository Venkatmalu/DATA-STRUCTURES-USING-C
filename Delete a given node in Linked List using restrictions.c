#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*tail;
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

void deletekeyelementatposition()
{
   int key;
   printf("Enter the key position element to delete : ");
   scanf("%d",&key);
   temp=head;
   currentnode=head;
   if(head==0)
   {
       printf("\nList is empty\n");
   }
   else
   {
          if(key==0)
   {
       head=head->next;
       free(temp);
   }
   else
   {
        if(key<=count)
        {
           int i=0;
           while(i!=key)
           {
             currentnode=temp;
             temp=temp->next;
             i++;
           }
            currentnode->next=temp->next;
            free(temp);
        }
        else
        {
            printf("\nPosition Invalid\n");
        }
   }
   }
}

void display()
{
    count=-1;
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
           count++;
         }
    }
}

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.Delete key position element\n 3.Display\n");
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
                deletekeyelementatposition();
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

