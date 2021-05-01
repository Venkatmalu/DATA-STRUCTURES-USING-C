#include<stdio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*newnode,*temp,*tail;
int choice=1,count;

void insert();
void display();

void insert()
{
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the element to insert : ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
        {
            head=tail=newnode;
            head->next=head;
            head->prev=head;
        }
        else
        {
            newnode->prev=tail;
            newnode->next=head;
            head->prev=newnode;
            tail->next=newnode;
            tail=newnode;
        }
        printf("Enter greater than 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
}

void display()
{
    temp=head;
    count=0;
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        count++;
        while(temp->next!=head)
        {
            count++;
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d",temp->data);
        printf("\ncount=%d",count);
    }
    printf("\nhead=%d",head->data);
}

int main()
{
    head=0;
    insert();
    display();
}
