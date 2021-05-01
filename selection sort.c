#include<stdio.h>
void main()
{
    int a[50],n,j,i,temp,count=0;
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
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
     printf("\nThe sorted array is : \n");
    for(i=0;i<n;i++)
    {
      printf("%d ",a[i]);
    }
}
