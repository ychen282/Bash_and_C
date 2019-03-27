#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include "lib.h"

int main(int argc, char *argv[]){

  pid_t child_a, child_b;
  child_a = fork();

 //child process 1 - sort
  if(child_a<0){
    printf("Fork error\n");
    return -1;
  }
  else if(child_a == 0){
    printf("Random Numbers Generated:\n");
    //generate x random numbers from 1 to 99
    int x = atoi(argv[1]);
    int array[x];
    for(int i=0; i<x; i++){
      array[i]=rand()%100;
      printf("%d ",array[i]);
    }
    printf("\n");

    printf("Bubble Sort Process Started\n");
    sort(array, x);
    printf("Bubble Sort Process Exits\n");
    exit(0);
  }
  else{
    child_b = fork();

    //child process 2 - fibonacci recursion
    if(child_b<0){
      printf("Fork error\n");
      return -1;
    }
    else if(child_b == 0){
      printf("Fibonacci Process Started\n");
      printf("Input Number:%d\n",atoi(argv[2]));
      printf("Fibonacci Number f(%d) is %ld \n",atoi(argv[2]),fibonacci(atoi(argv[2])));
      printf("Fibonacci Process Exits.");
      exit(0);
    }

    //parent process
    else{
      printf("Main Process Started\n");
      printf("Number of Random Numbers =%d\n",atoi(argv[1]));
      printf("Fibonacci Input =%d\n",atoi(argv[2]));
      printf("Bubble Sort Process Created\n");
      printf("Fibonacci Process Created\n");
      printf("Main Process Waits\n");
      wait(NULL);
      printf("Main Process Exits\n");
      exit(0);
    }
  }

  return 0;
}
