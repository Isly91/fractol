# ifndef FRACTOL_H
#  define FRACTOL_H

# include "MLX42/MLX42.h"
# include "../libft/headers/libft.h"
# include <math.h>
# define WIDTH 2000
# define HEIGHT 2000
# define BPP sizeof(int32_t)

// memdetect . -Iinclude -IMLX42/include -Ilibft/headers -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -LMLX42/build -lmlx42 -e MLX42 -a Mandelbrot -il -fo libobjc AppKit GLEngine Foundation Sky IOKit

typedef struct color_s
{    
    int32_t r;
    int32_t g;
    int32_t b;
    int32_t a;
} color_t;

typedef struct Complex_s
{
    double x;
    double y;
} Complex_t;

//typedef struct {
//    double zx;
//    double zy;
//    double cx;
//    double cy;
//    double zoom;
//} new_coordinates_t;

typedef struct s_imagine
{
    mlx_image_t *image;
    mlx_t       *mlx;
    int         julia_or_mandelbrot;
    int         iter;
    double      moveX;
    double      moveY;
    double      zx;
    double      zy;
    double      cx;
    double      cy;
    double      x;
    double      y;
	double      z_max_x;
    double      z_max_y;
    double      zoom;
} imagine_t;

//typedef struct Complex_s
//{
//    double moveX;
//    double moveY;
//    double zx;
//    double zy;
//    double cx;
//    double cy;
//    double zoom;
//    double x;
//    double y;
//} Complex_t;

typedef struct s_xy
{
	long double		xmin;
	long double		xmax;
	long double		ymin;
	long double		ymax;
	long double		dx;
	long double		dy;
	long double		y0;
	long double		x0;
	long double		x;
	long double		y;
	long double		tempx;
	uint32_t		w;
	uint32_t		h;
}	t_xy;

void change_colors(mlx_image_t *quella_troia);

void mandelbrot(imagine_t *immagine);

void    julia(imagine_t *image);

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

void my_scrollhook(double xdelta, double ydelta, void *param);

double change_imaginary_image_x(imagine_t *immagine, uint32_t x_coordinate);

double change_imaginary_image_y(imagine_t *immagine, uint32_t y_coordinate);

# endif