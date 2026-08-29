#include <stdio.h>
#include <limits.h>

int main()
{
    int n, p[20], dp[20][20];
    int i, j, k, len, cost;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    printf("Enter %d dimensions: ", n + 1);
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Cost is 0 for one matrix
    for (i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }

    // Find minimum multiplication cost
    for (len = 2; len <= n; len++)
    {
        for (i = 1; i <= n - len + 1; i++)
        {
            j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (k = i; k < j; k++)
            {
                cost = dp[i][k] + dp[k + 1][j]
                     + p[i - 1] * p[k] * p[j];

                if (cost < dp[i][j])
                {
                    dp[i][j] = cost;
                }
            }
        }
    }

    printf("Minimum number of multiplications = %d\n", dp[1][n]);

    return 0;
}