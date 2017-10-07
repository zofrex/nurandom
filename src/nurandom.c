#include <fcntl.h>
#include <unistd.h>

#include "nurandom.h"

uint32_t random_int(uint32_t upper_bound) {
  int urandom = open("/dev/urandom", O_RDONLY);
  uint32_t random;
  uint32_t minimum = -upper_bound % upper_bound;

  while(1) {
    read(urandom, &random, sizeof random);
    if (random > minimum) {
      break;
    }
  }

  return random % upper_bound;
}
