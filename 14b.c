#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

int h[TABLE_SIZE] = {NULL};

void insert() {
    int key, index, i, hkey;
    printf("\nEnter the number to insert in the hash table: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i * i) % TABLE_SIZE;

        if (h[index] == NULL) {
            h[index] = key;
            break;
        }
    }

    if (i == TABLE_SIZE) {
        printf("\nElement cannot be inserted\n");
    }
}

void search() {
    int key, index, i, hkey;
    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    hkey = key % TABLE_SIZE;

    for (i = 0; i < TABLE_SIZE; i++) {
        index = (hkey + i * i) % TABLE_SIZE;

        if (h[index] == key) {
            printf("Value is found at index %d\n", index);
            return;
        }
    }

    if (i == TABLE_SIZE) {
        printf("\nValue is not found\n");
    }
}

void display() {
    printf("\nElements in the hash table are:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("At index %d: value = %d\n", i, h[i]);
    }
}

void main() {
    int opt;
    clrscr();
    while (1) {
        printf("\nPress 1. Insert\t2. Display\t3. Search\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    getch();
}
