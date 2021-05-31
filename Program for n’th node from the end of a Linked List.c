#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail;
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

void findNthelementfromlast()
{
    printf("Enter the Nth element from last node : ");
    scanf("%d",&N);
  temp=head;
  if(temp==0)
  {
      printf("List is empty...");
  }
  else
  {
    if(N==0)
    {
        printf("\n***0 Is a Invalid node in the list so Enter greater than 0***\n");
    }
    else
    {
         if(N<=count)
        {
         int i=0,pos=count-N;
         while(i!=pos)
         {
             temp=temp->next;
             i++;
         }
         printf("\nThe %d element from last node is : %d\n",N,temp->data);
       }
      else
      {
         printf("\nThere is %d elements only...\n",count);
      }
    }
  }
}

void findNthnode()
{
    printf("Enter the Nth position to display : ");
    scanf("%d",&N);
    temp=head;
    if(head==0)
    {
        printf("List is empty...");
    }
    else
    {
        if(N<=count)
        {
            int i=0;
            while(i!=N)
            {

                temp=temp->next;
                i++;
            }
            printf("\nThe Index[%d] element is : %d\n",N,temp->data);
        }
        else
        {
            printf("Invalid position");
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
        printf("Enter ur choice\n 1.insert\n 2.find Nth from last element\n 3.Find Nth element \n 4.Delete element\n 5.Display\n");
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
                findNthelementfromlast();
                break;
            }
        case 3:
            {
                findNthnode();
                break;
            }
        case 4:
            {
                deleteelement();
                break;
            }
        case 5:
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
