#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    int n, amount;

    printf("Enter number of denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter coin denominations:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    printf("Enter amount: ");
    scanf("%d", &amount);

    int dp[amount + 1];

    dp[0] = 0;

    // Initialize DP array
    for (int i = 1; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }

    // Dynamic Programming
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[amount] == INT_MAX)
        printf("Amount cannot be made using given coins.\n");
    else
        printf("Minimum number of coins = %d\n", dp[amount]);

    return 0;
}