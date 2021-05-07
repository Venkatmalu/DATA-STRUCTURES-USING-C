#include<stdio.h>
int stack[100],top=-1;

void push(x)
{
    stack[++top]=x;
}

int pop()
{
    if(top==-1)
    {
        printf("stack is empty...");
    }
    else
    {
        return stack[top--];
    }
}

void main()
{
    int arr[100],n,i,x,res[100],count=0,k;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the %d element : ",i+1);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\nEnter the number of values to delete : ");
    scanf("%d",&k);
    i=0;
    push(arr[0]);
    count=0;
     while(top!=-1)
     {
         for(i=1;i<n;i++)
         {
             while(top!=-1&&stack[top]<arr[i])
             {
                 pop();
                 count++;
             }
            push(arr[i]);
             if(count==k)
                 {
                    break;
                 }
         }
         for(i=i;i<n;i++)
         {
            push(arr[i]);
         }
         i=0;
         while(top!=-1)
         {
             res[i]=pop();
             i++;
         }
     }
     printf("The output is : ");
     for(int j=i-1;j>=0;j--)
     {
         printf("%d ",res[j]);
     }
}
