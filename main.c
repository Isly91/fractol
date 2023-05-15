/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 11:54:14 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/15 20:29:16 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    julia_or_mandelbrot(char *which_fractal)
{
	if (ft_strncmp("julia", which_fractal, 6) > 0)
		ft_printf("Julia\n");
	else if(ft_strncmp("Julia", which_fractal, 6) > 0)
		ft_printf("Julia\n");
	else if(ft_strncmp("mandelbrot", which_fractal, 11) > 0)
		ft_printf("Mandelbrot\n");
	else if (ft_strncmp("mandelbrot", which_fractal, 11) > 0)
		ft_printf("Mandelbrot\n");
	else
	{
		ft_printf("please type Mandelbrot or Julia\n");
		exit(EXIT_FAILURE);
	}
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void ft_add_colors(mlx_image_t *quella_troia, int32_t r, int32_t g, int32_t b, int32_t a)
{
	uint32_t i;
	uint32_t y;
	i = 0;
	while (i < quella_troia->width)
	{
		y = 0;
		while (y < quella_troia->height)
		{
			uint32_t color = ft_pixel(r % 0xFF, g % 0xFF, b % 0xFF, a);
			mlx_put_pixel(quella_troia, i, y, color);
			y++;
		}
		i++;
	}
}

void change_colors(mlx_image_t *quella_troia)
{
	color_t *colors;
	colors = malloc(sizeof(color_t));
	if (!colors)
		exit(EXIT_FAILURE);
	colors->r = 76;
	colors->g = 0;
	colors->b = 19;
	colors->a = 255;
	ft_add_colors(quella_troia, colors->r, colors->g, colors->b, colors->a);
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	mlx_image_t *quella_troia;
	long double zoom;
	zoom = 1;
	quella_troia = param;
	if (!param)
		exit(EXIT_FAILURE);
	if (ydelta > 0 && quella_troia->height < HEIGHT && quella_troia->width < WIDTH)
	{
		// quella_troia->instances->x *= 2;
		// quella_troia->instances->y *= 2;
		zoom *= 0.9;
		quella_troia->instances->x += quella_troia->width * 0.005 *zoom;
		quella_troia->instances->y += quella_troia->height * 0.005 * zoom;
	}
	else if (ydelta < 0 && quella_troia->height > 0 && quella_troia->width > 0)
	{
		// quella_troia->instances->x /= 1.05;
		// quella_troia->instances->y /= 1.05;
		zoom *= 1.1;
		quella_troia->instances->x -= quella_troia->width * 0.005 *zoom;
		quella_troia->instances->y -= quella_troia->height * 0.005 * zoom;
		// printf("minore di 0=%i\t", quella_troia->instances->x);
		// printf("minore di 0=%i\t", quella_troia->instances->y);
		//printf("ydelta = %f\t", ydelta);
		//printf("altezza =%i\t", quella_troia->height);
		//printf("larghezza=%i\n", quella_troia->width);
	}
	xdelta++;
}

int32_t	main(int argc, char **argv)
{
	mlx_t *mlx;
	mlx_image_t *quella_troia;
	mlx_instance_t  *quella_troia_pos;

	if (argc == 2)
	{
		julia_or_mandelbrot(argv[1]);
		mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
		quella_troia = mlx_new_image(mlx, WIDTH, HEIGHT);
		quella_troia_pos = malloc(sizeof(mlx_instance_t));
		quella_troia->instances = quella_troia_pos;
		quella_troia->width = 500;
		quella_troia->height = 500;
		quella_troia_pos->x = (WIDTH / 2) - (quella_troia->width / 2);
		quella_troia_pos->y = (HEIGHT / 2) - (quella_troia->height / 2);
		if (!mlx)
			exit(EXIT_FAILURE);
		mlx_image_t* img = mlx_new_image(mlx, WIDTH, HEIGHT);
		ft_memset(img->pixels, 255, img->width * img->height * BPP);
		ft_memset(quella_troia->pixels, 255, quella_troia->width * quella_troia->height * BPP);
		mlx_image_to_window(mlx, img, 0, 0);
		change_colors(quella_troia);
		mlx_scroll_hook(mlx, &my_scrollhook, quella_troia);
		mlx_image_to_window(mlx, quella_troia, quella_troia_pos->x, quella_troia_pos->y);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}