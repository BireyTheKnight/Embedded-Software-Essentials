/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 *
 *****************************************************************************/

/**
 * @file stats.c
 * @brief Implementations of array analyzing functions
 *
 *  Functions within this source file can analyze an array of unsigned
 *  char data items and report analytics on the maximum, minimum, mean,
 *  and median of the data set
 *
 * @author Birey Kadıoğlu
 * @date 02/05/2023
 *
 */


/* #include <stdio.h> */
#include "stats.h"
#include "../include/common/platform.h"

#define SIZE (40)

/************************************************************************
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  
  unsigned char median = 0;
  unsigned char mean = 0;
  unsigned char maximum = 0;
  unsigned char minimum = 0; 


  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  maximum = find_maximum(test, SIZE);
  minimum = find_minimum(test, SIZE);
  sort_array(test, SIZE);
  print_array(test, SIZE);
  print_statistics(test, SIZE);

}  
*******************************************************************/

void sort_array(unsigned char *array, unsigned int array_length){
  
  int i;
  int j;
  int temp = 0;

  for (i = 0; i < array_length-1; i++){
    for (j = i+1; j < array_length; j++){

      if ( *(array+i) < *(array+j) ){
        
	temp = *(array+i);
        *(array+i) = *(array+j);
	*(array+j) = temp;
      
      }
      else{

        continue;

      }
    }
  }
}


void print_array(unsigned char *array, unsigned int array_length){
  
  PRINTF("The Array:\n");

  int i;

  for (i = 0; i < array_length; i++){

    PRINTF("%d ", *(array+i));

  }
  
  PRINTF("\n\n");

}
  

unsigned char find_median(unsigned char *array, unsigned int array_length){
  
  sort_array(array, array_length);

  unsigned char median = 0;

  if (array_length % 2 == 0){

    median = (*(array+(array_length/2)) + *(array+(array_length/2)-1))/2;
  
  }
  else{

    median = *(array+((array_length-1)/2));
  
  }

  return median;  
}


unsigned char find_mean(unsigned char *array, unsigned int array_length){
  
  int i;
  int mean = 0;
  int sum = 0;

  for (i = 0; i < array_length; i++){

    sum = sum + *(array+i);

  }
  
  mean = sum / array_length;

  return mean;

}


unsigned char find_maximum(unsigned char *array, unsigned int array_length){
  
  int i;
  int maximum = *array;
  for (i = 1; i < array_length; i++){
  
    if ( maximum < *(array+i) ){
    
      maximum = *(array+i);
    
    }
    else{
    
      continue;
    
    }  
  }

  return maximum;

}

  
unsigned char find_minimum(unsigned char *array, unsigned int array_length){

  int i;
  int minimum = *array;
  for (i = 1; i < array_length; i++){

    if ( minimum > *(array+i) ){

      minimum = *(array+i);

    }
    else{

      continue;

    }
  }

  return minimum;
  
}
 
 
void print_statistics(unsigned char *array, unsigned int array_length){
  
  PRINTF("Statistics Of The Array:\n");
  PRINTF("Mean = %d\n", find_mean(array, array_length));
  PRINTF("Median = %d\n", find_median(array, array_length));
  PRINTF("Maximum = %d\n", find_maximum(array, array_length));
  PRINTF("Minimum = %d\n", find_minimum(array, array_length));

}
