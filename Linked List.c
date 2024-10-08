#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main()
{
    struct node *head=NULL, *temp=NULL, *newnode=NULL;
    head = 0;
    int choice = 1, count = 0,pos=0,i=1;
    
    do{
        printf("1.Insert an element at beginning\n2.Insert element at the end\n3.Insert an element at specified position\n4.Delete At beginning\n5.Delete at End\n6.Delete at specified position\n7.Traverse the list\n8.Reverse of list\n0.Exit\n"); 
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                newnode = (struct node*)malloc(sizeof(struct node));
                printf("Enter data: ");
                scanf("%d", &newnode->data);
                newnode->next = head;
                head=newnode;
                printf("Inserted at beginning\n");
                break;
            case 2: {
                newnode = (struct node*)malloc(sizeof(struct node));
                printf("Enter data: ");
                scanf("%d", &newnode->data);
                newnode->next = 0;
                if(head==NULL){
                    head=newnode;
                }else{
                    temp=head;
                    while(temp->next!=0){
                        temp=temp->next;
                    }
                temp->next=newnode;}
                printf("Inserted at end\n");
                break;}
            case 3: 
                temp = head;
                while (temp != 0) {
                    temp = temp->next;
                    count++;
                }
                temp=head;       
                printf("Enter position:");
                scanf("%d",&pos);
                if(pos>count){
                    printf("Invalid position\n");
                }
                else{
                    newnode = (struct node*)malloc(sizeof(struct node));
                    printf("Enter data");
                    scanf("%d",&newnode->data);
                    while(i<pos){
                        temp=temp->next;
                        i++;
                    }
                    newnode->next=temp->next;
                    temp->next=newnode;
                    printf("Inserted at position\n");
                }
                break;
            case 4:
                temp=head;
                head=head->next;
                free(temp);
                printf("Deleted at beginning\n");
                break;
            case 5:
                struct node *prevnode;
                temp=head;
                while(temp->next!=0){
                    prevnode=temp;
                    temp=temp->next;
                }
                if(temp==head){
                    head=0;
                }
                else{
                    prevnode->next=0;
                }
                free(temp);
                printf("Deleted at end\n");
                break;
            case 6:
                if (head == NULL) {
                    printf("List is empty\n");
                } else {
                    printf("Enter position:");
                    scanf("%d", &pos);
                    if (pos < 1) {
                        printf("Invalid position\n");
                    } else if (pos == 1) {
                        temp = head;
                        head = head->next;
                        free(temp);
                    } else {
                        temp = head;
                        i = 1;
                        while (i < pos - 1 && temp != NULL) {
                            temp = temp->next;
                            i++;
                        }
                        if (temp == NULL || temp->next == NULL) {
                            printf("Invalid position\n");
                        } else {
                            struct node* toDelete = temp->next;
                            temp->next = toDelete->next;
                            free(toDelete);
                        }
                    }
                    printf("Deleted at position\n");
                }
                break;               
            case 7:
                count=0;
                temp = head;
                printf("Linked List: ");
                while (temp != 0) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                    count++;
                }printf("\n");
                printf("No. of elemenys in the list are %d",count);
                printf("\n");
                break;
            case 8:
                struct node *currentnode,*nextnode;
                prevnode=0;
                currentnode=nextnode=head;
                while(nextnode!=0){
                    nextnode=nextnode->next;
                    currentnode->next=prevnode;
                    prevnode=currentnode;
                    currentnode=nextnode;
                }head=prevnode;
                break;
            case 0:
                printf("Exit\n");
                break;
                
            default:
                printf("Invalid option! please enter a valid choice\n");
        }       
    }while(choice!=0);
    
    temp = head;
    while (temp != NULL) {
        struct node* toFree = temp;
        temp = temp->next;
        free(toFree);
    }

    return 0;
}
