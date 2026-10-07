#include <stdio.h>

int a[10][10], n, visited[10];

void dfs(int v)
{
    int i;

    printf("%d ", v);
    visited[v] = 1;

    for(i = 0; i < n; i++)
    {
        if(a[v][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

void bfs(int start)
{
    int q[10];
    int front = 0, rear = 0;
    int visited[10] = {0};
    int i, v;

    q[rear] = start;
    rear++;
    visited[start] = 1;

    while(front < rear)
    {
        v = q[front];
        front++;

        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(a[v][i] == 1 && visited[i] == 0)
            {
                q[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("\nDFS: ");
    
    for(i = 0; i < n; i++)
        visited[i] = 0;

    dfs(start);

    printf("\nBFS: ");
    bfs(start);

    return 0;
}