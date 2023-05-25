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
 * @file data.h 
 * @brief Abstraction of data manipulation operations
 *
 * This header file provides an abstraction of manipulating data by
 * conversion of data from ASCII string to integer and vice versa
 * via function calls
 *
 * @author Birey Kadıoğlu
 * @date 02/05/2023
 *
 */


#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

#define BASE_10 (10)
#define BASE_16 (16)

/**
 * @brief Converts data from integer into ASCII string
 *
 * Converts a signed 32-bit integer into an ASCII string given the
 * base and a pointer to copy the ASCII string to
 *
 * @param data Signed 32-bit integer to be converted 
 * @param ptr Pointer to the converted character string
 * @param base Integer value of the base to convert to
 *
 * @return Length of the converted data 
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);


/**
 * @brief Converts data from ASCII string into integer
 *
 * Converts an ASCII string into a signed 32-bit integer given the
 * base and the number of digits in the character set
 *
 * @param ptr Pointer to the ASCII character string to be converted
 * @param digits Number of digits in the character set
 * @param base Integer value of the base to convert to
 *
 * @return Converted signed 32-bit integer
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);


#endif /* __DATA_H__ */
