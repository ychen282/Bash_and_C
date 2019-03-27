#include <stdio.h>
#include <stdlib.h>

char* strncpy(char *s,char *t,int n);
char* strncat(char *s,char *t,int n);
int strncmp(char *s,char *t,int n);

//strncpy: copy at most n characters from t to s
char* strncpy(char *s,char *t,int n){
  char r1[n];
  char *a1;
  //counter is to keep track of the index of r1[]
  int counter = 0;
  r1[0]='\"';
  counter++;
  for(int i=1; i<=n+1; i++){
    if(i==n+1)
      r1[i]='\"';
    else
      r1[i] = *(t+i-1);
    counter++;
  }
  //insert '\0' to indicate where the char array ends
  r1[counter] = '\0';
  //let a1 point to the address of the array
  a1 = &r1[0];
  return a1;
}

//strncat: append first n characters of t to s
char* strncat(char *s,char *t,int n){
  char r2[200];
  char *a2;
  r2[0]='\"';
  int counter=1;
  //copy all characters in s to the new array
  for(int i=1; *(s+i-1)!='\0'; i++){
    r2[i] = *(s+i-1);
    counter++;
  }
  //temp represents how many characters has been inserted at present
  //counter keeps increasing
  int temp = counter;
  for(int i=0; i<=n; i++){
    if(i==n)
      r2[temp+n]='\"';
    else
      r2[temp+i] = *(t+i);
    counter++;
  }
  //insert '\0' to indicate where the char array ends
  r2[counter] = '\0';
  //a2 points to the address of the array
  a2 = &r2[0];
  return a2;
}

//strncmp: compare the first two characters that are different in the first n characters in each string
int strncmp(char *s,char *t,int n){
  while(*s && *t && n && (*s==*t)){
    s++;
    t++;
    n--;
  }
  //n decreases to 0 means the first n characters are the same
  if( 0==n ){
    return 0;
  }
  //return the difference
  return (int)(*s-*t);
}

int main(){

  //declare variables
  char str1[200],str2[200];
  char *s,*t;
  int n;

  //assign values to the variables
  printf("Enter the first string:");
  gets(str1);
  s = &str1[0];
  printf("Enter the second string:");
  gets(str2);
  t = &str2[0];
  printf("Enter the number:");
  scanf("%d",&n);

  //call the function to get the output
  printf("strncpy is %s\n",strncpy(s,t,n));
  printf("strncat is %s\n",strncat(s,t,n));

  if(strncmp(s,t,n)>0)
    printf("strncmp is \"%s\">\"%s\" \n",s,t);
  if(0==strncmp(s,t,n))
    printf("strncmp is \"%s\"=\"%s\" \n",s,t);
  if(strncmp(s,t,n)<0)
    printf("strncmp is \"%s\"<\"%s\" \n",s,t);

  return 0;
}

