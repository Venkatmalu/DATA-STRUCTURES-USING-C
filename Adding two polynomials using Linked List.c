#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int power;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*head,*tail,*head1,*tail1,*head2,*tail2;
int choice=1,choose,x,y;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    printf("Enter the x power to insert : ");
    scanf("%d",&newnode->power);
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

void insert1()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    printf("Enter the x power to insert : ");
    scanf("%d",&newnode->power);
    newnode->next=0;
    if(head1==0)
    {
        head1=tail1=newnode;
    }
    else
    {
        tail1->next=newnode;
        tail1=newnode;
    }
}

void insert2(int x,int y)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->power=y;
    newnode->next=0;
    if(head2==0)
    {
        head2=tail2=newnode;
    }
    else
    {
        tail2->next=newnode;
        tail2=newnode;
    }
}

void check()
{
   temp=head;
   temp1=head1;
   if(head==0&&head1==0)
   {
       printf("List is empty...");
   }
   else
   {
       while(temp!=NULL || temp1!=NULL)
       {
           if((temp->power)==(temp1->power))
           {
               insert2(((temp->data)+(temp1->data)),(temp->power));
               temp=temp->next;
               temp1=temp1->next;
           }
           else
           {
               if((temp->power)>(temp1->power))
               {
                   insert2((temp->data),temp->power);
                   temp=temp->next;
               }
               else
               {
                   insert2((temp1->data),temp1->power);
                   temp1=temp1->next;
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
        while(temp->next!=NULL)
         {
           printf("%dX^%d-> ",temp->data,temp->power);
           temp=temp->next;
         }
         printf("%dX^%d",temp->data,temp->power);
    }
    printf("\n");
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
        while(temp->next!=NULL)
         {
           printf("%dX^%d-> ",temp->data,temp->power);
           temp=temp->next;
         }
         printf("%dX^%d",temp->data,temp->power);
    }
}

void resultlist()
{
    temp=head2;
    if(head2==0)
    {
        printf("List is epmty...");
    }
    else
    {
        printf("The List is : ");
        while(temp->next!=NULL)
         {
           printf("%dX^%d-> ",temp->data,temp->power);
           temp=temp->next;
         }
         printf("%dX^%d",temp->data,temp->power);
    }
}

int main()
{
    head=0;
    head1=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.insert1 \n 3.Check \n 4.Result List \n 5.Display\n");
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
             check();
                break;
            }
        case 4:
            {
                resultlist();
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
