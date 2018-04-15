/******************************************************************************
 * Copyright (C) 2018 by Andrei Sudakov - AO PKK MILANDR
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Andrei Sudakov and the AO PKK MILANDR are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Main entry point to the project 
 *
 * This file contains the main and other funtions code. These are
 * statistic functions for find minimum, maximum, mean, and 
 * median values of an array, print array and statistic, sort
 * array functions.
 *
 * @author Andrei Sudakov
 * @date April 15 2018
 *
 */

#include <stdio.h>
#include "stats.h"

#define array_size 9

int main(void) {
unsigned char tst_array[array_size] = {
  0x25, 0x13, 0x48, 0x33, 0x9A, 0xbd, 0xe3, 0xa2, 0x64
};
unsigned char sorted_tst_array[array_size];
int i;

  printf("Print array values unsorted\n");
  print_array(tst_array, array_size);
  printf("Print array values after sort\n");
  for (i=0; i<array_size; i++){
    sorted_tst_array[i] = tst_array[i];
  }
  sort_array(sorted_tst_array, array_size); 
  print_array(sorted_tst_array, array_size);
  printf("Print statistic values of an array \n");
  print_statistics(tst_array, array_size);
  
  return 0;
}
unsigned char find_maximum(unsigned char * ptr, unsigned int size) {
unsigned int i;
unsigned char found_max=0; /* Set to minimum value*/

  for (i=0;i<size;i++){
    if (found_max < ptr[i]){ /* if array value larger*/
      found_max = ptr[i]; /* store this value*/
    }
  }

  return (found_max);
}

unsigned char find_minimum(unsigned char * ptr, unsigned int size) {
unsigned int i;
unsigned char found_min=255; /* Set to maximum value*/

  for (i=0;i<size;i++){
    if (found_min > ptr[i]){ /* if array value less*/
      found_min = ptr[i]; /* store this value*/
    }
  }

  return (found_min);
}

unsigned char find_median(unsigned char * ptr, unsigned int size) {
unsigned char found_median;

  sort_array(ptr, size); /* call sort function before */
  if (size % 2){ /* if array size odd */
    found_median = ptr[size / 2];
  }
  else{ /* if array size even */
    found_median = (ptr[size / 2] + ptr[size / 2 - 1])/2;
  }
    
  return (found_median);
}

unsigned char find_mean(unsigned char * ptr, unsigned int size) {
unsigned int i;
unsigned long array_sum=0;
unsigned char found_mean;

  for (i=0;i<size;i++){
    array_sum += ptr[i]; /* summarize all the values */
  }
  found_mean = array_sum / size; /* Divide total value by the count */

  return (found_mean);
}

void print_statistics(unsigned char * ptr, unsigned int size) {
unsigned char maximum_value;
unsigned char minimum_value;
unsigned char median_value;
unsigned char mean_value;

  maximum_value = find_maximum(ptr, size); /* find maximum value */
  minimum_value = find_minimum(ptr, size); /* find minimum value */
  median_value = find_median(ptr, size); /* find median value */
  mean_value = find_mean(ptr, size); /* find mean value */
  
  printf("Maximum array value = 0x%x\n", maximum_value);
  printf("Minimum array value = 0x%x\n", minimum_value);
  printf("Median array value = 0x%x\n", median_value);
  printf("Mean array value = 0x%x\n", mean_value);
}

void print_array(unsigned char * ptr, unsigned int size) {
int i;

  for (i=0;i<size;i++) {
    printf("Array[%d] value = 0x%x\n", i, ptr[i]);
  }
}

void sort_array(unsigned char * ptr, unsigned int size) {
int i;
int j;
unsigned char tmp1;
unsigned char tmp2;
  
  for(i = 0; i < size; i++){
    for(j = 0; j < size - i - 1; j++){
      if(ptr[j] > ptr[j + 1]){ /* if current value is greater than  next */
        /* swap them */
        tmp1 = ptr[j];
        tmp2 = ptr[j + 1];  
        ptr[j] = tmp2;
        ptr[j+1] = tmp1;
      }
    } 
  }
}

