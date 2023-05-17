# ifndef FRACTOL_H
#  define FRACTOL_H

# include "MLX42/MLX42.h"
# include "../libft/headers/libft.h"
# include <math.h>
# define WIDTH 2040
# define HEIGHT 1600
# define BPP sizeof(int32_t)

typedef struct color_s
{    
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
} color_t;

typedef struct fractal_s
{
    double cx;
    double cy;
    double zx;
    double zy;
    double zx_new;
    double zy_new;
    int iter;
} fractal_t;

void change_colors(mlx_image_t *quella_troia);

void mandelbrot(mlx_image_t *image);

void    julia(mlx_image_t *image);

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

# endif