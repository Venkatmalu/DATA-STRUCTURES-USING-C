#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail,*prev,*temp1;
int choice=1,choose,count=0,N;

void insert()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head==0)
    {
        head=tail=newnode;
        count++;
    }
    else
    {
        tail->next=newnode;
        tail=newnode;
        count++;
    }
}
void middleelement()
{
   if(head==0)
   {
       printf("List empty...");
   }
   else
   {
       int k,sum;
       printf("Enter the k value : ");
       scanf("%d",&k);
       temp=head;
       while(temp!=NULL)
       {
           sum=0;
           printf("manitemp\n");
           if(temp->data==k)
           {
               printf("mani\n");
               sum=temp->data;
               prev->next=temp->next;
               prev=temp;
           }
           else
           {

               temp1=temp->next;
               while(temp1!=NULL)
              {
                  printf("manitemp1\n");
                 if(temp->next==temp1)
                 {
                     printf("manitemp=temp1\n");
                   sum=sum+(temp->data)+(temp1->data);
                 }
                 else
                 {
                     printf("maniT!=T1\n");
                   sum=sum+temp1->data;
                 }
                 if(sum==k)
                 {
                   if(temp==head)
                   {
                       printf("hi\n");
                       head=temp1->next;
                       break;
                   }
                   else
                   {

                   }
                 }
                 else
                 {
                     printf("maniT1N\n");
                   temp1=temp1->next;
                 }
              }
           }
           if(sum!=k)
           {
               printf("maniTN\n");
               prev=temp;
               temp=temp->next;
           }
           else
           {
               if(prev!=head)
               {
                   printf("hi1\n");
                   temp=head;
               }
               else
               {
                   printf("hi2\n");
                   temp=prev->next;
               }
           }
       }
   }
}

void deleteelement()
{
   temp=head;
   currentnode=head;
   if(head==0)
   {
       printf("List is empty...");
   }
   else
   {
         while(temp!=tail)
         {
             currentnode=temp;
             temp=temp->next;
         }
         tail=currentnode;
         tail->next=0;
         free(temp);
         count--;
         if(count==0)
         {
             head=0;
         }
   }
}

void display()
{
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
         }
         printf("c=%d",count);
    }
}

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.Middle element \n 3.delete element \n 4.Display\n");
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
                middleelement();
                break;
            }
        case 3:
            {
                deleteelement();
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
                break;
            }
        }
        printf("\nEnter greater than 1 to continue else 0 : ");
        scanf("%d",&choice);
    }
}


