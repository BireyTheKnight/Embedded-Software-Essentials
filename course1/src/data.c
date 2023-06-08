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
 * @file data.c
 * @brief Implementations of data manipulating functions
 *
 * Functions within this source file can convert an ASCII string into an
 * integer and vice versa
 *
 * @author Birey Kadıoğlu
 * @date 02/05/2023
 *
 */

#include <stdint.h>
#include "data.h"
#include "memory.h"


uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){

  int8_t sign = 0;
  if (data < 0){
  
    sign = 1;
    data = -data;
  
  }

  if (data == 0){
  
    *ptr = '0';
    *(ptr+1) = '\0';
    return 2; 

  }
  else{
  
    uint32_t remainder;
    uint8_t length = 0;
    while (data > 0){
    
      remainder = data % base;
      if (remainder < 10){
      
        *(ptr+length) = remainder + '0';

      }
      else{
      
        *(ptr+length) = remainder - 10 + 'A';
      
      }

      data /= base;
      length++;
    
    }
  
    if (sign){
  
      *(ptr+length) = '-';
      length++;
  
    }

    my_reverse(ptr, length);
    *(ptr+length) = '\0';
    length++;

    return length;
  
  }  
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){

  int32_t data = 0;
  int8_t sign = 1;

  if (*ptr == '-'){
  
    sign = -1;
    digits--;
    ptr++;
  
  }

  while (digits > 1){
  
    uint8_t digit = *ptr;
    int32_t value;

    if (digit >= '0' && digit <= '9'){
    
      value = digit - '0';
    
    }
    else if (digit >= 'A' && digit <= 'F'){
    
      value = digit - 'A' + 10;
    
    }
  
    data = data * base + value;
    digits--;
    ptr++;

  }

  data = data * sign;

  return data;

}


