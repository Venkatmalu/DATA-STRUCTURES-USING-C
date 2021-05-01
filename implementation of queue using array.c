#include<stdio.h>
#define N 5
int queue[N],front,rear,x,i;
front=-1;
rear=-1;

void enqueue();
void dequeue();
void peek();
void display();

void enqueue()
{
    int x;
    printf("Enter the value to push : ");
    scanf("%d",&x);
    if(front==-1&&rear==-1)
    {
        front++;
        rear++;
        queue[rear]=x;
    }
    else if(rear==N-1)
    {
       printf("occuring overflow...");
    }
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if(front>rear)
    {
        printf("underflow situation occuring");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    {
        front++;
    }
}

void peek()
{
    if(front>rear)
    {
        printf("\nThe is no elements,so insert....");
    }
    else
    {
        printf("\nThe peek value = %d",queue[front]);
    }
}
void display()
{
    for(i=front;i<=rear;i++)
    {
        printf("%d ",queue[i]);
    }
}

int main()
{
    int choice=1;
    while(choice)
    {
        printf("Enter UR choice \n1.enqueue\n2.dequeue\n3.peek\n4.display\n");
        scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            {
                enqueue();
                break;
            }
        case 2:
            {
                dequeue();
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

