#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *newnode,*temp;
struct node *front=0;
struct node *rear=0;
int framesize=0,choice=1,choose,x,temp1,temp2,FN;

void insertpage(int x)
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("%d ",x);
    newnode->data=x;
    newnode->next=0;
    newnode->prev=0;
    temp=front;
          if(x==(temp2))
          {
              dequeue();
          }
          else
          {
               while(temp!=NULL)
              {
                 if(x==(temp->data))
                 {
                     temp->prev->next=temp->next;
                     temp->next->prev=temp->prev;
                     free(temp);
                     framesize--;
                 }
                 else
                 {
                     temp=temp->next;
                 }
              }
          }
    if(front==0&&rear==0)
    {
        front=newnode;
        rear=newnode;
        framesize++;
        temp=front;
        temp2=rear->data;
    }
    else
    {
        if(framesize==FN)
        {
               dequeue();
               insertpage(x);
               temp2=rear->data;
        }
        else
        {
                newnode->next=front;
                front->prev=newnode;
                front=newnode;
                framesize++;
                temp2=rear->data;
                printf("r=%d",rear->data);
        }
    }
}

void dequeue()
{
    temp=rear;
    if(front==0&&rear==0)
    {
        printf("Frame is empty...");
    }
    else
    {
        rear=rear->prev;
        rear->next=0;
        free(temp);
        framesize--;
    }
}

void display()
{
   temp=front;
   if(front==0&&rear==0)
   {
       printf("No pages in Frame");
   }
   else
   {
       printf("The pages are : ");
       while(temp!=NULL)
       {
           printf("%d ",temp->data);
           temp=temp->next;
       }
   }
}

void main()
{
    int queue[100],num,i;
    printf("Enter the number of pages : ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&queue[i]);
    }
    printf("The page queue is : ");
    for(i=0;i<num;i++)
    {
        printf("%d ",queue[i]);
    }
    printf("\nEnter the frame size : ");
    scanf("%d",&FN);
    i=0;
    while(choice)
    {
        printf("\nEnter ur option \n1.insertpage\n2.display\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            {
                if(i<num)
                {
                    x=queue[i];
                    insertpage(x);
                    i++;
                }
                else
                {
                    printf("There is no pages to insert...");
                }
                break;
            }
        case 2:
            {
                display();
                break;
            }
        default:
            {
                printf("Invalid option");
                break;
            }
        }
        printf("\nEnter greaterthan 1 to continue to insertpage or display else 0 : ");
        scanf("%d",&choice);
    }
}
