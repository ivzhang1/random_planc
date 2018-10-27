#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

  char * file = "/dev/random";
  int file_id = open(file, O_RDWR); //READ ONLY

  int * k = malloc(10);
  printf("File Id: %d\n", file_id);
  
  printf("Bytes Read: %zd\n", read(file_id, k, 4));
  printf("String read: %d\n", *k);
  
   

}
