#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newnode,*temp,*currentnode,*prev,*head,*tail,*aux,*temp1,*head1;
int choice=1,choose,count=0;

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

void sort()
{
    if(head==0)
    {
        printf("List is empty...");
    }
    else
    {
        prev=head;
      while(head!=NULL)
      {
        temp=head;
        temp1=head;
        aux=head->next;
        while(aux!=NULL)
        {
            if((temp->data)<(aux->data))
            {
                aux=aux->next;
            }
            else
            {
                temp=aux;
                aux=aux->next;
            }
        }
        printf("t=%d ",temp->data);
        aux=head->next;
        while(aux!=NULL)
        {
            if((temp1->data)>(aux->data))
            {
                aux=aux->next;
            }
            else
            {
                temp1=aux;
                aux=aux->next;
            }
        }
         printf("t1=%d",temp1->data);
         currentnode=head;
             if(head==temp)
             {

             }
             else
             {
                     while(currentnode->next!=temp)
                     {
                       currentnode=currentnode->next;
                     }
                     if(count==0)
                     {
                        currentnode->next=temp->next;
                        temp->next=head;
                        head=temp;
                     }
                     else
                     {
                        currentnode->next=temp->next;
                        temp->next=head;
                        prev->next=temp;
                        head=temp;
                     }
             }
            if(count==0)
            {
                head1=temp;
            }
            count++;
         currentnode=head->next;
            if(head->next==temp1)
            {

            }
            else
            {
                while(currentnode->next!=temp1)
                {
                  currentnode=currentnode->next;
                }
               currentnode->next=temp1->next;
               temp1->next=head->next;
               head->next=temp1;
            }
         prev=head->next;
         head=head->next->next;
        if(prev==NULL || head->next==NULL)
         {
             break;
         }
      }
    }
    head=head1;
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
        printf("Enter ur choice\n 1.insert\n 2.Sort \n 3.Display \n");
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
