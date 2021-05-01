#include<stdio.h>
void main()
{
    int a[50],i,n,temp=0,j,count=0;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("The unsorted array is : ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
         {
           if(a[j]>a[j+1])
           {
             temp=a[j];
             a[j]=a[j+1];
             a[j+1]=temp;
             count++;
           }
         }
         if(count==0)
            break;
    }
    printf("\nThe sorted array is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
