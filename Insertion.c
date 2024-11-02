#include <stdio.h>

int* insertionSort(int array[], int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }

    return array;
}

void main() {
    int array[1000], n, i;
    clrscr();
    printf("Enter the number of elements you want to sort: ");
    scanf("%d", &n);

    printf("Enter elements in the list:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    insertionSort(array, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");

getch();
}
