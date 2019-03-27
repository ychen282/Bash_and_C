#include <stdio.h>

int main(){

  //declare and initialize variables
  FILE *readNum = fopen("input.txt","rt");
  int temp,sumNum=0,size=0,index=0,result;
  int arrayNum[100];

  //check if input.txt exists
  if( readNum == NULL ){
    printf("Error opening file\n");
    return 1;
  }
  //while hasing next int, scan and store it into the array
  while(fscanf(readNum, "%d", &temp)==1){
    arrayNum[index]=temp;
    index++;
  }
  //size is to keep track of the index and representing the length of the array
  size = index;

  //caculate and print the sum of the numbers in the input.txt
  for(int i=0; i<size; i++){
    sumNum = sumNum + arrayNum[i];
  }
  printf("The sum of numbers is %d\n",sumNum);

  //start calculating fibonacci
  printf("The Fibonacci Sequence of each number is:\n");
  index = 0;
  //loop until all the numbers in the array have given out a result
  while(index<size){
    int f[arrayNum[index]];
    //base case
    if(arrayNum[index]==1||arrayNum[index]==2)
      result = 1;
    //loop until the i of f(i) reaches the value stored at each index of array
    else{
      f[1] = f[2] = 1;
      for(int i=3; i<=arrayNum[index]; i++){
        f[i] = f[i-1] + f[i-2];
      }
      result = f[arrayNum[index]];
    }
    //output
    printf("Fib(%d) is %d\n",arrayNum[index],result);
    index++;
  }
  fclose(readNum);
  return 0;
