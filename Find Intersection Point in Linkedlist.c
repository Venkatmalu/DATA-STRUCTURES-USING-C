#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*temp2,*head,*tail,*head1,*tail1,*intersection;
int choice=1,choose,count=0,count1=0,x,p=0;

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
        if(count==3)
        {
            intersection=tail;
        }
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
        if(count1==2)
        {
            tail1->next=intersection;
            count1++;
        }
        else
        {
            tail1->next=newnode;
            tail1=newnode;
            count1++;
        }
    }
}

void intersectionpoint()
{
    temp=head;
    temp1=head1;
    int d;
    if(count<count1)
    {
        d=count1-count;
    }
    else
    {
        d=count-count1;
    }

    if(head==0)
    {
        printf("List is empty...");
    }
    else
    {
        if(count<count1)
        {
            while(d)
            {
                temp1=temp1->next;
                d--;
            }
        }
        else
        {
             while(d)
             {
                temp=temp->next;
                d--;
             }
        }
        while(temp!=NULL)
        {
            while(temp1!=NULL)
            {
                if((temp->data)==(temp1->data))
                {
                    printf("The Intersection Point is : %d",temp->data);
                    p++;
                    break;
                }
                else
                {
                    break;
                }
            }
            if(p==1)
            {
                break;
            }
            else
            {
                temp=temp->next;
                temp1=temp1->next;
            }
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
    count1=0;
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
           count1++;
         }
    }
}

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.insert1 \n 3.Intersection Point \n 4.Display \n");
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
                intersectionpoint();
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




