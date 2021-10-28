#include "randP.h"

int main() {
  int *data = randomGen(10);
  int i;
  printf("Original Array Gen: \n");
  for (i = 0; i < 10; i++){
      printf("%d: %d\n", i, data[i]);
  }
  printf("\n");

  int file = open("f1.txt", O_CREAT | O_WRONLY, 0777);
  if (file < 0) { // error check
    printf("There is an error: %s\n", strerror(errno));
  }
  else {
    // put in data
    write(file, data, 10 * sizeof(int));
    int *copy = malloc(10 * sizeof(int));

    file = open("f1.txt", O_RDONLY, 0777);
    if (file < 0) { // error check
      printf("There is an error: %s\n", strerror(errno));
    }
    else {
      // move into copy
      read(file, copy, 10 * sizeof(int));
      printf("Copy of Array: \n");
      for (i = 0; i < 10; i ++){
        printf("%d: %d\n", i, copy[i]);
      }
    }
  }
  return 0;
}
