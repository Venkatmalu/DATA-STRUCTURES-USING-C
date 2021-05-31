#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*head,*tail,*prev,*head1,*temp1,*resp,*tail1,*nextnode,*head2,*tail2;
int choice=1,choose,count=0;

void reverse();

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

void resultlist(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(head2==0)
    {
        head2=tail2=newnode;
    }
    else
    {
        tail2->next=newnode;
        tail2=newnode;
    }
}

void sort()
{
   prev=head;
   head1=0;
   if(head==0)
   {
       printf("\nList is empty\n");
   }
   else
   {
       temp=prev->next;
       currentnode=temp->next;
       while(temp!=NULL)
       {
           prev->next=temp->next;
           if(head1==0)
           {
               head1=tail1=temp;
           }
           else
           {
               tail1->next=temp;
               tail1=temp;
               tail1->next=0;
           }
           prev=prev->next;
           temp=prev->next;
           if(temp==NULL)
           {
               break;
           }
           currentnode=temp->next;
       }
      reverse();
      temp=head;
      temp1=head1;
        if((temp->data)<(temp1->data))
           {
             resp=temp;
             resultlist((resp->data));
             temp=temp->next;
           }
           else
           {
              resp=temp1;
              resultlist((resp->data));
              temp1=temp1->next;
           }
           while(temp!=NULL || temp1!=NULL)
           {
                   if(temp1==NULL)
                   {
                      while(temp!=NULL)
                      {
                          resp->next=temp;
                          resp=resp->next;
                          resultlist((resp->data));
                          temp=temp->next;
                      }
                   }
                   else if(temp==NULL)
                   {
                        while(temp!=NULL)
                        {
                          resp->next=temp1;
                          resp=resp->next;
                          resultlist((resp->data));
                          temp1=temp1->next;
                        }
                   }
                   else
                   {
                      if((temp->data)>(temp1->data))
                      {
                       resp->next=temp1;
                       resp=resp->next;
                        resultlist((resp->data));
                       temp1=temp1->next;
                      }
                      else
                      {
                       resp->next=temp;
                       resp=resp->next;
                       resultlist((resp->data));
                       temp=temp->next;
                      }
                   }
           }
   }
}

void reverse()
{
        prev=0;
        nextnode=currentnode=head1;
        while(nextnode!=0)
        {
            nextnode=nextnode->next;
            currentnode->next=prev;
            prev=currentnode;
            currentnode=nextnode;
         }
      head1=prev;
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
    }
}

void resultdisplay()
{
    temp=head2;
    if(head2==0)
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
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.Sort\n 3.Display\n 4.resultdisplay\n");
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
                sort();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        case 4:
            {
                resultdisplay();
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
