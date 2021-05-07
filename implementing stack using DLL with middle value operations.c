#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *top,*newnode,*temp;
int count=0;

void Push()
{
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("Enter the data to insert : ");
   scanf("%d",&newnode->data);
   newnode->next=0;
   newnode->prev=0;
   if(top==0)
   {
       newnode->next=0;
       newnode->prev=0;
       top=newnode;
   }
   else
   {
       newnode->prev=top;
       top->next=newnode;
       top=newnode;
   }
}

void Pop()
{
    if(top==0)
    {
        printf("Stack is Empty...");
    }
    else
    {
        top=top->prev;
        top->next=0;
    }
}

void Findmid()
{
    temp=top;
    int  mid,j=1;
    if(count%2==1)
    {
        mid=count/2+1;
        while(j<mid)
        {
            temp=temp->prev;
            j++;
        }
        printf("The mid value is : %d",temp->data);
    }
    else
    {
        mid=count/2+1;
        while(j<mid)
        {
            temp=temp->prev;
            j++;
        }
        printf("The mid value is : %d",temp->data);
    }
}

void Peek()
{
   if(top==0)
   {
       printf("Stack is Empty...");
   }
   else
   {
       printf("The Peek value is : %d",top->data);
   }
}

void deletemid()
{
    temp=top;
    int  mid,j=1;
    if(count%2==1)
    {
        mid=count/2+1;
        while(j<mid)
        {
            temp=temp->prev;
            j++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
    else
    {
        mid=count/2+1;
        while(j<mid)
        {
            temp=temp->prev;
            j++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
}
void display()
{
    count=0;
    temp=top;
    while(temp!=0)
    {
        count++;
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\ncount= %d",count);
}
int main()
{
    top=0;
    int choice=1;
    while(choice)
    {
        printf("Enter UR choice \n1.push\n2.pop\n3.Find mid value\n4.deletemid\n5.Peek\n6.display\n");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                Push();
                break;
            }
        case 2:
            {
                Pop();
                break;
            }
        case 3:
            {
                Findmid();
                break;
            }
        case 4:
            {
                deletemid();
                break;
            }
        case 5:
            {
                Peek();
                break;
            }
        case 6:
            {
                display();
                break;
            }
        default:
        printf("Entered invalid option");
    }
    printf("\nEnter greater than 1 to continue else 0 : ");
    scanf("%d",&choice);
    }
}
