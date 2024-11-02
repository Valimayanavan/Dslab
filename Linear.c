#include <stdio.h>

int main() {
    int array[100], search, c, number;

    printf("Enter the number of elements in array: ");
    scanf("%d", &number);

    printf("Enter %d numbers:\n", number);
    for (c = 0; c < number; c++) {
        scanf("%d", &array[c]);
    }

    printf("Enter the number to search: ");
    scanf("%d", &search);

    int found = 0; // Flag to indicate if the number was found

    for (c = 0; c < number; c++) {
        if (array[c] == search) { // Corrected to use '==' for comparison
            printf("%d is present at location %d\n", search, c + 1);
            found = 1; // Set flag to true
            break; // Exit loop if found
        }
    }

    if (!found) { // Check if the number was not found
        printf("%d is not present in array\n", search);
    }

    return 0;
}
