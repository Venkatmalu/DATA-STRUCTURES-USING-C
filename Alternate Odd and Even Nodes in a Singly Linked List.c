#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail,*prev;
int choice=1,choose,count=0,*evenqueue[100],*oddqueue[100],evenfront=-1,evenrear=-1,oddfront=-1,oddrear=-1;

void evenenqueue(struct node *x)
{
    if(evenfront==-1)
    {
        evenfront=evenrear=0;
        evenqueue[evenrear]=x;
    }
    else
    {
        evenrear++;
        evenqueue[evenrear]=x;
    }
}

void oddenqueue(struct node *x)
{
    if(oddfront==-1)
    {
        oddfront=oddrear=0;
        oddqueue[oddrear]=x;
    }
    else
    {
        oddrear++;
        oddqueue[oddrear]=x;
    }
}

int evendequeue()
{
    if(evenfront==-1)
    {
        printf("List is empty...");
    }
    else
    {
        return evenqueue[evenfront++];
    }
}

int oddequeue()
{
    if(oddfront==-1)
    {
        printf("List is empty...");
    }
    else
    {
        return oddqueue[oddfront++];
    }
}

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

void reverse()
{
  temp=head;
  while(temp!=NULL)
  {
      if((temp->data)%2!=0)
      {
          oddenqueue((temp->next));
          printf("\nor=%d",oddrear);
      }
      else
      {
          evenenqueue((temp->next));
          printf("\ner=%d",evenrear);
      }
      temp=temp->next;
  }
  while(evenfront!=-1 || oddfront!=-1)
  {
      if(evenfront!=-1)
      {

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
    }
}

int main()
{
    head=0;
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.reverse  \n 3.Display\n");
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
                reverse();
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






