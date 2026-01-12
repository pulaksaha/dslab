#include<stdio.h>
#include<stdlib.h>

int adj[50][50];
int n;
int visited[50];

int queue[50],front=-1,rear=-1;

//bfs
void bfs(int v){
    
    int i,cur;
    front=-1,rear=-1;

    visited[v]=1;
    queue[++rear]=v;
    printf("%d",v);

    while(front!=rear){
        cur=queue[++front];

        for(i=1;i<=n;i++){
            if(adj[cur][i]==1 && visited[i]==0){
                   visited[i]=1;
                   queue[++rear]=i;
                   printf("%d",i);
            }
        }

    }
}

void dfs(int v){
    int i;
    visited[v]=1;
    printf("%d",v);

    for(i=1;i<=n;i++){
        if(adj[v][i]==1 && visited[i]==0){
                dfs(i);
        }
    }
}

int main(){
    int ch,start,i,j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter adjacency matrix:\n");
     for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &adj[i+1][j+1]);

    while(1){
         //reset all visited nodes
         for (i = 1; i <= n; i++)
            visited[i] = 0;
        
            //starting vertex
        printf("\nEnter starting vertex (1 to %d): ", n);
        scanf("%d", &start);

        printf("\n1. BFS");
        printf("\n2. DFS");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

         switch (ch)
        {
        case 1:printf("\nBFS traversal: ");
            bfs(start);
            break;
        case 2:
            printf("\nDFS traversal: ");
            dfs(start);
            break;
        case 3:
            exit(0);

        default:
            printf("\nInvalid choice");
        }
    }

 return 0;
}




