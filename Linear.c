#include <stdio.h>

void main() {
    int array[100], search, c, number,found;
    clrscr();
    printf("Enter the number of elements in array: ");
    scanf("%d", &number);

    printf("Enter %d numbers:\n", number);
    for (c = 0; c < number; c++) {
        scanf("%d", &array[c]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &search);

    found = 0; 

    for (c = 0; c < number; c++) {
        if (array[c] == search) { 
            printf("%d is present at location %d\n", search, c + 1);
            found = 1; 
            break; 
        }
    }

    if (!found) { 
        printf("%d is not present in array\n", search);
    }

    getch();
}
