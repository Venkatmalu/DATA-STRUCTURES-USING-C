#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*nextnode,*head,*tail,*prev;
int choice=1,choose,count;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
    {
        head=tail=newnode;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
    }
}

void reverse()
{
    if(head==0)
    {
        printf("List is empty");
    }
    else
    {
        prev=0;
        nextnode=currentnode=head;
        while(nextnode!=0)
        {
            nextnode=nextnode->next;
            currentnode->next=prev;
            prev=currentnode;
            currentnode=nextnode;
         }
    }
      head=prev;
}

void  calculate()
{
  int sum=0;
  if(head==0)
  {
      sum=0;
  }
  else
  {
       reverse();
       temp=head;
       int res=0;
       int squ=0;
       while(temp!=NULL)
       {
           if((temp->data)==0)
           {
               if(res==0&&head==temp)
               {
                  res=0;
                  sum=res;
                  squ=1;
                  temp=temp->next;
               }
               else
               {
                   if(res==0)
                   {
                       res=res+0;
                       squ=squ+1;
                       temp=temp->next;
                   }
                   else
                   {
                       squ=squ*2;
                       temp=temp->next;
                   }
               }
           }
           else
           {
               if(res==0)
               {
                   if(squ==0)
                   {
                       sum=1;
                       res=sum;
                       squ=1;
                   }
                   else
                   {
                       sum=squ*2;
                       res=sum;
                       squ=squ*2;
                   }
                   temp=temp->next;
               }
               else if(res==1)
               {
                   sum=res+1+squ;
                   res=sum;
                   squ=squ+1;
                   temp=temp->next;
               }
               else
               {
                   sum=sum+squ*2;
                   squ=squ*2;
                   res=sum;
                   temp=temp->next;
               }
           }
       }
       reverse();
  }
  printf("\nThe output is : %d\n",sum);
}

void display()
{
    count=-1;
    temp=head;
    if(head==0)
    {
        printf("List is epmty...");
    }
    else
    {
        printf("The List is : ");
        while(temp!=NULL)
         {
           printf("%d ",temp->data);
           temp=temp->next;
           count++;
         }
    }
}

int main()
{
    head=0;
    printf("***YOU MUST ENTER ONLY BINARY VALUES FOR CORRECT OUTPUT***\n");
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.calculate \n 3.Display\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            {
                insert();
                break;
            }
        case 2:
            {
                calculate();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        default :
            {
                printf("Invalid option");
                break;
            }
        }
        printf("\nEnter greater than 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
}
