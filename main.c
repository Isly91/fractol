/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 11:54:14 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/17 16:09:55 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int    julia_or_mandelbrot(char *which_fractal)
{
	if (ft_strncmp("Julia", which_fractal, 6) == 0)
		return (1);
	else if(ft_strncmp("Mandelbrot", which_fractal, 10) == 0)
		return (0);
	else
	{
		ft_printf("please type Mandelbrot or Julia\n");
		exit(EXIT_FAILURE);
		return (0);
	}
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void ft_add_colors(mlx_image_t *image, int32_t r, int32_t g, int32_t b, int32_t a)
{
	uint32_t i;
	uint32_t y;
	i = 0;
	while (i < image->width)
	{
		y = 0;
		while (y < image->height)
		{
			uint32_t color = ft_pixel(r % 0xFF, g % 0xFF, b % 0xFF, a);
			mlx_put_pixel(image, i, y, color);
			y++;
		}
		i++;
	}
}

void change_colors(mlx_image_t *image)
{
	color_t *colors;
	colors = malloc(sizeof(color_t));
	if (!colors)
		exit(EXIT_FAILURE);
	colors->r = 76;
	colors->g = 0;
	colors->b = 19;
	colors->a = 255;
	ft_add_colors(image, colors->r, colors->g, colors->b, colors->a);
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	mlx_image_t *image;
	long double zoom;
	zoom = 1;
	image = param;
	if (!param)
		exit(EXIT_FAILURE);
	if (ydelta > 0 && image->height < HEIGHT && image->width < WIDTH)
	{
		zoom *= 0.9;
		image->instances->x += image->width * 0.005 *zoom;
		image->instances->y += image->height * 0.005 * zoom;
	}
	else if (ydelta < 0 && image->height > 0 && image->width > 0)
	{
		zoom *= 1.1;
		image->instances->x -= image->width * 0.005 *zoom;
		image->instances->y -= image->height * 0.005 * zoom;
	}
	xdelta++;
}

float g_shift = 5;

void hook(struct mlx_key_data key_data, void* param)
{
	mlx_t	*mlx;

	mlx = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		mlx_close_window(mlx);
	if (key_data.key == MLX_KEY_1 && key_data.action == MLX_RELEASE)
	{
		//printf("ciao %f\n", g_shift);	
		g_shift+=100;
	}
	if (key_data.key == MLX_KEY_0 && key_data.action == MLX_RELEASE)
		g_shift-=0.1;
}

int32_t main(int argc, char **argv)
{
    mlx_t *mlx;
    mlx_image_t *image;
    mlx_instance_t *image_pos;

    if (argc == 2)
    {
        julia_or_mandelbrot(argv[1]);
        mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
        image = mlx_new_image(mlx, WIDTH, HEIGHT);
        image_pos = malloc(sizeof(mlx_instance_t));
        image->instances = image_pos;
        image->width = WIDTH;
        image->height = HEIGHT;
		image_pos->x = 0;
		image_pos->y = 0;
        if (!mlx)
            exit(EXIT_FAILURE);
        ft_memset(image->pixels, 255, image->width * image->height * BPP);
        if (julia_or_mandelbrot(argv[1]) == 0)
			mandelbrot(image);
		else
			julia(image);
        mlx_scroll_hook(mlx, &my_scrollhook, image);
        mlx_image_to_window(mlx, image, 0, 0);
		mlx_key_hook(mlx, &hook, mlx);
        mlx_loop(mlx);
        mlx_terminate(mlx);
    }
    else
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}
