#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<conio.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node* createNode(){
   struct node *p=(struct node*)malloc(sizeof(struct node));
   p->data=0;
   p->next=NULL;
   return(p);
}
void insertNodeAtStart(){
    int val;
    struct node *p=createNode();
    printf("Enter data for node: ");
    scanf("%d",&val);
    p->data=val;
    if(head==NULL){
        head=p;
    }
    else{
        p->next=head;
        head=p;
    }
}
void insertNodeAtLast(){
    int val;
    struct node *p=createNode();
    printf("Enter data for node: ");
    scanf("%d",&val);
    p->data=val;
    if(head==NULL){
        head=p;
    }
    else{
        struct node *q=head;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=p;
    }
}
void insertNodeAtSpecifiedPosition(){
    int val,nodeVal;
    struct node *p=createNode();
    printf("Enter data for node: ");
    scanf("%d",&val);
    p->data=val;
    printf("Enter data for node: ");
    scanf("%d",&nodeVal);
    if(head==NULL){
        printf("LinkedList is empty");
    }
    else{
        struct node *q=head;
        while(q!=NULL){
            if(q->data==nodeVal){
                break;
            }
            q=q->next;
        }
        if(q!=NULL){
            if(q->next!=NULL){
                p->next=q->next;
                q->next=p;
            }
            else{
                q->next=p;
            }
        }
        else{
            printf("Can't be inserted..Specified node not forund in the list");
        }
    }
}
void printLinkedList(){
    struct node *p=head;
    if(head==NULL){
        printf("\nLinkedList Is Empty");
    }
    else{
        while(p!=NULL){
            printf("%d ",p->data);
            p=p->next;
        }
    }
}
int menu(){
    int choice;
    printf("\n1. Insert At Start");
    printf("\n2. Insert At Last");
    printf("\n3. Insert At SpecifiedPos");
    printf("\n4. Print LinkedList");
    printf("\n5. Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    return(choice);
}
int main(){
    int flag=0;
    while(1){
        //clrscr();
        switch(menu()){
            case 1:
                insertNodeAtStart();
                break;
            case 2:
                insertNodeAtLast();
                break;
            case 3:
                insertNodeAtSpecifiedPosition();
                break;
            case 4:
                 printLinkedList();
                 break;
            case 5:
                 flag=1;
                 break;   
            default:
                printf("\nInvalid choice..That's good");
        }
        if(flag==1){
            break;
        }
    }
    return(0);
}
