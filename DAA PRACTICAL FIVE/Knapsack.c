#include <stdio.h>

#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, capacity;
    int weight[MAX_ITEMS], profit[MAX_ITEMS];
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of %d items:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }

    printf("Enter the profits of %d items:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &profit[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Initialize first row and first column
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int w = 0; w <= capacity; w++)
    {
        dp[0][w] = 0;
    }

    // Build the DP table
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= capacity; w++)
        {
            if (weight[i - 1] <= w)
            {
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum profit = %d\n", dp[n][capacity]);

    // Find selected items
    printf("Selected items: ");

    int w = capacity;

    for (int i = n; i > 0 && w > 0; i--)
    {
        if (dp[i][w] != dp[i - 1][w])
        {
            printf("%d ", i);
            w = w - weight[i - 1];
        }
    }

    printf("\n");

    return 0;
}
