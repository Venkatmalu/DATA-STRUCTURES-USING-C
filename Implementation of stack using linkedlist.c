#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top,*newnode,*temp;
int i,choice=1,count;

void push();
void pop();
void peek();
void display();

void push()
{
    int x;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data to push : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(top==0)
    {
       top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

void pop()
{
    temp=top;
    if(top==0)
    {
        printf("Stack is empty");
    }
    else
    {
        top=top->next;
        free(temp);
    }
}

void peek()
{
    if(top==0)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nTop = %d",top->data);
    }
}

void display()
{
    temp=top;
    count=0;
    while(temp!=0)
    {
        count++;
       printf("%d ",temp->data);
       temp=temp->next;
    }
    printf("\ncount=%d",count);
}

int main()
{
    top=0;
    int choice=1;
    while(choice)
    {
        printf("Enter UR choice \n1.push\n2.pop\n3.peek\n4.display\n");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                push();
                break;
            }
        case 2:
            {
                pop();
                break;
            }
        case 3:
            {
                peek();
                break;
            }
        case 4:
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
