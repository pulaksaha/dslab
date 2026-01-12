#include<stdio.h>
#include<stdlib.h>

struct student{
    char usn[20],name[20],programme[20];
    int sem;
    long int phno;
    struct student *next;
};
typedef struct student *node;

node head=NULL;

node createnode(){
    node newnode;
    newnode=(node)malloc(sizeof(struct student));

    printf("Enter USN: ");
    scanf("%s", newnode->usn);
    printf("Enter Name: ");
    scanf("%s", newnode->name);
    printf("Enter Programme: ");
    scanf("%s", newnode->programme);
    printf("Enter Semester: ");
    scanf("%d", &newnode->sem);
    printf("Enter Phone Number: ");
    scanf("%ld", &newnode->phno);

    newnode->next=NULL;
    return newnode;

}

//insertfront
node insertfront(){
    node newnode=createnode();
    newnode->next=head;
    head=newnode;
    return head;
}

//deletefront
node deletefront(){
    node temp;
    if(head==NULL){
        printf("List is empty");
        return head;
    }
    temp=head;
    head=temp->next;
    free(temp);
    return head;
}

//insertend
node insertend(){
    node temp;
    node newnode=createnode();

    if(head==NULL){
        head=newnode;
        return head;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
    return head;
}

//deleteend
node deleteend(){
    node prev,temp;
    if(head==NULL){
        printf("List is empty\n");
        return head;
    }
    if(head->next==NULL){
        printf("student %s",head->name);
        free(head);
        head =NULL;
        return head;
    }
    prev=NULL;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
    printf("student deleted %s",temp->name);
    free(temp);
    return head;
}

node display(){
    node temp;
    int count=0;

    if(head==NULL){
        printf("SLL is empty\n");
        return head;
    }
    temp=head;
    printf("Student details\n");

    while(temp!=NULL){
         printf("USN: %s | Name: %s | Programme: %s | Sem: %d | PhNo: %ld\n",
               temp->usn, temp->name, temp->programme, temp->sem, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("The total number of students =%d\n",count);
    return head;

}

int main(){
    int choice,n,i;
    while(1){
        printf("\n--- SLL MENU ---\n");
        printf("1. Create SLL using Front Insertion\n");
        printf("2. Display and Count\n");
        printf("3. Insert at End\n");
        printf("4. Delete at End\n");
        printf("5. Insert at Front (Stack Push)\n");
        printf("6. Delete at Front (Stack Pop)\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("Enter number of students\n");
                    scanf("%d",&n);
                    for(i=0;i<n;i++){
                        insertfront();
                    }
                    break;
            case 2: display(); break;
            case 3: insertend(); break;
            case 4: deleteend(); break;
            case 5: insertfront(); break;
            case 6: deletefront(); break;
            case 7: exit(0);
            default :  printf("Invalid choice\n");
        }
    }
    return 0;
}