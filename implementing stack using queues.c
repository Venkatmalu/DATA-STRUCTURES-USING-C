#include<stdio.h>
#define N 5
int queue1[N],queue2[N],x;
int front1=-1,rear1=-1,front2=-1,rear2=-1;

void Push()
{
    printf("Enter the element to insert : ");
    scanf("%d",&x);
    if(front1==-1 && rear1==-1)
    {
        front1=rear1=0;
        queue1[rear1]=x;
    }else if((rear1+1)%N==front1)
    {
        printf("stack is full...NO SAPCE FOR %d",x);
    }
    else
    {
        rear1=(rear1+1)%N;
        queue1[rear1]=x;
    }
}

void Pop()
{
    if(front1==-1 && rear1==-1)
    {
        printf("Stack is empty...");
    }else if(front1==rear1)
    {
        front1=rear1=-1;
        printf("Last Element In The Stack Is Poped So,NOW STACK IS EMPTY...");
    }
    else
    {
        while(front1!=rear1)
        {
            if(front2==-1&&rear2==-1)
            {
                front2=rear2=0;
                queue2[rear2]=queue1[front1];
                front1++;
            }
            else
            {
                rear2=(rear2+1)%N;
                queue2[rear2]=queue1[front1];
                front1++;
            }
        }
        front1=rear1=-1;
        while(front2<=rear2)
        {
            if(front1==-1 && rear1==-1)
            {
                front1=rear1=0;
                queue1[rear1]=queue2[front2];
                front2++;
            }
            else
            {
                rear1=(rear1+1)%N;
                queue1[rear1]=queue2[front2];
                front2++;
            }
        }
    }
}

void Peek()
{
    if(front1==-1&&rear1==-1)
    {
        printf("Stack is Empty....");
    }
    else
    {
        printf("The Peek Value is : %d",queue1[rear1]);
    }
}
void display()
{
    int i=rear1;
    if(front1==-1&&rear1==-1)
    {
        printf("Stack is empty.....");
    }
    else
    {
        printf("The Stack is : ");
        while(i!=front1)
        {
            printf("%d ",queue1[i]);
            i=(i-1)%N;
        }
         printf("%d ",queue1[i]);
    }
}

void main()
{
    int choice=1;
   while(choice)
   {
       printf("\nEnter UR choice \n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n");
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
            Peek();
            break;
        }
       case 4:
        {
            display();
            break;
        }
       default:
        printf("Invalid option");
       }
       printf("\nEnter greater than 1 to continue else 0  :  ");
       scanf("%d",&choice);
   }

}
