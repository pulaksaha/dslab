#include<stdio.h>
#include<ctype.h>

#define max 50
char stack[max];
int top=-1;

//push
void push(char x){
    stack[++top]=x;
}

//pop
char pop(){
    return stack[top--];
}

//precedence
int precedence(char x){
    if(x =='^') return 3;
    if(x=='*'||x=='/'||x=='%') return 2;
    if(x=='+'||x=='-') return 1;

return 0;
}

//main
int main(){
    char infix[50],postfix[50];
    int i=0,j=0;
    char ch;

   printf("\n Enter infix expression\n");
   scanf("%s",infix);

   while((ch=infix[i++]) !='\0'){
      
       if(isalnum(ch)){
        postfix[j++]=ch;
       }
       else if(ch=='('){
         push(ch);
       }
       else if(ch==')'){
        while(stack[top]!='(') 
           postfix[j++]= pop();
        pop(); //remove )
       }
       else{
          while(top!=-1 && precedence(stack[top])>=precedence(ch))
            postfix[j++]=pop();
            
        push(ch);
          
       }
   }
   while(top!=-1)
     postfix[j++]=pop();
   
   postfix[j]='\0';
   printf("Postfix Expression: %s\n", postfix);

return 0;
}