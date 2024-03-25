#include <stdio.h>
#include <stdlib.h>

//Part 1:
void change_regular(int n, float coins[], float to_change) {
    if (n == 0) {
        printf("Error: no coins\n");
        return;
    }
    if (to_change == 0) {
        for (int i = 0; i < n; i++) {
            printf("0 coins of type %f\n", coins[i]);
        }
        printf("Returned exact change!\n");
        printf("0 coins are needed for change\n");
        return;
    }
    if (to_change < 0) {
        printf("Error: negative amount\n");
        return;
    }

    // Sort the array in descending order
    int *p_to_elements = &coins[0];
    for (int j = 1; j < n; j++) {
        int value = *(p_to_elements + j);
        int i = j - 1;
        while ((i >= 0) && (*(p_to_elements + i) < value)) {
            int *p_temp = (p_to_elements + (i + 1));
            *p_temp = *(p_to_elements + i);
            i--;
        }
        int *p_temp = (p_to_elements + (i + 1));
        *p_temp = value;
    }

    float change_left = to_change;
    int num_of_coins = 0;
    int i = 0;
    while (i < n) {
        if (change_left >= coins[i]) {
            int temp = change_left / coins[i];
            num_of_coins += temp;
            change_left -= (temp * coins[i]);
            if (coins[i] == (int)coins[i])
                printf("%d coins of type %d\n", temp, (int)coins[i]);
            else
                printf("%d coins of type %.2f\n", temp, coins[i]);
        } else {
            if (coins[i] == (int)coins[i])
                printf("0 coins of type %d\n", (int)coins[i]);
            else
                printf("0 coins of type %.2f\n", coins[i]);
        }
        i++;
    }

    if ((change_left == 0) || ((change_left * 100) < 1)) {
        printf("Returned exact change!\n");
    } else {
        if (change_left == (int)change_left) {
            printf("Exact change is impossible! %d reminded.\n", (int)change_left);
        } else {
            printf("Exact change is impossible! %.2f reminded.\n", change_left);
        }
    }
    printf("%d coins are needed for change\n", num_of_coins);
}


/* Gets the address of an array of integers, and the size of the array,
   and returns the address of the first element in the copy of the array,
   using dynamic allocation */
int *copyarray(int *elements, int size) {
    // Dynamically allocate memory for the new array
    int *elements_copy = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (elements_copy == NULL) {
        printf("Out of Memory\n");
        exit(1);
    } else // Memory allocation was successful{
        printf("Memory allocated successfully\n");
        int i = 0;
        // Copy the elements of the array to the new array
        while (i < size) {
            elements_copy[i] = elements[i];
            i++;
        }

    // Return the address of the first element in the copy of the array
    return elements_copy;
}

/* Gets the address of an array of integers, and the size of the array,
   and returns the address of the first element in the sorted array,
   using dynamic allocation */
int *sort_arr(int *elements, int size) {
    // Copy the array, using the copyarray method, that using dynamic allocation
    int *elements_copy = copyarray(elements, size);
    // Sort the array in ascending order, using the insertion sort algorithm
    for (int j = 1; j < size; j++) {
        // Insert elements[j] into the sorted sequence elements[0..j-1]
        int value = elements_copy[j];
        int i = j - 1;
        // Find the correct position for elements[j] in the sorted sequence
        while ((i >= 0) && (elements_copy[i] > value)) {
            // Shift elements[i] to the right
            int *p_temp = (elements_copy + (i + 1));
            // Insert elements[j] into the correct position
            *p_temp = *(elements_copy + i);
            --i;
        }
        // Insert elements[j] into the correct position
        int *p_temp = (elements_copy + (i + 1));
        // Insert elements[j] into the correct position
        *p_temp = value;
    }

    // Return the address of the first element in the sorted array
    return elements_copy;
}


int main() {
    //Part 1:
    int n = 1;
    float coins[] = {5.5};
    float to_change = 7;
    change_regular(n, coins, to_change);

    //Part 2:
    int size = 6;
    int elements[6] = {2,7,6,4,5, 4};
    printf("%x\n", &elements);

    int *p_copy = copyarray(&elements[0], size);
    printf("{");
    int i = 0;
    while (i < size) {
        printf("%d, ", *p_copy);
        p_copy++;
        i++;
    }
    printf("%x\n", &p_copy[-1]);

    int *p_sort_of_arr = sort_arr(&elements[0], size);
    printf("{");
    i = 0;
    while (i < size) {
        printf("%d, ", *p_sort_of_arr);
        p_sort_of_arr++;
        i++;
    }
    printf("%x\n", &p_sort_of_arr[-1]);
    return 0;
}
