#include <stdio.h>

// Iterative Method
long long factorialIterative(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

// Recursive Method
long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorialRecursive(n - 1);
    }
}

int main()
{
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial is not defined for negative numbers.\n");
    }
    else
    {
        // Iterative factorial
        printf("Factorial using Iterative Method = %lld\n",
               factorialIterative(n));

        // Recursive factorial
        printf("Factorial using Recursive Method = %lld\n",
               factorialRecursive(n));
    }

    return 0;
}