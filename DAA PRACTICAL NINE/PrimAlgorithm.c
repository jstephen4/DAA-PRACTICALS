#include <stdio.h>

#define INF 999

int main()
{
    int cost[10][10], visited[10] = {0};
    int n, i, j, u, v, min, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;

    printf("\nEdges in Minimum Spanning Tree:\n");

    for(i = 0; i < n - 1; i++)
    {
        min = INF;

        for(j = 0; j < n; j++)
        {
            if(visited[j])
            {
                int k;

                for(k = 0; k < n; k++)
                {
                    if(!visited[k] && cost[j][k] < min)
                    {
                        min = cost[j][k];
                        u = j;
                        v = k;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);
        total += min;
        visited[v] = 1;
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}
