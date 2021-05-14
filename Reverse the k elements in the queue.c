#include<stdio.h>
int stack[100],top=-1,queue[100],front,rear,x,N;
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

void reversekelements()
{
    int k,i=0;
    printf("Enter the k value : ");
    scanf("%d",&k);
   if(front==-1&&rear==-1)
   {
       printf("queue is empty...");
   }
   else if(front==rear)
   {
       printf("%d",queue[rear]);
   }
   else
   {
      while(i!=k)
      {
          x=dequeue();
          push(x);
          i++;
      }
      while(top!=-1)
      {
          x=pop();
          enqueue(x);
      }
      i=0;
      int rem=N-k;
      while(i!=rem)
      {
          x=dequeue();
          enqueue(x);
          i++;
      }
       if(front==N)
          {
              front=0;
          }
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
    printf("Enter the number of elements to insert : ");
    scanf("%d",&N);
    int choice=1,choose;
    while(choice)
    {
        printf("choose ur option \n1.enqueue\n2.Dequeue\n3.Display\n");
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
                reversekelements();
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

