#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*head,*tail,*head1,*tail1,*head2,*tail2,*resp;
int choice=1,choose,count=0,count1=0,checkcount=0,x;

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

void insert1()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the element to insert : ");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if(head1==0)
    {
        head1=tail1=newnode;
        count1++;
    }
    else
    {
        tail1->next=newnode;
        tail1=newnode;
        count1++;
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

void check()
{
   temp=head;
   temp1=head1;
   if(head==0 || head1==0)
   {
       printf("There is missing no elements in list1 or list1,so we dont merge");
   }
   else
   {
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

void display()
{
    count=0;
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
    display1();
}

void display1()
{
    temp=head1;
    if(head1==0)
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
        printf("Enter ur choice\n 1.insert\n 2.insert1 \n 3.check\n 4.Display\n 5.Result Display \n");
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
                insert1();
                break;
            }
        case 3:
            {
                check();
                break;
            }
        case 4:
            {
                display();
                break;
            }
        case 5:
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

