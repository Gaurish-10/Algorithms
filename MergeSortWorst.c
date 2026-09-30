#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int arr[], int left, int right) {
    for (int i = left; i <= right; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    printf("\nMerging:\n");
    printArray(L, 0, n1 - 1);
    printArray(R, 0, n2 - 1);

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];

    printf("After Merge: ");
    printArray(arr, left, right);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        printf("\nDividing: ");
        printArray(arr, left, right);

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("Enter a value between 1 and 1000.\n");
        return 0;
    }

    int arr[n];

    //Reverse Sorted
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }

    printf("\n---- Worst Case Input ----\n");

    printf("\nInput Size (n): %d\n", n);

    printf("\nReverse Sorted Input Array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    struct timespec start, end;

    printf("\nRecursive Division and Merge Process:\n");

    clock_gettime(CLOCK_MONOTONIC, &start);

    mergeSort(arr, 0, n - 1);

    clock_gettime(CLOCK_MONOTONIC, &end);

    long long execution_time =
        (end.tv_sec - start.tv_sec) * 1000000000LL +
        (end.tv_nsec - start.tv_nsec);

    printf("\nSorted Array After Merge Sort:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n\n---- Worst Case Analysis ----");

    printf("\n\nExecution Time: %lld nanoseconds\n", execution_time);

    printf("\nSpace Complexity Analysis:\n");
    printf("Auxiliary Space : O(n)\n");
    printf("Recursive Stack : O(log n)\n");

    printf("\nInput Size Used: %d elements\n", n);

    printf("\nTime Complexity:\n");
    printf("Worst Case : O(n log n)\n");

    return 0;
}