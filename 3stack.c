#include<stdio.h>
#include<string.h>
#define MAX 5

int stack[MAX];
int top=-1;

//push
void push(){
    int x;
    if(top==MAX-1){
        printf("stack overflow!\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &x);
    stack[++top]=x;
    printf("Element: %d pushed sucessfully\n",x);
}

//pop
void pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return;
    }
    printf("Popped element %d",stack[top--]);

}

//display
void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }

    printf("stack elements\n");
    for(int i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}

//pallindrome

void pallindrome(){
    char str[50],rev[50];
    int i,len;

    top=-1;
    printf("Enter string");
    scanf("%s",str);

    len=strlen(str);

    for(i=0;i<len;i++){
        stack[++top]=str[i];
    }

    for(i=0;i<len;i++){
        rev[i]=stack[top--];
    }

    rev[i]='\0';

    if(strcmp(str,rev)==0){
        printf("\n Pallindrome\n");
    }
    else{
        printf("Not a pallindrome");
    }
}

int main(){
    int choice;
    while(1){
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Palindrome Check\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: push(); break;
            case 2:pop(); break;
            case 3: pallindrome(); break;
            case 4:display(); break;
            case 5: return 0;
            default: printf("Invalid choice\n");
        }
    }
}