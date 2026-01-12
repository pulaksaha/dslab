#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define MAX 20

int stack[MAX];
int top=-1;

void push(int item){
    if(top==MAX-1){
        printf("StackOverflow\n");
    }
    stack[++top]=item;
}

int pop(){
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main(){
    char postfix[50],symb;
    int i, op1,op2,result;

    printf("Enter the postfix Expression\n");
    scanf("%s",postfix);

    for(i=0;postfix[i]!='\0';i++){

        symb =postfix[i];
        if(isdigit(symb)){
            push(symb-'\0'); //char to int
        }
        else{
            op2=pop();
            op1=pop();

            switch(symb){
                case'+':
                  push(op1+op2);
                  break;
                case'-':
                   push(op1-op2);
                   break;
                case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            case '%':
                push(op1 % op2);
                break;
            case '^':
               push((int)pow(op1,op2));
               break;
            default:
               printf("Invalid operator\n");
               exit(1);
                   
            }
        }
    }
    result =pop();
    printf("Result=%d\n",result);

    return 0;
}
