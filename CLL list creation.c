#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp;
int choice=1;

void insert();
void display();

void insert()
{

    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data to insert : ");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0)
        {
            head=temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
        printf("Enter greater the 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
    display();
    printf("\n%d",temp->next->data);
}

void display()
{
    temp=head;
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        while(temp->next!=head)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
    }
}

int main()
{
    head=0;
    insert();
}
