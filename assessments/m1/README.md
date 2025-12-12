# Array Statistics and Sorting Project (C-Programming)

## Repository and Project Description

This repository contains the C-programming implementation for analyzing an array of unsigned character data items. The project includes functions to calculate the maximum, minimum, mean, and median of the dataset, and also to reorder (sort) the data set from largest to smallest.

The implementation is split into a header file (`stats.h`) for function declarations and an implementation file (`stats.c`) containing the main logic and a driver `main()` function for testing.

## Author Information

* **Author:** [Ralph Asilod]
* **Date:** [12/12/2025]
* **Course:** [Introduction to Embedded Systems and Software Development ESE Coursera Course 1]

## Files

1.  **`stats.c`**: The core implementation file containing all eight required functions.
2.  **`stats.h`**: The header file containing function declarations and documentation.
3.  **`README.md`**: This file, providing an overview of the project.

## Compilation and Execution

To compile and run this code using a standard C compiler (like GCC), use the following commands:

```bash
# Compile the stats.c file, creating an executable named stats.out
gcc -o stats.out stats.c -lm 

# Note: The '-lm' flag links the math library required for the round() function used in find_mean and find_median.

# Run the compiled program
./stats.out
