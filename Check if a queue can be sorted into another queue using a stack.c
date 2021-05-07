#include<stdio.h>
int stack[100],top=-1,x,queue1[100],queue2[100],front1,rear1,front2,rear2,N,i,count=0;
front1=-1;
rear1=-1;
front2=-1;
rear2=-1;

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

void enqueue1(int N)
{
    printf("Enter the element to insert : ");
    scanf("%d",&x);
    if(front1==-1&&rear1==-1)
    {
       front1=rear1=0;
       queue1[rear1]=x;
    }
    else if((rear1+1)%N==front1)
    {
        printf("Queue is full");
    }
    else
    {
        rear1=(rear1+1)%N;
        queue1[rear1]=x;
    }
}

void enqueue2(int N,int x)
{
    count++;
    if(front2==-1&&rear2==-1)
    {
       front2=rear2=0;
       queue2[rear2]=x;
    }
    else if((rear2+1)%N==front2)
    {
        printf("Queue is full");
    }
    else
    {
        rear2=(rear2+1)%N;
        queue2[rear2]=x;
    }
}

int dequeue1()
{
    if(front1==-1&&rear1==-1)
    {
        printf("queue is empty");
    }
    else if(front1==rear1)
    {
        return queue1[front1];
        front1=rear1=-1;
    }
    else
    {
       return queue1[front1++];
    }
}

void display()
{
    int i=front1;
    if(front1==-1&&rear1==-1)
    {
        printf("Queue is empty...");
    }
    else
        printf("\n\nThe Queue is : ");
    {
        while(i!=rear1)
        {
            printf("%d ",queue1[i]);
            i=(i+1)%N;
        }
         printf("%d ",queue1[i]);
    }
}

void main()
{
    int n,exe=1;
    printf("Enter the number of elements to sort : ");
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        enqueue1(N);
    }
    display();
    n=N;
    while(n)
    {
       if(exe==queue1[front1])
       {
           exe++;
           x=dequeue1();
           enqueue2(N,x);
       }else if(top==-1)
       {
           x=dequeue1();
           push(x);
       }
       else
       {
           if(stack[top]>queue1[front1])
           {
               x=dequeue1();
               enqueue2(N,x);
               exe++;
           }
           else
           {
                break;
           }
       }
       n--;
    }
    while(top!=-1&&exe==stack[top])
    {
        x=pop();
        enqueue2(N,x);
    }
    if(N==count&&top==-1)
    {
        printf("\n\nThe output is : Yes\n");
    }
    else
    {
        printf("\n\nThe output is : No\n");
    }
}
