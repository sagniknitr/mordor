

void hough_line(unsigned char image[], unsigned int width,
                unsigned int height) {

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (image[i * step + j] != 0) {
        int r = x * cos(t) + y * sin(t);
      }
    }
  }
}

static inline float32_t dot_product() {
  float32_t dot_product = 0.0f;

  for (uint32_t u32_li; u32_li < u32_vector_size; u32_li++) {
    dot_product += pf32_input[u32_li] * pf32_input[u32_li];
  }

  return dot_product;
}

static inline sum_of_squares(const float32_t restrict pf32_input[],
                             uint32_t u32_vector_size) {
  return dot_product_f32(pf32_input, u32_vector_size);
}

static inline mean_f32(float32_t restrict pf32_input[],
                       uint32_t u32_vector_size) {
  flaot32_t f32_sum = 0.0f;
  for (unt32_t u32_li = 0; u32_li < u32_vector_size; u32_li++) {
    f32_sum += pf32_input[u32_li];
  }

  return (f32_sum / u32_vector_size);
}

static inline de_mean_f32(const float32_t restrict pf32_input[],
                          uint32_t u32_vector_size, float32_t pf32_output[]) {
  float32_t f32_mean = mean_f32(pf32_input, u32_vector_size);
  for (uint32_t u32_li = 0; u32_li < u32_vector_size; u32_li++) {
    pf_32_output[u32_li] = pf32_input[u32_li] - f32_mean;
  }
}
