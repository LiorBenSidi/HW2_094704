#include <stdio.h>
#include <stdlib.h>

/* Gets the number of coins, the coins array, and the amount to change,
   and prints the number of coins needed for change of each coin type,
   the amount of change left, if the exact change is impossible,
   and the number of coins needed for change */
void change_regular(int n, float coins[], float to_change) {
    // Check if the number of coins is 0
    /*
    if (n == 0) {
        printf("Error: no coins\n");
        return;
    }
    */

    // Check if the amount to change is negative
    if (to_change < 0) {
        printf("Error: negative amount\n");
        return;
    }

    // A pointer to the first element in the coins array
    float *p_to_elements = &coins[0];

    // Sort the array in descending order,
    // using the insertion sort algorithm,
    // to get the coins in descending order,
    // without duplicates
    for (int j = 1; j < n; j++) {
        // Insert elements[j] into the sorted sequence elements,
        // till the element, elements[j-1],
        float value = p_to_elements[j];
        int i = j - 1;
        // Find the correct position for elements[j] in the sorted sequence
        while ((i >= 0) && (p_to_elements[i] < value)) {
            // Shift elements[i] to the right
            float *p_temp = (p_to_elements + (i + 1));
            // Insert elements[j] into the correct position
            *p_temp = *(p_to_elements + i);
            i--;
        }
        // Insert elements[j] into the correct position
        float *p_temp = (p_to_elements + (i + 1));
        // Insert elements[j] into the correct position
        *p_temp = value;
    }
    // Remove duplicates
    int new_n = 0;
    // Loop through the sorted coins array
    for (int i = 0; i < n; i++) {
        // Check if the current element is not a duplicate
        if ((i == 0) || (p_to_elements[i] != p_to_elements[i - 1])) {
            // if unique element, copy it to the correct position
            p_to_elements[new_n] = p_to_elements[i];
            new_n++;
        }
    }

    // after finish get rid of duplicates,
    // update the number of elements to the number of unique elements
    n = new_n;

    // Check if the amount to change is 0
    if (to_change == 0) {
        for (int i = 0; i < n; i++) {
            // Print 0 coins of the current coin, if the coin is an integer
            if (coins[i] == (int)coins[i])//(int)coins[i] < coins[i]
                printf("0 coins of type %d\n", (int)coins[i]);
            else // Print 0 coins of the current coin, if the coin is a float
                printf("0 coins of type %.2f\n", coins[i]);
        }
        printf("Returned exact change!\n");
        printf("0 coins are needed for change\n");
        return;
    }

    // A variable to store the amount of change left
    // To avoid floating point errors, and to handle the case of 0.01,
    // we add 0.001 to the change_left, before comparing it with the coin
    float change_left = to_change + 0.001;
    // A variable to store the number of coins needed
    int num_of_coins = 0;
    int i = 0;
    // Loop through the coins array
    while (i < n) {
        // Check if the amount left is greater than the current coin
        // with a precision of at most 2 decimal places after the point.
        if (change_left >= coins[i]) {
            // Calculate the number of coins needed
            int temp = change_left / coins[i];
            // Update the number of coins needed
            num_of_coins += temp;
            // Update the amount of change left
            change_left -= (temp * coins[i]);
            // Print the number of coins needed, if the coin is an integer
            if (coins[i] == (int)coins[i])
                printf("%d coins of type %d\n", temp, (int)coins[i]);
            else // Print the number of coins needed, if the coin is a float
                printf("%d coins of type %.2f\n", temp, coins[i]);

            // Print 0 coins of the current coin,
            // if the amount left is less than the current coin
        } else {
            // Print 0 coins of the current coin, if the coin is an integer
            if (coins[i] == (int)coins[i])
                printf("0 coins of type %d\n", (int)coins[i]);
            else // Print 0 coins of the current coin, if the coin is a float
                printf("0 coins of type %.2f\n", coins[i]);
        }
        i++;
    }

    // Check if the amount of change left is 0, while assume the precision of
    // the amount of change left is at most 2 decimal places after the point
    if ((change_left == 0) || ((change_left * 100) < 1)) {
        printf("Returned exact change!\n");

        // Print the amount of change left,
        // if the amount of change left is not 0
    } else {
        // Print the amount of change left,
        // if the amount of change left is an integer
        if (change_left == (int)change_left) {
            printf("Exact change is impossible! %d reminded.\n",
                          (int)change_left);
            // Print the amount of change left,
            // if the amount of change left is a float
        } else {
            printf("Exact change is impossible! %.2f reminded.\n",
                          change_left);
        }
    }

    // Print the number of coins needed for change
    printf("%d coins are needed for change\n", num_of_coins);
}


