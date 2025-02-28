#include <stdio.h>
#include <math.h>

#define N 6

int maxsum = -1;
int bestArr1[N / 2], bestArr2[N / 2];

void dividirArr(int A[], int n, int count, int idx1, int idx2, int arr1[], int arr2[], int sum1, int sum2)
{
    if (n == count) {
        if (abs(sum1 - sum2) > maxsum) {
            maxsum = abs(sum1 - sum2);
            for (int i = 0; i < n / 2; i++) {
                bestArr1[i] = arr1[i];
                bestArr2[i] = arr2[i];
            }
        }
        return;
        
    }
    if (idx1 < n / 2) {
        arr1[idx1] = A[count];
        dividirArr(A, n, count + 1, idx1 + 1, idx2, arr1, arr2, sum1 + A[count], sum2);
    }
    if (idx2 < n / 2) {
        arr2[idx2] = A[count];
        dividirArr(A, n, count + 1, idx1, idx2 + 1, arr1, arr2, sum1, sum2 + A[count]);
    }
}

int main()
{
    int n = N;
    int A[] = {8, 4, 3, 7, 10, 9};
    int arr1[N / 2], arr2[N / 2];

    dividirArr(A, n, 0, 0, 0, arr1, arr2, 0, 0);
    for (int i = 0; i < n / 2; i++)
    {
        printf("%d ", bestArr1[i]);
    }
    printf("\n");
    for (int i = 0; i < n / 2; i++)
    {
        printf("%d ", bestArr2[i]);
    }

    return 0;
}