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
 * @file course1.h 
 * @brief This file is to be used for week 1 application assignment.
 *
 * @author AYASH SHIYAS
 * @date April 2, 2025
 *
 */

#ifndef STATS_H
#define STATS_H

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param array Pointer to the unsigned char array.
 * @param length The length of the array.
 */
void print_statistics(unsigned char *array, unsigned int length);

/**
 * @brief Prints the array to the screen.
 *
 * @param array Pointer to the unsigned char array.
 * @param length The length of the array.
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief Finds the median value of an array.
 *
 * @param array Pointer to the unsigned char array.
 * @param length The length of the array.
 * @return The median value.
 */
unsigned char find_median(unsigned char *array, unsigned int length);

/**
 * @brief Finds the mean value of an array.
 *
 * @param array Pointer to the unsigned char array.
 * @param length The length of the array.
 * @return The mean value.
 */
unsigned char find_mean(unsigned char *array, unsigned int length);

/**
 * @brief Finds the maximum value of an array.
 *
 * @param array Pointer to the unsigned char array.
 * @param length The length of the array.
 * @return The maximum value.
 */
unsigned char find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief Finds the minimum value of an array.
 *
 * @param array Pointer to the unsigned char array.
 * @param length The length of the array.
 * @return The minimum value.
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);

/**
 * @brief Sorts the array from largest to smallest.
 *
 * @param array Pointer to the unsigned char array.
 * @param length The length of the array.
 */
void sort_array(unsigned char *array, unsigned int length);

#endif /* STATS_H */
