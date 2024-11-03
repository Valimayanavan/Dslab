#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2]; // Temporary arrays for left and right subarrays

    for (int i = 0; i < n1; i++) 
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    // Merge the two halves back into arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);    // Sort the first half
        mergeSort(arr, m + 1, r); // Sort the second half
        merge(arr, l, m, r);      // Merge the two halves
    }
}

void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void main() {
    int n;
  clrscr();
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements of the array:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Given array is: \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array is: \n");
    printArray(arr, n);

    getch();
}
