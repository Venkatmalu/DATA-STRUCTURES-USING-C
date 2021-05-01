#include<stdio.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head,*newnode,*temp,*tail;
int choice=1,count,pos,j=1;

void insert();
void deleteatfirst();
void deleteatmid();
void deleteatlast();
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

void deleteatfirst()
{
    temp=head;
    head=head->next;
    head->prev=tail;
    tail->next=head;
    free(temp);
    printf("\nAfter deleting the first element : ");
    display();
}

void deleteatmid()
{
    temp=head;
    printf("\nEnter the position to delete the element : ");
    scanf("%d",&pos);
    if(pos>=1&&pos<=count)
    {
        if(pos==1)
        {
            deleteatfirst();
        }
        else if(pos==count)
        {
            deleteatlast();
        }
        else
        {
            while(j<pos)
            {
                temp=temp->next;
                j++;
            }
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            printf("\nAfter deleting the specified position :");
        }
    }
    display();
}
void deleteatlast()
{
    temp=tail;
    tail=tail->prev;
    tail->next=head;
    head->prev=tail;
    printf("\nAfter deleting the last element : ");
    display();
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
    }
}

int main()
{
    head=0;
    insert();
    deleteatfirst();
    deleteatmid();
    deleteatlast();
}
