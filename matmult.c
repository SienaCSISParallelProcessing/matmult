/* 
   Matrix multiplication example

   Serial version

   Jim Teresco, CS 338, Williams College
   Mon Feb 10 10:55:31 EST 2003

   CS 341, Mount Holyoke College
   CS 400/CS 335, Siena College

*/

/* header files needed for printf, gettimeofday, struct timeval */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/* header file for our own timer.c function diffgettime */
#include "timer.h"

/* we will multiply square matrices, how big? */
#define SIZE 750

/* our matrices - global because of limited stack space in Solaris */
double a[SIZE][SIZE], b[SIZE][SIZE], c[SIZE][SIZE]; 

/* it's a simple program for now, we'll just put everything in main */
int main(int argc, char *argv[]) {
  double sum;

  /* counters */
  int i, j, k;

  /* to pass to gettimeofday to get wall clock times */
  struct timeval start, stop;

  /* initialize matrices, just fill with junk */
  gettimeofday(&start, NULL);
  for (i=0; i<SIZE; i++) {
    for (j=0; j<SIZE; j++) {
      a[i][j] = i+j;
      b[i][j] = i-j;
    }
  }
  gettimeofday(&stop, NULL);
  printf("Initialization took: %f seconds\n", diffgettime(start,stop));
  
  gettimeofday(&start, NULL);
  /* matrix-matrix multiply */
  for (i=0; i<SIZE; i++) {  /* for each row */
    for (j=0; j<SIZE; j++) { /* for each column */
      /* initialize result to 0 */
      c[i][j] = 0;

      /* perform dot product */
      for(k=0; k<SIZE; k++) {
	c[i][j] = c[i][j] + a[i][k]*b[k][j];
      }
    }
  }
  gettimeofday(&stop, NULL);
  printf("Multiplication took: %f seconds\n", diffgettime(start,stop));

  /* This is here to make sure the optimizing compiler doesn't
     get any big ideas about "optimizing" code away completely */
  sum=0;
  for (i=0; i<SIZE; i++) {
    for (j=0; j<SIZE; j++) {
      sum += c[i][j];
    }
  }
  printf("Sum of elements of c=%f\n", sum);

  return 0;
}
