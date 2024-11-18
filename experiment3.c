#include<stdio.h>
#include<stdlib.h>
struct Node{
        struct Node* prev;
        int data;
        struct Node* next;
};
struct Node* head=NULL;
struct Node* createNode(int data){
        struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->prev=NULL;
        newNode->data=data;
        newNode->next=NULL;
        return newNode;
}
void insertAtBeginning(int data){
        struct Node* newNode=createNode(data);
        newNode->prev=NULL;
        newNode->next=head;
        head=newNode;
}
void display(){
        struct Node* temp=head;
        if(temp==NULL){
                printf(" list is empty \n");
                return;
        }
        while(temp!=NULL){
                printf("%d \t",temp->data);
                temp=temp->next;
        }
}
void insertAtEnd(int data){
        struct Node* newNode=createNode(data);
        if(head==NULL){
                head=newNode;
                return;
        }
        struct Node* temp=head;
        while(temp->next!=NULL)
                temp=temp->next;
        temp->next=newNode;
        newNode->prev=temp;
        newNode->next=NULL;
}
void insertAtPosition(int data,int position){
        if(position<1){
                printf("position must be >=1\n");
                return;
        }
        if(position==1){
                insertAtBeginning(data);
                return;
        }
        struct Node* newNode=createNode(data);
        struct Node* temp=head;
        for (int i=1 ;i<position-1 && temp!=NULL;i++)
                temp=temp->next;
        if(temp==NULL){
                printf("position greater than the length of the list\n"); 
                free(newNode);
        }
        else{
                newNode->next=temp->next;
                temp->next->prev=newNode;
                temp->next=newNode;
                newNode->prev=temp;
        }

}
void deleteAtBeginning(){
        if(head==NULL){
                printf("list is empty\n");
                return;
        }
        struct Node* temp=head;
        head=temp->next;
        if(head!=NULL){
                head->prev=NULL;
        }
        free(temp);
        printf("item deleted\n");
}
void deleteAtEnd(){
        if(head==NULL){
                printf("list is empty\n");
                return;
        }
        struct Node* temp=head;
        struct Node* loc=NULL;
        if (temp->next == NULL){
                free(temp);
                head=NULL;
                return;
        }
        while (temp->next!=NULL){
                loc=temp;
                temp=temp->next;
        }
        loc->next=NULL;
        free(temp);
        printf("item deleted\n");
}
void deleteAtPosition(int position){
        if(head==NULL){
                printf("list is empty\n");
                return;
        }
        if (position<1){
                printf("position should be greater than or equal to 1\n");
                return;
        }
        if( position==1){
                deleteAtBeginning();
                return;
        }
        struct  Node* temp=head;
        struct  Node* loc=NULL;
        for (int i=1; i<position && temp!= NULL; i++)
        {
                loc = temp;
                temp=temp->next;
        }
        if (temp==NULL)
                printf("position greater than  the lenth of the list\n");
        else {
                loc->next=temp->next;
                free(temp);
        }

}
int main()
{
        int choice,data,position;
        do{
                printf("\nselect an operation:\n");
                printf("1.insertion at beginning:\n");
                printf("2.insertion at end\n");
                printf("3.insertion at position\n");
                printf("4.deletion at beginning\n");
                printf("5.deletion at end\n");
                printf("6.deletion at position\n");
                printf("7.display\n ");
                printf("8.exit\n");
                printf("\nenter your choice: ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                printf("enter the data to insert at the beginning  ");
                                scanf("%d",&data);
                                insertAtBeginning(data);
                                break;
                       case 2:
                                printf("enter the data to insert at the end  ");
                                scanf("%d",&data);
                                insertAtEnd(data);
                                break;
                        case 3:
                                printf("enter the data ");
                                scanf("%d",&data);
                                printf("enter the position ");
                                scanf("%d",&position);
                                insertAtPosition(data,position);
                                break;
                        case 4:
                                deleteAtBeginning();
                                break;
                       case 5:
                                deleteAtEnd();
                                break;
                       case 6:
                                printf("enter the position to delete element ");
                                scanf("%d",&position);
                                deleteAtPosition(position);
                                break;
                        case 7:
                                display();
                                break;
		                    case 8:
                                printf("existing...");
                                break;
                        default:
                                printf("invalid option\n");
                                break;
                }
        }while(choice!=8);

return 0;
}
