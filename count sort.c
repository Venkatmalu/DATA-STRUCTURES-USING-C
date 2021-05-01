#include<stdio.h>
void main()
{
    int a[50],count[50]={0},n,i,max,temp,j,b[50];
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\nThe elements are : \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                max=a[j];
            }
            break;
        }
    }
    for(i=0;i<n;i++)
    {
        ++count[a[i]];
    }
    for(i=1;i<=max;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>=0;i--)
    {
        b[--count[a[i]]]=a[i];
    }
    for(i=0;i<n;i++)
    {
        a[i]=b[i];
    }
    printf("\n The sorted array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
