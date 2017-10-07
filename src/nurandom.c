#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "nurandom.h"

const int MAXIMUM_ITERATIONS = 100;

uint32_t random_int(uint32_t upper_bound) {
  int urandom = open("/dev/urandom", O_RDONLY);
  if(urandom < 0) {
    abort();
  }
  uint32_t random;
  uint32_t minimum = -upper_bound % upper_bound;

  int iterations = 0;

  while(1) {
    read(urandom, &random, sizeof random);
    if (random > minimum) {
      break;
    }
    iterations++;
    if(iterations >= MAXIMUM_ITERATIONS) {
      abort();
    }
  }

  return random % upper_bound;
}
