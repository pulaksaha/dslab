#include<stdio.h>
#include<stdlib.h>

struct Employee{
  char ssn[20],name[20], dept[20],designation[20];
  int sal;
  long int phno;
  struct Employee *prev;
  struct Employee *next;
};
typedef struct Employee *node;

node head=NULL;


//createnode
node create(){
    node newnode;
    newnode=(node)malloc(sizeof(struct Employee));
    printf("Enter SSN: ");
    scanf("%s", newnode->ssn);
    printf("Enter Name: ");
    scanf("%s", newnode->name);
    printf("Enter Department: ");
    scanf("%s", newnode->dept);
    printf("Enter Designation: ");
    scanf("%s", newnode->designation);
    printf("Enter Salary: ");
    scanf("%d", &newnode->sal);
    printf("Enter Phone Number: ");
    scanf("%ld", &newnode->phno);   

    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

//inserfront
node insertfront(){
    node newnode=create();
   
    if(head==NULL){
        head=newnode;
        return head;
    }
    newnode->next=head;
    newnode->prev=NULL;
    head->prev=newnode;
    head =newnode;

    return head;
}

//deletefront
node deletefront(){
    node temp;
    if(head==NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->next==NULL){
        printf("deleted element is %s\n",head->name);
        free(head);
        return NULL;
    }
    temp=head;
    head=head->next;
    head->prev=NULL;
    printf("deleted element is %s\n",temp->name);
    free(temp);
    return head;
}

//insertend
node insertend(){
    node newnode=create();
    node temp;
    temp=head;  
    if(head==NULL){
        head=newnode;
        return head;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    newnode->next=NULL;

    return head;
    
}

//deleteend
node deleteend(){
    node temp,prev;
    if(head==NULL){
        printf("list is empty");
        return NULL;
    }
    if(head->next==NULL){
        printf("deleted element is %s",head->name);
        free(head);
        return NULL;
    }
    temp=head;
    prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("deleted element is %s",temp->name);
    free(temp);

    return head;
}

//display
node display(){
    node temp;
    temp=head;

    if(temp==NULL){
        printf("List is empty\n");
    }
    printf("----------DLL CONTENTS---------\n");
    while(temp !=NULL){
        printf("SSN: %s\n",temp->ssn);
        printf("Name: %s\n",temp->name);
        printf("Department: %s\n",temp->dept);
        printf("Designation: %s\n",temp->designation);
        printf("Salary: %d\n",temp->sal);
        printf("Phone Number: %ld\n",temp->phno);
        printf("--------------------------\n");
        temp=temp->next;
    }
    return head;
}

int main(){
 int choice; 
    while(1){
        printf("\n--- DLL MENU ---\n");
        printf("1. Insert at Front\n");
        printf("2. Delete at Front\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
    
        switch(choice){
            case 1: insertfront(); break;
            case 2: deletefront(); break;
            case 3: insertend(); break;
            case 4: deleteend(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}