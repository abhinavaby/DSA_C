#include <stdio.h>
#define MAX 20
int main()
{
    int graph[MAX][MAX];
    int visited[MAX]={0};
    int queue[MAX];
     
    int n,i,j;
    int start;
    int front = 0,rear = -1;
    int vertex;

    printf("enetr the number of vertices: ");
    scanf("%d",&n);
    printf("enter the adjacent matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        scanf("%d",&graph[i][j]);
        }
}
printf("enter thr starting vertex: ");
scanf("%d",&start);
visited[start]=1;
queue[++rear]=start;
printf("BFS Traversal: ");    
while(front<=rear)
{
    vertex =queue[front++];
    printf("%d",vertex);
    for(i=0;i<n;i++){
            if (graph[vertex][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                queue[++rear]=i;
            }
        
    }
}     
return 0; 
}
