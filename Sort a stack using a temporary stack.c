#include<stdio.h>
int istack[100],tmpstack[100],itop=-1,ttop=-1,x;

void ipush(x)
{
    istack[++itop]=x;
}
void tmppush(x)
{
    tmpstack[++ttop]=x;
}

int ipop()
{
    if(itop==-1)
    {
        printf("istack is empty...");
    }
    else
    {
        return istack[itop--];
    }
}
int tmppop()
{
    if(ttop==-1)
    {
        printf("tstack is empty...");
    }
    else
    {
        return tmpstack[ttop--];
    }
}

int main()
{
    int n,i,temp;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter %d elemnet to insert into input stack : ",i+1);
        scanf("%d",&x);
        ipush(x);
    }
    printf("\n");
    for(i=itop;i>=0;i--)
    {
        printf("%d ",istack[i]);
    }
    while(itop!=-1)
    {
        temp=ipop();
        while(ttop!=-1 && tmpstack[ttop]<temp)
        {
            x=tmppop();
            ipush(x);
        }
        tmppush(temp);
    }
    printf("\nThe sorted stack is : ");
    for(i=ttop;i>=0;i--)
    {
        printf("%d ",tmpstack[i]);
    }
}
