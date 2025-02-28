#include <stdio.h>

int ternarySearch(int arr[], int low, int high, int x)
{
    if (low > high)
        return - 1;
    int m1 = low + (high - low) / 3;
    int m2 = low + 2 * (high - low) / 3;
    if (arr[m1] == x)
        return m1;
    if (arr[m2] == x)
        return m2;
    if (x < arr[m1])
        return ternarySearch(arr, low, m1 - 1, x);
    if (x > arr[m1] && x < arr[m2])
        return ternarySearch(arr, m1 + 1, m2 - 1, x);
    return ternarySearch(arr, m2 + 1, high, x);
}

int main()
{
    int arr[] = { 2, 3, 4, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = ternarySearch(arr, 0, n - 1, x);
    if (result == -1) printf("Element is not present in array");
    else printf("Element is present at index %d", result);
    return 0;
}
