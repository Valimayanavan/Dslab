#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int i,j,k;
    int L[10];
    int R[10]; 

    for ( i = 0; i < n1; i++)
	L[i] = arr[l + i];
    for ( j = 0; j < n2; j++)
	R[j] = arr[m + 1 + j];

    i = 0, j = 0, k = l;

   
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

   
    while (i < n1) {
	arr[k] = L[i];
	i++;
	k++;
    }

   
    while (j < n2) {
	arr[k] = R[j];
	j++;
	k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
	int m = l + (r - l) / 2;

	mergeSort(arr, l, m);    
	mergeSort(arr, m + 1, r); 
	merge(arr, l, m, r);      
    }
}

void printArray(int A[], int size) {
    int i;
    for (i = 0; i < size; i++)
	printf("%d ", A[i]);
    printf("\n");
}

void main() {
    int n,i,arr[20];
  clrscr();
    printf("Enter the size of the array: ");
    scanf("%d", &n);


    printf("Enter %d elements of the array:\n", n);
    for ( i = 0; i < n; i++)
	scanf("%d", &arr[i]);

    printf("Given array is: \n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array is: \n");
    printArray(arr, n);

    getch();
}
