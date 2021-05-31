#include<stdio.h>
#include<stdlib.h>
struct node
{
    char data;
    struct node *next;
};
struct node *newnode,*temp,*head,*tail,*head1,*tail1,*temp1;
int choice=1,choose,count=0,count1=0,count2=0,result;

void insert(char x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
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

void insert1(char x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
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

int compare()
{
   if(count==count1)
   {
       temp=head;
       temp1=head1;
       while(temp!=NULL && temp1!=NULL)
       {
           if((temp->data)==(temp1->data))
           {
               count2++;
           }
           else if((temp->data)>(temp1->data))
           {
               return 1;
           }
           else
           {
               return -1;
           }
           if(count2==count)
           {
               return 0;
               break;
           }
           temp=temp->next;
           temp1=temp1->next;
       }
   }
   else if(count>count1)
   {
       return 1;
   }
   else
   {
       return -1;
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
           printf("%c ",temp->data);
           temp=temp->next;
         }
    }
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
           printf("%c ",temp->data);
           temp=temp->next;
         }
    }
}

int main()
{
    head=0;
    char str1[50],str2[50];
    printf("Enter the First string : ");
    gets(str1);
    printf("Enter the Second string : ");
    gets(str2);
    while(choice)
    {
        printf("Enter ur choice\n 1.insert\n 2.insert1 \n 3.Compare\n 4.Display First List\n 5.Display Second List \n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            {
                for(int i=0;str1[i]!='\0';i++)
                {
                    insert(str1[i]);
                }
                printf("\nSuccessfully Inserted all Characters into the First LinkedList...\n");
                break;
            }
        case 2:
            {
                for(int i=0;str2[i]!='\0';i++)
                {
                    insert1(str2[i]);
                }
                printf("\nSuccessfully Inserted all Characters into the Second LinkedList...\n");
                break;
            }
        case 3:
            {
                result=compare();
                printf("\nThe output is : %d\n",result);
                break;
            }
        case 4:
            {
                display();
                break;
            }
        case 5:
            {
                display1();
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
