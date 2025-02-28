#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define N 11
#define min(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    int l, r;
} Interval;

void printArray(int array[N])
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%d, ", array[i]);
    }
}

void createArray(int array[N])
{
    int i;
    time_t t;

    srand((unsigned)time(&t));

    for (i = 0; i < N; i++)
    {
        array[i] = rand() % 1000000;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

void mergeSort(int arr[], int n)
{
    for (int tam = 1; tam < n; tam *= 2)
    {
        for (int i = 0; i < n; i += 2 * tam)
        {
            int l = i;
            int r = min(l + 2 * tam - 1, n - 1);
            int m = l + tam - 1;
            merge(arr, l, m, r);
        }
    }
}

void mergeSortPila(int arr[], int n) {
    Interval *stack = (Interval*)malloc(n * sizeof(Interval));
    int top = -1;

    stack[++top] = (Interval){0, n - 1};

    while (top >= 0) {
        Interval current = stack[top--];
        int l = current.l;
        int r = current.r;

        if (l < r) {
            int m = l + (r - l) / 2;

            stack[++top] = (Interval){l, m};
            stack[++top] = (Interval){m + 1, r};

            merge(arr, l, m, r);
        }
    }
    free(stack);
}

int main()
{
    static int arr[N];

    createArray(arr);
    printf("\n\nUNSORTED ARRAY:\n");
    printArray(arr);

    mergeSortPila(arr, N);

    printf("\n\nSORTED ARRAY:\n");
    printArray(arr);
    printf("\n\n");

    return 0;
}
