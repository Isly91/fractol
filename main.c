/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 11:54:14 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/25 16:42:03 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_or_mandelbrot(char *which_fractal, t_imagine	*img)
{
	if (ft_strncmp("Julia", which_fractal, 6) == 0)
	{
		img->zoom = 5;
		img->z_max_x = img->zoom / 2;
		img->z_max_y = img->z_max_x * 2.5 / 4;
		return (1);
	}
	else if (ft_strncmp("Mandelbrot", which_fractal, 10) == 0)
	{
		img->zoom = 10;
		img->z_max_x = 2;
		img->z_max_y = 2;
		return (0);
	}
	else
	{
		ft_printf("please type Mandelbrot or Julia\n");
		exit(EXIT_FAILURE);
		return (0);
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_imagine	*img;

	img = param;
	(void)xdelta;
	if (ydelta < 0)
		img->zoom *= 1.1;
	else
		img->zoom *= 0.9;
	if (img->julia_or_mandelbrot == 0)
		draw_mandelbrot(img);
	else
		julia(img);
	mlx_image_to_window(img->mlx, img->image, 0, 0);
}

void	hook(struct mlx_key_data key_data, void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		mlx_close_window(mlx);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_imagine	img;

	if (argc == 2)
	{
		mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
		if (!mlx)
			exit(EXIT_FAILURE);
		img.image = mlx_new_image(mlx, WIDTH, HEIGHT);
		img.julia_or_mandelbrot = julia_or_mandelbrot(argv[1], &img);
		img.image->width = mlx->width;
		img.image->height = mlx->height;
		img.mlx = mlx;
		ft_memset(img.image->pixels, 255, img.image->width
			* img.image->height * sizeof(int32_t));
		if (img.julia_or_mandelbrot == 0)
			draw_mandelbrot(&img);
		else
			julia(&img);
		mlx_scroll_hook(mlx, &my_scrollhook, &img);
		mlx_image_to_window(mlx, img.image, 0, 0);
		mlx_key_hook(mlx, &hook, mlx);
		mlx_loop(mlx);
		mlx_terminate(mlx);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
