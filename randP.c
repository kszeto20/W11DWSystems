#include "randP.h"
#include <fcntl.h>
#include <errno.h>

int * randomGen(int size) {
  // read it
  int file = open("/dev/random", O_RDONLY);
  if (file < 0) { // error check
    printf("There is an error: %s\n", strerror(errno));
  }
  else {
    //make data point to calloc memory
    int *data = calloc(size, sizeof(int));
    // read data into memory at data
    read(file, data, sizeof(int) *10);
    return data;
  }
}
