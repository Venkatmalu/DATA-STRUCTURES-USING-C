#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail;
int choice=1,choose,count=0,stack[100],top=-1,count1=0,count2=0;

void push(int x)
{
    stack[++top]=x;
}

int pop()
{
    if(top==-1)
    {
        printf("Stack is empty...");
    }
    else
    {
        return stack[top--];
    }
}

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
bool palindrome()
{
    top=-1;
    temp=head;
    while(temp!=NULL)
    {
        push((temp->data));
        temp=temp->next;
    }
    temp=head;
    while(top!=-1)
    {
        if((temp->data)==pop())
        {
            temp=temp->next;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void deleteelement()
{
   temp=head;
   currentnode=head;
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
         while(temp!=tail)
         {
             currentnode=temp;
             temp=temp->next;
         }
         tail=currentnode;
         tail->next=0;
         free(temp);
         count--;
         if(count==0)
         {
             head=0;
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
        printf("Enter ur choice\n 1.insert\n 2.palindrome \n 3.delete element \n 4.Display\n");
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
              if(palindrome())
              {
                  printf("\nTrue It Is palindrome\n");
              }
              else
              {
                  printf("\nFalse It Is Not palindrome\n");
              }
                break;
            }
        case 3:
            {
                deleteelement();
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



