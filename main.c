#include <stdio.h>
#include <stdlib.h>

/* Gets the number of coins, the coins array, and the amount to change,
   and prints the number of coins needed for change of each coin type,
   the amount of change left, if the exact change is impossible,
   and the number of coins needed for change */
void change_regular(int n, float coins[], float to_change) {
    // Check if the number of coins is 0
    if (n == 0) {
        printf("Error: no coins\n");
        return;
    }

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

int main() {
    //part 1:
    // Test the change_regular method
    //exact change possible example:
    float coins[] = {10, 5,  1, 0.5, 0.1};
    int n = 5;
    float to_change = 6.80;
    change_regular(n, coins, to_change);
    printf("\n");

    //No Coins Provided (n = 0):
    float coins1[0] = {};
    n = 0;
    to_change = 5.0;
    change_regular(n, coins1, to_change);
    printf("\n");

    //Negative Amount to Change (to_change < 0):
    float coins2[3] = {1, 0.5, 0.25};
    n = 3;
    to_change = -2.0;
    change_regular(n, coins2, to_change);
    printf("\n");

    //Zero Amount to Change (to_change = 0):
    float coins3[3] = {1, 0.5, 0.25};
    n = 3;
    to_change = 0;
    change_regular(n, coins3, to_change);
    printf("\n");

    //Exact Change Possible:
    float coins4[] = {10, 5, 2,1,0.5,0.1};
    n = 6;
    to_change = 35.7;
    change_regular(n, coins4, to_change);
    printf("\n");

    //Exact Change Impossible:
    float coins5[] = {25, 17,15,0.89,0.05,0.04};
    n = 6;
    to_change = 22.33;
    change_regular(n, coins5, to_change);
    printf("\n");

    //Large Number of Coins Needed:
    float coins6[] = {1, 0.5, 0.25};
    n = 3;
    to_change = 20.0;
    change_regular(n, coins6, to_change);
    printf("\n");

    //Coins with Decimal Values:
    float coins7[] = {0.25, 0.1, 0.05};
    n = 3;
    to_change = 0.4;
    change_regular(n, coins7, to_change);
    printf("\n");

    //Duplicate Coin Values:
    float coins8[] = {6, 3, 2, 6, 2};
    n = 5;
    to_change = 7;
    change_regular(n, coins8, to_change);
    printf("\n");

    //Large Number of Coin Types:
    float coins9[] = {5, 2, 1, 0.5, 0.25, 0.1, 0.05, 0.01};
    n = 8;
    to_change = 3.76;
    change_regular(n, coins9, to_change);
    printf("\n\n");

    //part 2:
    // Test the copyarray method
    //Empty Array (size = 0):
    int array1[] = {};
    int size = 0;
    print_array(copyarray(array1, size), size);
    printf("\n");

    //Single Element Array (size = 1):
    int array2[] = {5};
    size = 1;
    print_array(copyarray(array2, size), size);
    printf("\n");

    //Large Array:
    int array3[1000]; // Initialize with some values
    size = 1000;
    print_array(copyarray(array3, size), size);
    printf("\n");

    //Null Pointer (elements = NULL):
    int *array4 = NULL;
    size = 10;
    copyarray(array4, size);
    printf("\n");

    //Negative Size (size < 0):
    int array5[] = {1, 2, 3};
    size = -3;
    copyarray(array5, size);
    printf("\n\n");

    // Test the sort_arr method
    //Empty Array (size = 0):
    int array6[] = {};
    size = 0;
    print_array(sort_arr(array6, size), size);
    printf("\n");

    //Single Element Array (size = 1):
    int array7[] = {5};
    size = 1;
    print_array(sort_arr(array7, size), size);
    printf("\n");

    //Array with All Equal Elements:
    int array8[] = {3, 3, 3, 3};
    size = 4;
    print_array(sort_arr(array8, size), size);
    printf("\n");

    //Array with Negative Elements:
    int array9[] = {-4, 2, -1, 0};
    size = 4;
    print_array(sort_arr(array9, size), size);
    printf("\n");

    //Large Array:
    int array10[1000]; // Initialize with some values
    size = 1000;
    print_array(sort_arr(array10, size), size);
    printf("\n");

    //Array with Duplicates:
    int array11[] = {5, 2, 5, 1, 2};
    size = 5;
    print_array(sort_arr(array11, size), size);
    printf("\n");

    //Sorted and Reverse Sorted Arrays:
    int sorted_array[] = {1, 2, 3, 4};
    size = 4;
    int *sorted = sort_arr(sorted_array, size);
    print_array(sorted, size);
    printf("\n");

    int reverse_sorted_array[] = {4, 3, 2, 1};
    size = 4;
    int *reverse_sorted = sort_arr(reverse_sorted_array, size);
    print_array(reverse_sorted, size);
    printf("\n");

    //negative size
    int array12[] = {1, 2, 3};
    size = -3;
    sort_arr(array12, size);
    printf("\n");

    //null pointer
    int *array13 = NULL;
    size = 10;
    sort_arr(array13, size);
}