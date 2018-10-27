#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int rand_gen(){
  char * file = "/dev/random";
  int file_id = open(file, O_RDONLY);
  int num;
  read(file_id, &num, sizeof(int));
  
  if (errno) {
        printf("Errno number: %d\n", errno);
        printf("Message: %s\n", strerror(errno));
  }

  close(file_id);
  return num;
}


int main(){
  int rand[10];

  printf("Generating random numbers:\n");
  //int * k = rand;
  rand[0] = rand_gen();
  printf("\trandom 0: %d\n", rand[0]);
  rand[1] = rand_gen();
  printf("\trandom 1: %d\n", rand[1]);
  rand[2] = rand_gen();
  printf("\trandom 2: %d\n", rand[2]);
  rand[3] = rand_gen();
  printf("\trandom 3: %d\n", rand[3]);
  rand[4] = rand_gen();
  printf("\trandom 4: %d\n", rand[4]);
  rand[5] = rand_gen();
  printf("\trandom 5: %d\n", rand[5]);
  rand[6] = rand_gen();
  printf("\trandom 6: %d\n", rand[6]);
  rand[7] = rand_gen();
  printf("\trandom 7: %d\n", rand[7]);
  rand[8] = rand_gen();
  printf("\trandom 8: %d\n", rand[8]);
  rand[9] = rand_gen();
  printf("\trandom 9: %d\n", rand[9]);
  
  printf("\nWriting numbers to file...\n");

  char * file_2 = "random_num.txt";
  int file_id_c = open(file_2, O_RDWR|O_CREAT, 0666);
  write(file_id_c, rand, sizeof(rand));
  close(file_id_c);

  if (errno) {
        printf("Errno number: %d\n", errno);
        printf("Message: %s\n", strerror(errno));
  }
    
  printf("\nReading numbers from file...\n");
  int new_nums[10];
  int file_id_d = open(file_2, O_RDONLY);
  read(file_id_d, &new_nums, sizeof(new_nums));
  close(file_id_d);
  
  if (errno) {
        printf("Errno number: %d\n", errno);
        printf("Message: %s\n", strerror(errno));
  }
  
  printf("\nVerification that written values were the same:\n");
  for(int i = 0; i < 10; i++){
    printf("random %d: %d\n", i, new_nums[i]);
  }

  return 0;

}
