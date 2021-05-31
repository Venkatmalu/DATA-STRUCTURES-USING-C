#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*temp1,*head,*tail,*head1,*tail1,*prev;
int choice=1,choose,count=0,count1=0,checkcount=0;

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

void check()
{
  temp=head;
  temp1=head1;
  if(head==0&&head1==0)
  {
      printf("List s empty...");
  }
  else
  {
      while(temp!=NULL)
      {
          temp1=head1;
              if((temp1->data)<(temp->data))
              {
                  int tmp=temp->data;
                  temp->data=temp1->data;
                  while(temp1!=NULL)
                  {
                      if((temp1->next->data)<tmp)
                      {
                          prev=temp1;
                          temp1=temp1->next;
                      }
                      else
                      {
                          if(temp1==head1)
                          {
                              temp1->data=tmp;
                              break;
                          }
                          else
                          {
                              prev->data=temp1->data;
                              temp1->data=tmp;
                              break;
                          }
                      }
                  }
              }
              temp=temp->next;
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
        printf("\nThe List is : ");
        while(temp!=NULL)
         {
           printf("%d ",temp->data);
           temp=temp->next;
         }
    }
    printf("\n");
    display1();
    printf("\n");
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

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.insert1 \n 3.check\n 4.Display\n");
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
