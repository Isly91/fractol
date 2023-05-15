# ifndef FRACTOL_H
#  define FRACTOL_H

# include "MLX42/MLX42.h"
# include "../libft/headers/libft.h"
# include <math.h>
# define WIDTH 1500
# define HEIGHT 1080
# define BPP sizeof(int32_t)

typedef struct color_s {
    
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
} color_t;

# endif