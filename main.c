#include <stdio.h>

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

    /*
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", coins[i]);
    }
    printf("\n");
    */

    /*
    char str[20];

    // Format the number with at most two digits after the decimal point
    snprintf(str, sizeof(str), "%.2f", to_change);
    printf("To change: %s\n", str);

    float decimal_part = 0.0;
    int decimal_places = 0;
    int decimal_found = 0;

    // Parse the string to find the decimal part
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            decimal_found = 1;
        } else if (decimal_found && decimal_places < 2 && str[i] >= '0' && str[i] <= '9') {
            decimal_part = decimal_part * 10 + (str[i] - '0');
            decimal_places++;
        }
    }

    // Adjust the decimal part to have the correct value
    while (decimal_places < 2) {
        decimal_part *= 10;
        decimal_places++;
    }
    decimal_part /= 100.0;

    printf("Decimal part: %.2f\n", decimal_part);
    */

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

    /*
int before_decimal_point = (int) to_change;
float after_decimal_point = to_change - before_decimal_point;
printf("Before decimal point: %d\n", before_decimal_point);
printf("After decimal point: %.2f\n", after_decimal_point);

int num_of_coins = 0;
int i = 0;
while (i < n && coins[i] >= 1) {
        if (before_decimal_point >= coins[i]) {
            int temp = before_decimal_point / coins[i];
            num_of_coins += temp;
            before_decimal_point -= (temp * coins[i]);
            printf("%d coins of type %d\n", temp, (int)coins[i]);
        } else {
            printf("0 coins of type %d\n", (int)coins[i]);
        }
    i++;
}

while (i < n) {
    if (after_decimal_point >= coins[i]-1) {
        int temp = after_decimal_point / coins[i];
        num_of_coins += temp;
        after_decimal_point -= (temp * coins[i]);
        printf("%d coins of type %.2f\n", temp, coins[i]);
    } else {
        printf("0 coins of type %.2f\n", coins[i]);
    }
    i++;
}
if (before_decimal_point == 0 && after_decimal_point == 0.000000) {
    printf("Returned exact change!\n");
} else {
    if (before_decimal_point != 0 && after_decimal_point == 0.000000) {
        printf("Exact change is impossible! %d\n", before_decimal_point);
    } else if (before_decimal_point == 0 && after_decimal_point != 0.000000) {
        printf("Exact change is impossible! %.2f\n", after_decimal_point);
    } else {
        float temp = before_decimal_point + after_decimal_point;
        printf("Exact change is impossible! %.2f\n", temp);
    }
}
printf("%d coins are needed for change\n", num_of_coins);
}
/*

//Part 2:

/* Gets the address of an array of integers, and the size of the array,
and returns the address of the first element in the copy of the array */
}

int *copyarray(int *elements, int size) {
    int *p_to_first_element = elements;
    int i = 0;
    while (i < size) {
        int *p_temp = (p_to_first_element + i);
        *p_temp = *(elements + i);
        i++;
    }
    return p_to_first_element;
}

/* Gets the address of an array of integers, and the size of the array,
   and returns the address of the first element in the sorted array */
int *sort_arr(int *elements, int size) {
    int *p_to_elements = elements;
    for (int j = 1; j < size; j++) {
        int value = *(p_to_elements + j);
        int i = j - 1;
        while ((i >= 0) && (*(p_to_elements + i)) > value) {
            int *p_temp = (p_to_elements + (i + 1));
            *p_temp = *(p_to_elements + i);
            --i;
        }
        int *p_temp = (p_to_elements + (i + 1));
        *p_temp = value;
    }
    return p_to_elements;
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
    printf("%x and %x\n", &elements[0], &elements + 1);

    int *p_copy = copyarray(&elements[0], size);
    printf("{");
    int i = 0;
    while (i < size - 1) {
        printf("%d, ", *p_copy);
        p_copy++;
        i++;
    }
    printf("%d}\n", *p_copy);
    printf("%x and %x and %x\n", &elements[0], p_copy, p_copy + 1);

    int *p_sort_of_arr = sort_arr(&elements[0], size);
    printf("{");
    i = 0;
    while (i < size - 1) {
        printf("%d, ", *p_sort_of_arr);
        p_sort_of_arr++;
        i++;
    }
    printf("%d}\n", *p_sort_of_arr);
    printf("%x and %x\n", &elements[0], p_sort_of_arr + 1);
    return 0;
}
