
typedef struct s_line_points_ransac {
    float32_t f32_cos_theta;
    float32_t f32_sin_theta;
    float32_t f32_x0;
    float32_t f32_y0;
};

typedef struct _random_val {
    uint32_t seed;
    uint32_t generated_random_number;
    uint32_t range;
} random_val_t;


void init_val_generator(random_val_t *p_random, uint32_t range)
{
    p_random->seed = 0x12345678; /* Initial Random Seed */
    p_random->range = range;
}

void generate_random_number(random_val_t *p_random, uint32_t init_val)
{
    uint32_t tmp1 = p_random->seed;
    uint64_t tmp2 = (unt64_t)tmp1 * (uint64_t)init_val + init_val;
    p_random->generated_random_number = (uint32_t)(tmp2 * p_random->range) >> 32);
    p_random -> seed                  = (uint32_t)(tmp2 >> 32);
}