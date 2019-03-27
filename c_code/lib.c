#include <stdio.h>

//sort the array with bubble sort
extern void sort(int array[], int x){

  for(int i=0; i<x-1; i++){
    for(int j=0; j<x-i-1; j++){
      if(array[j]>array[j+1]){
        int temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }

  //print out the sorted array
  printf("Sorted Sequence:\n");

  for(int i=0; i<x; i++){
    printf("%d ",array[i]);
  }
  printf("\n");

}

//fibonacci with recursion algorithm
extern long fibonacci(int y){

  //base case
  if (y<=2)
    return 1;

  //do the recursion call
  else
    return fibonacci(y-1)+fibonacci(y-2);
}
