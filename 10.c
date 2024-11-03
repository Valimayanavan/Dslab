#include <stdio.h>
#include <math.h>

#define MAX 100

void swap(int *p, int *q);
void display(int a[], int n);
void insert(int a[], int *n, int data);
int del_hi_priori(int a[], int *n);

int parent(int i);
int left(int i);
int right(int i);

int main() {
    int choice, num, n = 0, a[MAX], data, s;

    while (1) {
        printf(".....MAIN MENU.....\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to be inserted: ");
                scanf("%d", &data);
                insert(a, &n, data);
                break;

            case 2:
                s = del_hi_priori(a, &n);
                if (s != 0)
                    printf("The deleted value is: %d\n", s);
                break;

            case 3:
                display(a, n);
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}

void insert(int a[], int *n, int data) {
    if (*n >= MAX) {
        printf("Queue is Full\n");
        return;
    }

    int i = (*n)++;
    a[i] = data;

    // Heapify-up
    while (i != 0 && a[parent(i)] < a[i]) {
        swap(&a[i], &a[parent(i)]);
        i = parent(i);
    }
}

int del_hi_priori(int a[], int *n) {
    if (*n <= 0) {
        printf("Queue is Empty!\n");
        return 0;
    }

    int root = a[0];
    a[0] = a[--(*n)];

    // Heapify-down
    int i = 0;
    while (1) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < *n && a[l] > a[largest])
            largest = l;
        if (r < *n && a[r] > a[largest])
            largest = r;

        if (largest == i)
            break;

        swap(&a[i], &a[largest]);
        i = largest;
    }
    
    return root;
}

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void display(int a[], int n) {
    if (n == 0) {
        printf("Queue is Empty!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}
