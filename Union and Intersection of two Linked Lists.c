#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*head,*tail,*head1,*tail1,*head2,*tail2,*head3,*tail3,*temp3;
int choice=1,choose,count=0,count1=0,count3=0,checkcount=0,x;

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

void unionresultlist(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(head2==0)
    {
        head2=tail2=newnode;
        count3++;
    }
    else
    {
        tail2->next=newnode;
        tail2=newnode;
        count3++;
    }
}

void interresultlist(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=0;
    if(head3==0)
    {
        head3=tail3=newnode;
    }
    else
    {
        tail3->next=newnode;
        tail3=newnode;
    }
}

void check()
{
   if(head==0&&head==0)
   {
       printf("list is empty...");
   }
   else
   {
       if(head==0)
       {

       }
       else if(head1==0)
       {

       }
       else
       {
           //for intersection
           temp=head;
           while(temp!=NULL)
           {
               temp1=head1;
               while(temp1!=NULL)
               {
                   if((temp->data)==(temp1->data))
                      {
                          interresultlist((temp->data));
                          break;
                      }
                        temp1=temp1->next;
               }
               temp=temp->next;
           }
           //for Union
           temp=head;
           temp1=head1;
           while(temp!=NULL || temp1!=NULL)
           {
               if(temp1==NULL)
               {
                    int i=count3,j=0;
                    temp3=head2;
                    while(i)
                    {
                        if((temp->data)!=(temp3->data))
                        {
                           j++;
                           if(j==count3)
                           {
                              unionresultlist((temp->data));
                           }
                        }
                        temp3=temp3->next;
                        i--;
                    }
               }
               else if(temp==NULL)
               {
                    int i=count3,j=0;
                    temp3=head2;
                    while(i)
                    {
                        if((temp1->data)!=(temp3->data))
                        {
                           j++;
                           if(j==count3)
                           {
                              unionresultlist((temp1->data));
                           }
                        }
                        temp3=temp3->next;
                        i--;
                    }
               }
               else
               {
                       temp3=head2;
                       if(head2==0)
                        {
                          unionresultlist((temp->data));
                          unionresultlist((temp1->data));
                        }
                        else
                        {
                            if((temp->data)!=(temp1->data))
                            {
                                int i=count3,j=0,k=0;
                                int tmp=count3;
                                while(i)
                                {
                                     if((temp->data)!=(temp3->data))
                                     {
                                        j++;
                                        if(j==tmp)
                                        {
                                            unionresultlist((temp->data));
                                        }
                                     }
                                     if((temp1->data)!=(temp3->data))
                                     {
                                        k++;
                                        if(k==tmp)
                                        {
                                            unionresultlist((temp1->data));
                                        }
                                     }
                                     temp3=temp3->next;
                                     i--;
                                }
                            }
                            else
                            {
                                int i=count3,j=0;
                                temp3=head2;
                                while(i)
                                {
                                     if((temp->data)!=(temp3->data))
                                     {
                                        j++;
                                        if(j==count3)
                                        {
                                            unionresultlist((temp->data));
                                        }
                                     }
                                     temp3=temp3->next;
                                     i--;
                                }
                            }
                        }
                   }
                if(temp==NULL)
                {
                    temp1=temp1->next;
                }
                else if(temp1==NULL)
                {
                    temp=temp->next;
                }
                else
                {
                   temp=temp->next;
                   temp1=temp1->next;
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

void resultdisplayintersection()
{
    temp=head3;
    if(head3==0)
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

void resultdisplayunion()
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
    head1=0;
    head2=0;
    head3=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.insert1 \n 3.check\n 4.Display\n 5.Result Display for Intersection \n 6.Result Display for Union \n");
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
                resultdisplayintersection();
                break;
            }
        case 6:
            {
                resultdisplayunion();
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

