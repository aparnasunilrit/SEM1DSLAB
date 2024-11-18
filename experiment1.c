//STACK USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* link;
};
struct node *top=NULL;
int isEmpty()
{
        if(top==NULL)
                return 1;
        else
                return 0;
}

void push(int data)
{
        struct node* newNode=(struct node*)malloc(sizeof(struct node));
        if(newNode==NULL)
        {
                printf("stack overflow\n");
        }
        else
        {
                newNode->data=data;
                newNode->link=NULL;
                newNode->link=top;
                top=newNode;
        }
}

void display()
{
        struct node*temp;
        temp=top;
        if (isEmpty())
        {
                printf("stack underflow");
        }
        else
        {
                printf("the stack elements are:\n");
                while(temp)
                {
                        printf("%d\n",temp->data);
                        temp=temp->link;
                }
        }
}void pop()
{
        struct node* temp;
        int val;
        if (isEmpty())
        {
                printf("stack underflow");
        }
        else
        {
                temp=top;
                val=temp->data;
                top=temp->link;
                free(temp);
                temp=NULL;
                printf(" deleted element is %d\n",val);
        }
}
void search()
{
        struct node * temp;
        temp=top;
        int found=0;
        int value;
        if(isEmpty())
        {
                printf("stack underflow");
        }
        else
        {
                printf("enter the value to be searched: ");
                scanf("%d",&value);
                while(temp)
                {
                        if(temp->data==value)
                        {
                                found=1;
                                break;
                        }
                temp=temp->link;
                }
                if(found==1)
                        printf("the element is present inside the stack");
                else
                        printf("the element is not present inside the stack");

        }
}
int main()
{
        int data,choice;
        while(1)
        {
                printf("\n 1.push");
                printf("\n 2.pop");
                printf("\n 3.search");
                printf("\n 4.display");
                printf("\n 5.exit");
                printf("\n enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                        printf("enter the data to be added ");
                        scanf("%d",&data);
                        push(data);
                        break;
                case 2:
                        pop();
                        break;
                case 3:
                        search();
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        exit(0);
                        break;
                default:
                        printf("wrong choice");
                }
        }


return 0;
}
