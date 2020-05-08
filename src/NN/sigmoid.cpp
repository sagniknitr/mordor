
#define SGN(x) ((x < 0) ? 127 : 0)
#define ABS(x) ((x < 0) ? (-x) : x)



#define LUTMAX 8  
#define LUTPRECISION 8  
#define LUTLEN (LUTMAX * LUTPRECISION + 1)  

int mordor_sigmoid(int8_t in[],
                   uint8_t out[],
                   int w,
                   int in_fl_)

{
  int idx, x;

  uint8_t abs_in;

  uint8_t sgn_in;

  int8_t y;

  uint8_t* lut8b = lut8b3;

  for (int i = 0; i < w; i++) {
    abs_in = ABS(in[i]);

    sgn_in = SGN(in[i]);

    x = abs_in;

    if (in_fl_ > 3)
      x = (x >> (in_fl_ - 3));
    else if (in_fl_ < 3)
      x = (x << (3 - in_fl_));
    if (x >= (LUTLEN - 1))
      y = 127 - sgn_in;
    else {
      y = lut8b[x] - sgn_in;
    }

    out[i] = (ABS(y));
  }

  return 0;
}