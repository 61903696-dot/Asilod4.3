/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file <C1M1 ASILOD> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Ralph Asilod>
 * @date <12/12/2025>
 *
 */



#include "stats.h"
#include <math.h> // Needed for the round() function for nearest integer

/* Define a constant for the array size as used in the assignment image */
#define SIZE (40)

/* Helper function to swap two unsigned chars */
void swap_values(unsigned char *a, unsigned char *b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Sorts the array from largest to smallest.
 *
 * Given an array of data and a length, this function reorders the array
 * so the zeroth element is the largest value, and the last element (n-1)
 * is the smallest value. (Descending order)
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return No return value (void function). The array is sorted in place.
 */
void sort_array(unsigned char *test_array, unsigned int length) {
    for (unsigned int i = 0; i < length - 1; i++) {
        // Find the maximum element in the unsorted array
        unsigned int max_index = i;
        for (unsigned int j = i + 1; j < length; j++) {
            // Find largest value (descending sort)
            if (test_array[j] > test_array[max_index]) {
                max_index = j;
            }
        }
        // Swap the found maximum element with the first element
        swap_values(&test_array[i], &test_array[max_index]);
    }
}


/**
 * @brief Prints the contents of an array.
 *
 * Given an array of data and a length, this function prints the array 
 * to the screen, nicely formatted with an indicator for the index.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return No return value (void function).
 */
void print_array(unsigned char *test_array, unsigned int length) {
    printf("--- Array Data ---\n");
    for (unsigned int i = 0; i < length; i++) {
        // Print 8 elements per line for clean formatting
        if (i % 8 == 0 && i != 0) {
            printf("\n");
        }
        printf("Index %02u: %3u | ", i, test_array[i]);
    }
    printf("\n------------------\n");
}

/**
 * @brief Finds the minimum value in the array.
 *
 * Given an array of data and a length, this function returns the minimum value.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return The unsigned char minimum value found.
 */
unsigned char find_minimum(unsigned char *test_array, unsigned int length) {
    unsigned char min_val = test_array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (test_array[i] < min_val) {
            min_val = test_array[i];
        }
    }
    return min_val;
}

/**
 * @brief Finds the maximum value in the array.
 *
 * Given an array of data and a length, this function returns the maximum value.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return The unsigned char maximum value found.
 */
unsigned char find_maximum(unsigned char *test_array, unsigned int length) {
    unsigned char max_val = test_array[0];
    for (unsigned int i = 1; i < length; i++) {
        if (test_array[i] > max_val) {
            max_val = test_array[i];
        }
    }
    return max_val;
}

/**
 * @brief Finds the mean (average) value of the array.
 *
 * Given an array of data and a length, this function calculates and
 * returns the arithmetic mean. The result is rounded to the nearest integer.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return The unsigned char result of the mean calculation.
 */
unsigned char find_mean(unsigned char *test_array, unsigned int length) {
    // Use a larger integer type for sum to prevent overflow, as max sum is 40 * 255 = 10200
    // unsigned int is generally sufficient.
    unsigned long sum = 0; 
    for (unsigned int i = 0; i < length; i++) {
        sum += test_array[i];
    }
    // Calculate mean and round it to the nearest integer
    // The round() function from <math.h> is used.
    double mean = (double)sum / length;
    return (unsigned char)round(mean);
}

/**
 * @brief Finds the median value of the array.
 *
 * Given a sorted array of data and a length, this function returns the
 * median value. The array must be sorted first for this to work correctly.
 * The result is rounded to the nearest integer.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return The unsigned char result of the median calculation.
 */
unsigned char find_median(unsigned char *test_array, unsigned int length) {
    if (length % 2 != 0) {
        // Odd number of elements: median is the middle element
        // Since the array is sorted descending, the middle index is length / 2
        return test_array[length / 2];
    } else {
        // Even number of elements: median is the average of the two middle elements
        // The two middle indices are (length/2) - 1 and (length/2)
        // Note: The result of the average should be rounded to the nearest integer.
        double avg = (double)(test_array[(length / 2) - 1] + test_array[length / 2]) / 2.0;
        return (unsigned char)round(avg);
    }
}

/**
 * @brief Prints the statistics of an array.
 *
 * This function calls find_minimum, find_maximum, find_mean, and
 * find_median, and then prints all results to the screen.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return No return value (void function).
 */
void print_statistics(unsigned char *test_array, unsigned int length) {
    printf("\n--- Array Statistics ---\n");
    printf("Minimum: %u\n", find_minimum(test_array, length));
    printf("Maximum: %u\n", find_maximum(test_array, length));
    printf("Mean:    %u\n", find_mean(test_array, length));
    printf("Median:  %u\n", find_median(test_array, length));
    printf("------------------------\n");
}


/**
 * @brief The main entry point for your program
 */
int main() {
    // The main function has an array of 40 characters defined for testing
    unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                                114, 88,   45,  76, 123,  87,  25,  23,
                                200, 122, 150,  90,  44,  86, 117, 216,
                                201,  81,  10, 219, 118, 117, 100, 121,
                                121, 101, 101, 101, 102, 103, 104, 105
                              };
    
    // 1. Initial Print
    printf("Original Array:\n");
    print_array(test, SIZE);

    // 2. Print Initial Statistics (on unsorted array, excluding median)
    printf("Statistics on UNSORTED array:\n");
    // Median is not correct until the array is sorted, but others are fine.
    printf("Minimum: %u\n", find_minimum(test, SIZE)); 
    printf("Maximum: %u\n", find_maximum(test, SIZE)); 
    printf("Mean:    %u\n", find_mean(test, SIZE)); 

    // 3. Sort the array
    sort_array(test, SIZE);

    // 4. Print Sorted Array
    printf("\nSorted Array (Largest to Smallest):\n");
    print_array(test, SIZE);
    
    // 5. Print Final Statistics
    printf("Statistics on SORTED array (Median is now correct):\n");
    print_statistics(test, SIZE);

    return 0;
}
