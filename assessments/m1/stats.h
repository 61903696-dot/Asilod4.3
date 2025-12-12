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
#ifndef __STATS_H__
#define __STATS_H__

#include <stdio.h> // Include standard IO library for use in C files

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
void print_statistics(unsigned char *test_array, unsigned int length);

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
void print_array(unsigned char *test_array, unsigned int length);

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
unsigned char find_median(unsigned char *test_array, unsigned int length);

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
unsigned char find_mean(unsigned char *test_array, unsigned int length);

/**
 * @brief Finds the maximum value in the array.
 *
 * Given an array of data and a length, this function returns the maximum value.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return The unsigned char maximum value found.
 */
unsigned char find_maximum(unsigned char *test_array, unsigned int length);

/**
 * @brief Finds the minimum value in the array.
 *
 * Given an array of data and a length, this function returns the minimum value.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return The unsigned char minimum value found.
 */
unsigned char find_minimum(unsigned char *test_array, unsigned int length);

/**
 * @brief Sorts the array from largest to smallest.
 *
 * Given an array of data and a length, this function reorders the array
 * so the zeroth element is the largest value, and the last element (n-1)
 * is the smallest value.
 *
 * @param test_array The unsigned char pointer to an n-element data array.
 * @param length The unsigned integer size of the array.
 * @return No return value (void function). The array is sorted in place.
 */
void sort_array(unsigned char *test_array, unsigned int length);

#endif // __STATS_H__
