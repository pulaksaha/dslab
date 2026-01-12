#include<stdio.h>
#include<stdlib.h>

// Hash table pointer and table size
int *ht, m;
// Count of inserted elements
int count = 0;
// Index used for hashing
int idx;

//create
void create(){
    ht=(int*)malloc(m*sizeof(int));
    if(ht==NULL){
        printf("Memory not allocated\n");
        return;
    }

     for(int i=0;i<m;i++){
        ht[i]=-1; //initialize all locations as empty
    }

}


//insert
void insert(int key){
    idx=key%m;
    if(ht[idx]!=-1){
        idx=(idx+1)%m; //linear probing
    }
    ht[idx]=key;
    count++;
    printf("Key %d inserted at index %d\n",key,idx);
}


//display
void display(){
    printf("Hash Table\n");
    if(count==0){
        printf("Hash Table is empty\n");
        return;
    }
    printf("Index\tKey\n");
    for(int i=0;i<m;i++){
        printf("T[%d]\t-->%d\n",i,ht[i]);
    }
}

int main(){
    int choice,key;
    printf("Enter the size of hash table:");
    scanf("%d",&m);
    create();

    while(1){
         printf("\nMenu:\n");
        printf("1. Insert Key\n");
        printf("2. Display Hash Table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
                printf("Enter key to insert: ");
                scanf("%d",&key);
                insert(key);
                break;
                 case 2:
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

    }


}