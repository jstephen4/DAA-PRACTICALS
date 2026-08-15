#include <stdio.h>

int main()
{
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements in ascending order:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &target);

    int low = 0, high = n - 1, mid, found = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (arr[mid] == target)
        {
            printf("Element %d found at position %d.\n", target, mid + 1);
            found = 1;
            break;
        }
        else if (target < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (!found)
        printf("Element not found.\n");

    return 0;
}
