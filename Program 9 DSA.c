#include <stdio.h>
#include <stdlib.h>
int visited[20],a[10][10]={0},n;
void dfs(int u)
{
    int v;
    s[u]=1;
    printf("->%d",u);
    for(v=0;v<n;v++)
    {
        if(a[u][v]==1&&s[v]==0)
            dfs(v);
    }
}
void bfs(int v)
{
    int queue[10], front = -1, rear = -1, i, cur;
    visited[v] = 1;
    queue[++rear] = v;
    printf("%d",v);
    while(front != rear)
    {
        cur = queue[++front];
        for(i=0; i<n; i++)
        {
            if(a[cur][i] && !s[i])
            {
                s[i] = 1;
                queue[++rear] = i;
                printf("%d",i);
            }
        }
    }
}

int main()
{
    int i,j,start;
    printf("Enter value of n\n");
    scanf("%d",&n);
    printf("Enter values of adjacency matrix\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter starting vertex\n");
    scanf("%d",&start);
    for(i=0;i<20;i++)
        s[i]=0;
    printf("DFS from %d : ",start);
    dfs(start);
    for(i=0;i<20;i++)
        s[i]=0;
    printf("BFS from %d : ",start);
    bfs(start);
    return 0;
}
