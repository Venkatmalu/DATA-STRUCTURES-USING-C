#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail,*prev;
int choice=1,choose,count=0,k;

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
  printf("Enter the key value : ");
  scanf("%d",&k);
  if(k<count)

  {
          int i=0;
          temp=head;
          while(i!=k-1)
          {
            prev=temp;
            temp=temp->next;
            prev->next=temp->next;
            temp->next=head;
            head=temp;
            temp=prev;
            i++;
          }
          while(temp!=NULL)
          {
              struct node *temp1=prev,*head1;
              head1=prev=prev->next;
              temp=prev->next;
              int i=0;
              while(i!=k-1)
              {
                  prev=temp;
                  temp=temp->next;
                  i++;
              }
               if(temp==NULL)
              {
                  break;
              }
              i=0;
              temp1=prev;
              head1=prev=prev->next;
              temp=prev->next;
              while(i!=k-1)
              {
                  if(temp==NULL)
                   {
                       break;
                   }
                   prev->next=temp->next;
                   temp1->next=temp;
                   temp->next=head1;
                   head1=temp;
                   temp=prev->next;
                   i++;
              }
          }
  }
  else
  {
      printf("\n***There is %d node only...***\n",count);
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
    printf("\n***Entering Number of elements must be divisible by giving K value***");
    printf("\n              ***ELSE OUTPUT MAY BE WRONG***\n\n");
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.reverse  \n 3.Display\n");
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
                reverse();
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







