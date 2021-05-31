#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail;
int choice=1,choose,count,count1=0;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
    {
        head=tail=newnode;
        count1++;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
        count1++;
    }
}

void counter()
{
   int key;
   count=0;
   printf("Enter the key element to count its occurence(the element must in the list) : ");
   scanf("%d",&key);
   temp=head;
   if(head==0)
   {
       printf("\nList is empty...\n");
   }
   else
   {
         while(temp!=NULL)
         {
           if(key==(temp->data))
          {
              count++;
              temp=temp->next;
          }
          else
          {
              temp=temp->next;
          }
        }
        if(count==0)
        {
            printf("\n***U Entered a Invalid key element***\n");
        }
        else
        {
            printf("\nThe %d key element is occured %d\n",key,count);
        }
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
         if(count1==0)
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
        printf("Enter ur choice\n 1.insert\n 2.counter\n 3.delete element \n 4.Display\n");
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
                counter();
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

