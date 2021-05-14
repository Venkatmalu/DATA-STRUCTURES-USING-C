#include<stdio.h>
int stack[100],top=-1,queue[100],front,rear,N,x;
front=-1;
rear=-1;

void push(int x)
{
    if(top==N-1)
    {
        printf("stack is full...");
    }
    else
    {
        stack[++top]=x;
    }
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

void enqueue(int x)
{
    if(front==-1&&rear==-1)
    {
       front=rear=0;
       queue[rear]=x;
    }
    else if((rear+1)%N==front && front==0&&rear==N-1)
    {
        printf("Queue is full...");
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

int dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("Queue is empty...");
    }
    else
    {
        return queue[front++];
    }
}

void interleave()
{
    int i=0,len=N/2;
    while(i!=len)
    {
        push(dequeue());
        i++;
    }
    while(top!=-1)
    {
        enqueue(pop());
    }
    i=0;
    while(i!=len)
    {
        enqueue(dequeue());
        i++;
    }
    if(front==N)
    {
        front=0;
    }
    i=0;
    while(i!=len)
    {
        push(x=dequeue());
        i++;
    }
    i=0;
    while(i!=len)
    {
        enqueue(pop());
        enqueue(dequeue());
        i++;
    }
    if(front==N)
    {
        front=0;
    }
}


void display()
{
    int i=front;
    printf("%d",queue[front]);
    if(front==-1&&rear==-1)
    {
        printf("Queue ie empty...");
    }
    else
    {
        printf("the queue is : ");
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[i]);
    }
}

void main()
{
    printf("Enter the number of elements to insert(***length must in EvenLength***) : ");
    scanf("%d",&N);
    int choice=1,choose;
    while(choice)
    {
        printf("choose ur option \n1.enqueue\n2.Dequeue\n3.Inter leave\n4.display\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            {
                printf("Enter the element to insert : ");
                scanf("%d",&x);
                enqueue(x);
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                interleave();
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
            }
        }
        printf("\nEnter greater then 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
}

