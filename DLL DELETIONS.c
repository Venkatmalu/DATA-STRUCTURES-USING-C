#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*tail,*newnode,*temp;
int choice=1,count=0,i=1,pos;

void insert();
void deleteatstart();
void deleteatpos();
void deleteatend();
void print();

void insert()
{
    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data to insert : ");
        scanf("%d",&newnode->data);
        newnode->prev=0;
        newnode->next=0;
        if(head==0)
        {
            head=tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        printf("Enter choice graeter then 1 to continue else 0 :");
        scanf("%d",&choice);
    }
}

void deleteatstart()
{
    temp=head;
    head=head->next;
    head->prev=0;
    free(temp);
    printf("\nAfter deleting the first element,the remaining elements are : ");
    print();
}

void deleteatpos()
{
    temp=head;
    printf("\nEnter the position of element to delete : ");
    scanf("%d",&pos);
    if(pos>0&&pos<=count)
    {
        if(pos==1)
        {
            deleteatstart();
        }
        else
        {

            while(i<pos)
             {
               temp=temp->next;
               i++;
             }
             temp->next->prev=temp->prev;
             temp->prev->next=temp->next;
             printf("\nAfter deleting the element,the remaining elements are : ");
             print();
        }
    }
    else
    {
        printf("Invalid position");
    }
    free(temp);

}

void deleteatend()
{
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        tail->prev->next=0;
    }
    free(tail);
    printf("\nAfter deleting the last element,the remaining elements are :");
    print();
}

void print()
{
    count=0;
    temp=head;
    while(temp!=0)
    {
        count++;
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main()
{
    head=0;
    insert();
    deleteatstart();
    deleteatpos();
    deleteatend();

}