/* Gets the address of an array of integers, and the size of the array,
   and returns the address of the first element in the copy of the array,
   using dynamic allocation */
int *copyarray(int *elements, int size) {
    // Check if the input is invalid
    if (elements == NULL || size < 0) {
        printf("Invalid input\n");
        return 0;
    }

    // Dynamically allocate memory for the new array
    int *elements_copy = (int *)malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (elements_copy == NULL) {
        printf("Out of Memory\n");
        return 0;
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

    // Sort the array in ascending order,
    // using the insertion sort algorithm
    for (int j = 1; j < size; j++) {
        // Insert elements[j] into the sorted sequence elements,
        // till the element, elements[j-1],
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

/* For testing purposes:
   Gets the address of an array of integers, and the size of the array,
   and prints the elements of the array */
void print_array(int *elements, int size) {
    printf("{");
    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            printf("%d, ", elements[i]);
        } else {
            printf("%d", elements[i]);
        }
    }
    printf("}\n");
}

void test_change_regular() {
    // Test case 1: Exact change possible
    float coins1[] = {2.00, 1.00, 0.50, 0.20, 0.10, 0.05, 0.02, 0.01};
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    float to_change1 = 5.00;

    printf("Test case 1:\n");
    change_regular(n1, coins1, to_change1);
    printf("\n");

    // Test case 2: Exact change impossible
    float coins2[] = {0.25, 0.10, 0.05};
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    float to_change2 = 0.31;

    printf("Test case 2:\n");
    change_regular(n2, coins2, to_change2);
    printf("\n");

    // Test case 3: Empty coin array
    float coins3[] = {};
    int n3 = 0;
    float to_change3 = 0.00;

    printf("Test case 3:\n");
    change_regular(n3, coins3, to_change3);
    printf("\n");

    // Test case 4: Large amount
    float coins4[] = {50.00, 20.00, 10.00, 5.00, 2.00, 1.00};
    int n4 = sizeof(coins4) / sizeof(coins4[0]);
    float to_change4 = 100.00;

    printf("Test case 4:\n");
    change_regular(n4, coins4, to_change4);
    printf("\n");

    // Test case 5: Single coin type
    float coins5[] = {1.00};
    int n5 = sizeof(coins5) / sizeof(coins5[0]);
    float to_change5 = 1.00;

    printf("Test case 5:\n");
    change_regular(n5, coins5, to_change5);
    printf("\n");
}

int main() {
    test_change_regular();
    // Test sort_arr function
    int arr1[] = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int *sorted_arr = sort_arr(arr1, size1);

    printf("Sorted array: ");
    for (int i = 0; i < size1; i++) {
        printf("%d ", sorted_arr[i]);
    }
    printf("\n");

    free(sorted_arr);

    // Test copyArray function
    int arr2[] = {10, 20, 30, 40, 50};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int *copied_arr = copyarray(arr2, size2);

    printf("Copied array: ");
    for (int i = 0; i < size2; i++) {
        printf("%d ", copied_arr[i]);
    }
    printf("\n");

    free(copied_arr);
    return 0;
}

