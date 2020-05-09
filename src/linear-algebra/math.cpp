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

static int vector_sum(int restrict p_data[], int length) {
  int accu = 0;
  int i;
  for (i = 0; i < length; ++i) {
    accu += p_data[i];
  }

  return accu;
}

void integer_normalize(int restrict p_data[], int length) {
  int i;
  int accu;

  accu = sum(p_data, length); // vsum intrinsic is available in IVP

  /* Perform the Normalization */
  for (i = 0; i < length; ++i) {
    p_data[i] /= accu; // use vdiv here
  }
}

void float_normalize(int __restrict p_in_data[], float __restrict p_out_data[],
                     int length) {
  int i;
  int accu;

  accu = sum(p_data, length); // vsum intrinsic is available in IVP

  /* Perform the Normalization */
  for (i = 0; i < length; ++i) {
    p_out_data[i] = (float)p_in_data[i] / (float)accu;
  }
}
