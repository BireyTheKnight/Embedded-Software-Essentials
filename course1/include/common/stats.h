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
 * @file stats.h 
 * @brief Abstraction of array analyzing operations
 *
 *  This header file provides an abstraction of analyzing an array of unsigned
 *  char data items and report analytics on the maximum, minimum, mean,
 *  and median of the data set via function calls
 *
 * @author Birey Kadıoğlu
 * @date 02/05/2023
 *
 */


#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief Sorts a given array 
 *
 * Given an array of data and a length, sorts the array from largest to smallest
 *
 * @param Array An array of unsigned char data items
 * @param Length The length of the input array
 *
 * @return void
 */
void sort_array(unsigned char *array, unsigned int array_length);


/**
 * @brief Prints a given array to the screen
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param Array An array of unsigned char data items
 * @param Length The length of the input array
 *  
 * @return void
 */
void print_array(unsigned char *array, unsigned int array_length);


/**
 * @brief Finds the median value of a given array
 *
 * Given an array of data and a length, returns the median value
 * 
 * @param Array An array of unsigned char data items
 * @param Length The length of the input array
 * 
 * @return The median value
 */
unsigned char find_median(unsigned char *array, unsigned int array_length);


/**
 * @brief Finds the mean of a given array
 *
 * Given an array of data and a length, returns the mean
 * 
 * @param Array An array of unsigned char data items
 * @param Length The length of the input array
 * 
 * @return The mean value
 */
unsigned char find_mean(unsigned char *array, unsigned int array_length);

/**
 * @brief Finds the maximum of a given array
 * 
 * Given an array of data and a length, returns the maximum
 *
 * @param Array An array of unsigned char data items
 * @param Length The length of the input array
 *
 * @return The maximum value
 */
unsigned char find_maximum(unsigned char *array, unsigned int array_length);

/**
 * @brief Finds the minimum of a given array
 *
 * Given an array of data and a length, returns the minimum
 *
 * @param Array An array of unsigned char data items
 * @param Length The length of the input array
 *
 * @return The minimum value
 */
unsigned char find_minimum(unsigned char *array, unsigned int array_length);

/**
 * @brief Prints the statistics of a given array 
 *
 * Given an array of data and a length, prints the statistics of an array
 * including minimum, maximum, mean, and median.
 *
 * @param Array An array of unsigned char data items
 * @param Length The length of the input array
 * 
 * @return void
 */
void print_statistics(unsigned char *array, unsigned int array_length);


#endif /* __STATS_H__ */
