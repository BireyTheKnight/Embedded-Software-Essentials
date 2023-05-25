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
 * @file memory.c
 * @brief Implementations of memory manipulation functions
 *
 * This source file contains implementations of memory manipulation
 * functions
 *
 * @author Birey Kadıoğlu
 * @date 02/05/2023
 *
 */


#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "memory.h"


/* Pre-existing code provided by Alex Fosdick - University of Colorado */      

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

/***********************************************************************/     



uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

  uint8_t *temp = malloc(length * sizeof(uint8_t));

  if (temp == NULL){
  	  
    return NULL;

  }

  my_memcopy(src, temp, length);
  my_memcopy(temp, dst, length);

  free(temp);

  return dst;

}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	
  for (size_t i = 0; i < length; i++){

    *(dst+i) = *(src+i);

  }

  return dst;

}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

  for (uint8_t i = 0; i < length; i++){
  
    *(src+i) = value;
	  
  }

  return src;
	
}

uint8_t * my_memzero(uint8_t * src, size_t length){

  for (uint8_t i = 0; i < length; i++){

    *(src+i) = 0;

  }
  
  return src;

	
}

uint8_t * my_reverse(uint8_t * src, size_t length){

  uint8_t *temp = malloc(length * sizeof(uint8_t));

  my_memcopy(src, temp, length);

  for (size_t i = 0; i < length; i++){

    *(src+i) = *(temp+length-1-i);
  
  }

  free(temp);

  return src;

}

int32_t * reserve_words(size_t length){

  int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));

  if (ptr == NULL){

    return NULL;

  }
  else{

  return ptr;  

  }
}

void free_words(int32_t * src){

  free(src);
	
}

