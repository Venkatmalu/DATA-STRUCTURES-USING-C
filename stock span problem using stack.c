#include<stdio.h>
int stack[100],top=-1,temp,x;

void push()
{
    if(top==-1)
    {
        stack[++top]=x;
    }
    else
    {
        stack[++top]=x;
    }
}

void pop()
{
    if(top==-1)
    {
        printf("Stack is empty...");
    }
    else
    {
        top--;
    }
}

int snapvalue(stocks)
{
    int i=stocks-1,arr[100];
    while(top!=-1)
    {
        int count=0;
        temp=top;
    while(stack[temp]<=stack[top])
    {
        if(temp==-1)
        {
            break;
        }
        count++;
        temp--;
    }
    arr[i]=count;
    i--;
    pop();
    }
    printf("\nThe snapvalues for the days are : ");
    for(i=0;i<stocks;i++)
    {
        printf("%d ",arr[i]);
    }
}

void main()
{
    int arr[100],stocks,i;
    printf("Enter the number stocks : ");
    scanf("%d",&stocks);
    for(i=0;i<stocks;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<stocks;i++)
    {
        printf("%d ",arr[i]);
    }
    i=0;
    while(top!=stocks-1)
    {
        x=arr[i];
        push(x);
        i++;
    }
    snapvalue(stocks);
}
