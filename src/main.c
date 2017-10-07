#include<stdio.h>
#include<stdint.h>

#include "nurandom.h"

int main() {
  uint32_t x = random_int(10);
  printf("Your random number is: %d\n", x);
}
