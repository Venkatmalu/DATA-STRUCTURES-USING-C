#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*temp2,*head,*tail,*head1,*tail1,*head2,*tail2;
int choice=1,choose,count=0,count1=0,checkcount=0,x;

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

void insert2(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
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

void intersection()
{
    temp=head;
    if(head==0)
    {
        printf("List is empty...");
    }
    else
    {
        while(temp!=NULL)
        {
            temp1=head1;
            while(temp1!=NULL)
            {
                if((temp->data)==(temp1->data))
                {
                    insert2((temp->data));
                    break;
                }
                temp1=temp1->next;
            }
            temp=temp->next;
        }
    }
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

void displayresult()
{
    temp=head2;
    if(head2==0)
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
        printf("Enter ur choice\n 1.insert\n 2.insert1 \n 3.intersection \n 4.Display\n 5.Display Result \n");
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
                intersection();
                break;
            }
        case 4:
            {
                display();
                break;
            }
        case 5:
            {
                displayresult();
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



