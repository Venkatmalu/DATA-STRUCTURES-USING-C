#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*head,*tail,*slow,*fast;
int choice=1,choose,count=0,count1=0,stack[100],top=-1,x;

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
        if(count==2)
        {
            temp1=newnode;
        }
    }
    newnode->next=temp1;
}

void push(int x)
{
    top++;
   stack[top]=x;
}

int pop()
{
    if(top==-1)
    {

    }
    else
    {
        return stack[top--];
    }
}

void check()
{
    slow=fast=head;
    if(head==0)
    {
        printf("List is empty...");
    }
    else
    {
        while(fast!=NULL && slow!=NULL)
        {
            if(fast==slow && slow!=head)
            {
                break;
            }
            else
            {
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        temp=head;
        while((temp->next)!=(slow->next))
         {
             temp=temp->next;
             slow=slow->next;
         }
        temp=head;
        while(temp!=slow)
        {
           push((temp->data));
           temp=temp->next;
        }
        push((temp->data));
        temp=head;
        while(top!=-1)
        {
            x=pop();
            if((temp->data)==x)
            {
                count1++;
                temp=temp->next;
            }
            else
            {
                printf("\nNot Palindrome\n");
                break;
            }
        }
        if(count1==count)
        {
            printf("\nPalindrome\n");
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

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.Check \n 3.Display\n");
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
             check();
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
