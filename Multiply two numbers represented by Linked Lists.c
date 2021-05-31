#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*head,*tail,*head1,*tail1;
int choice=1,choose,count=0,count1=0,count3=0,x,sum3=0;

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

void insert1()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head1==0)
    {
        head1=tail1=newnode;
        count1++;
    }
    else
    {
        tail1->next=newnode;
        tail1=newnode;
        count1++;
    }
}

void multiply()
{
   temp=head;
   int sum=0,sum1=0,tmp;
   while(temp!=NULL)
   {
       sum=sum*10+temp->data;
       temp=temp->next;
   }
   temp=head1;
   while(temp!=NULL)
   {
       sum1=sum1*10+temp->data;
       temp=temp->next;
   }
   sum3=sum*sum1;
   printf("\nThe Output is : %d\n",sum3);
}

void display()
{
    count=0;
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
    display1();
}

void display1()
{
    temp=head1;
    if(head1==0)
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
        printf("Enter ur choice\n 1.insert\n 2.insert1 \n 3.Multiply\n 4.Display\n");
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
                insert1();
                break;
            }
        case 3:
            {
                multiply();
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

