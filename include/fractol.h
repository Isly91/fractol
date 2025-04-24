/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 10:33:56 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/30 19:44:38 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "MLX42/MLX42.h"
# include "../libft/libft.h"
# include <math.h>
# define WIDTH	2000
# define HEIGHT	2000
# define BPP
# define MAX_ITER 100

typedef struct color_s
{
	int32_t		r;
	int32_t		g;
	int32_t		b;
	int32_t		a;
	int32_t		new_r;
	int32_t		new_g;
	int32_t		new_b;
	double		brightness;
}	t_color;

typedef struct Complex_s
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_imagine
{
	mlx_image_t	*image;
	mlx_t		*mlx;
	int			julia_or_mandelbrot;
	int			iter;
	double		movex;
	double		movey;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		x;
	double		y;
	t_complex	z;
	t_complex	input_julia;
	double		xtemp;
	double		ytemp;
	double		z_max_x;
	double		z_max_y;
	double		zoom;
	uint32_t	color;
	t_color		color_set;
}	t_imagine;

void	change_colors(mlx_image_t *quella_troia);
void	draw_mandelbrot(t_imagine *img);
void	julia(t_imagine *image);
int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	my_scrollhook(double xdelta, double ydelta, void *param);
double	change_imaginary_image_x(t_imagine *immagine, uint32_t x_coordinate);
double	change_imaginary_image_y(t_imagine *immagine, uint32_t y_coordinate);
void	julia_set(t_imagine *img, char **argv);
void	color_mandelbrot_choice(t_imagine *img, char **argv);

#endif