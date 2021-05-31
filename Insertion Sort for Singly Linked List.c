#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*prev,*head,*tail,*head1,*tail1,*temp1;
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

void insert1(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(head1==0)
    {
        head1=tail1=newnode;
    }
    else
    {
        temp=head1;
        while(temp!=NULL)
        {
            if((temp->data)>x)
            {
                break;
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
        }
       if(temp==head1)
        {
            newnode->next=head1;
            head1=newnode;
        }
        else
        {
            prev->next=newnode;
            newnode->next=temp;
        }
    }
}

void sort()
{
   temp1=head;
   if(head==0)
   {
       printf("List is empty....");
   }
   else
   {
       while(temp1!=NULL)
       {
           insert1((temp1->data));
           temp1=temp1->next;
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

void resultdisplay()
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
    head=0,head1=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.Sort \n 3.Display\n 4.ShowResult \n");
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
                sort();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                resultdisplay();
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
