#include "./datatypes.hpp"

float32_t mordor_sqrt(float32_t f32_input) {
  float32_t x, z, tempf;
  unsigned long *tfptr = ((unsigned long *)&tempf) + 1;
  tempf = f32_input;
  *tfptr = (0xbfcdd90a - *tfptr) >> 1;
  x = tempf;
  z = f32_input * 0.5;
  x = (1.5 * x) -
      (x * x) *
          (x * z); // The more you make replicates of this statement
                   // the higher the accuracy, here only 2 replicates are used
  x = (1.5 * x) - (x * x) * (x * z);
  return x * f32_input;
}