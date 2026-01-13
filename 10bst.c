#include<stdio.h>
#include<stdlib.h>

struct bst{
   int data;
   struct bst *left;
   struct bst *right;

};
typedef struct bst *node;

//create node
node create(int data){
    node newnode;
    newnode=(node)malloc(sizeof(struct bst));
    
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

//insert node
node insert(node root,int data){
    if(root==NULL){
        return create(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }
    else if(data>=root->data){
        root->right=insert(root->right,data);
    }
    return root;
}

//preorder
void preorder(node root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//inorder(l-root-right)
void inorder(node root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

//postorder
void postorder(node root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

//search
node search(node root,int key){
       if(root==NULL){
        printf("\nElement not found");
        return NULL;
       }
       if(root->data==key){
        printf("Element %d found\n",key);
       }
       if(key<root->data){
          return search(root->left,key);
       }
       else{
        return search(root->right,key);
       }
}


int main(){
    node root=NULL;
    int choice,data,key;
    printf("enter number of elements in bst\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    while(1){
        printf("\n1.Insert\n2.Preorder\n3.Inorder\n4.Postorder\n5.Search\n6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                for(int i=0;i<n;i++){
                    root=insert(root,arr[i]);
                }
                break;
            case 2:
                printf("Preorder traversal:\n");
                preorder(root);
                break;
            case 3:
                printf("Inorder traversal:\n");
                inorder(root);
                break;
            case 4:
                printf("Postorder traversal:\n");
                postorder(root);
                break;
            case 5:
                printf("Enter the element to be searched:\n");
                scanf("%d",&key);
                search(root,key);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
   return 0;
}

