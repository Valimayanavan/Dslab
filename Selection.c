#include <stdio.h>

void selectionSort(int array[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the first element
        temp = array[min_idx];
        array[min_idx] = array[i];
        array[i] = temp;
    }
}

void main() {
    int array[1000], n;
    clrscr();
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    printf("Enter elements in the list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    selectionSort(array, n);

    printf("Sorted list: ");
    for (int i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }

    getch();
}
