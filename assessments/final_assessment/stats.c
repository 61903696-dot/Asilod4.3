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
 * @file course1.c 
 * @brief This file is to be used to week 1 application assignment.
 *
 * @author AYASH SHIYAS
 * @date April 2, 2025
 *
 */

#include <stdint.h>
#include "course1.h"
#include "platform.h"
#include "memory.h"
#include "data.h"
#include "stats.h"



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char *array, unsigned int length) {
  printf("Statistics of the array:\n");
  printf("Minimum: %u\n", find_minimum(array, length));
  printf("Maximum: %u\n", find_maximum(array, length));
  printf("Mean: %u\n", find_mean(array, length));
  printf("Median: %u\n", find_median(array, length));
}

void print_array(unsigned char *array, unsigned int length) {
  printf("Array: [");
  for (unsigned int i = 0; i < length; i++) {
    printf("%u", array[i]);
    if (i < length - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

unsigned char find_median(unsigned char *array, unsigned int length) {
  sort_array(array, length);
  if (length % 2 == 0) {
    return (array[length / 2 - 1] + array[length / 2]) / 2;
  } else {
    return array[length / 2];
  }
}

unsigned char find_mean(unsigned char *array, unsigned int length) {
  unsigned int sum = 0;
  for (unsigned int i = 0; i < length; i++) {
    sum += array[i];
  }
  return sum / length;
}

unsigned char find_maximum(unsigned char *array, unsigned int length) {
  unsigned char max = array[0];
  for (unsigned int i = 1; i < length; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *array, unsigned int length) {
  unsigned char min = array[0];
  for (unsigned int i = 1; i < length; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

void sort_array(unsigned char *array, unsigned int length) {
  for (unsigned int i = 0; i < length - 1; i++) {
    for (unsigned int j = 0; j < length - i - 1; j++) {
      if (array[j] < array[j + 1]) {
        unsigned char temp = array[j];
        array[j] = array[j + 1];
        array[j + 1] = temp;
      }
    }
  }
}

int main() {
  unsigned char test[SIZE] = {
      34, 201, 200, 154, 8,   194, 2,   6,   239, 235, 19,  18,  18,  18,
      18, 67,  107, 80,  88,  88,  88,  88,  88,  69,  42,  112, 16,  89,
      89, 89,  89,  89,  98,  1,   95,  135, 16,  17,  43,  2};

  printf("Original Array:\n");
  print_array(test, SIZE);

  print_statistics(test, SIZE);

  sort_array(test, SIZE);

  printf("\nSorted Array:\n");
  print_array(test, SIZE);

  return 0;
}
