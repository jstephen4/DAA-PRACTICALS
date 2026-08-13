#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    int num = 40;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == num)
        {
            printf("The target value: %d", arr[mid]);
            return 0;
        }
        else if (arr[mid] > num)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("Number not found");
    return 0;
}