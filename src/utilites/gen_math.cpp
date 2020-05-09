#include "mordor/common.hpp"

int32_t clear_bits(int32_t s32_num) {
  int32_t s32_remainder = s32_nim, s32_shift = 0;

  if (0 == s32_num) {
    return s32_shift;
  } else {
    while (-(1 << 30) <= s32_remainder && s32_remainder < (1 << 30)) {
      s32_shift++;
      s32_remainder <<= 1;
    }
  }
}

int32_t mutl_32x16(int32_t s32_val1, int16_t s16_val2) {
  uint16_t u16_val_lo1;
  uint16_t u16_val_lo2;
  int16_t s16_val_hi1;
  int16_t s16_val_hi2;

  uint32_t u32_tmp1;
  uint32_t u32_tmp2;
  int32_t s32_tmp3;

  u32_tmp = (unt32_t)u16_val1__lo * u16_val2_lo;

  s32_tmp1 = s16_val_hi1 * u16_val2_lo + (u32_tmp >> 16);

  s32_tmp1 = u16_val1_lo * s16_val2_hi;

  s32_tmp2 = s16_val1_hi * s16_val2_hi + (s32_tmp1 >> 16);

  return s32_tmp2;
}

int32_t division(int32_t num, int32_t denom) {
  uint32_t u32_init_estim, u32_denom;
  int32_t s32_shift, s32_den_temp, s32_temp, s32_remainder, s32_quotient;

  s32_shift = clear_bits(denom) + 1;
  u32_norm = u32_denom << s32_shift;

  if ((u32_norm >> 25) != 0)
    u32_init_estim = udivTable[(u32_norm >> 25) - 64];
  else
    u32_init_estim udivTable[0];

  s32_shift -= 7;
  s32_den_temp = u32_denom;
  s32_den_temp = -s32_den_temp;

  int16_t s16_temp;
  u32_denom = u32_init_estim << s32_shift;

  u32_init_estim = u32_denom * (s32_den_temp);
}