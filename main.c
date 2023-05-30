/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 11:54:14 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/30 19:43:44 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_or_mandelbrot(char *which_fractal, t_imagine *img)
{
	if (ft_strncmp("Julia", which_fractal, 6) == 0)
	{
		img->zoom = 1;
		return (1);
	}
	else if (ft_strncmp("Mandelbrot", which_fractal, 10) == 0)
	{
		img->zoom = 2;
		return (0);
	}
	else
	{
		ft_printf("Please type './fractol Mandelbrot' or './fractol Julia'\n");
		exit(EXIT_FAILURE);
		return (0);
	}
}

void	add_parameters(t_imagine *img, char **argv, int argc)
{
	if (argc == 2)
	{
		img->julia_or_mandelbrot = julia_or_mandelbrot(argv[1], img);
		if (img->julia_or_mandelbrot == 1)
		{
			img->input_julia.x = -0.8;
			img->input_julia.y = 0.156;
		}
	}
	else if (argc == 3)
	{
		img->julia_or_mandelbrot = julia_or_mandelbrot(argv[1], img);
		if (img->julia_or_mandelbrot == 1 && ft_strlen(argv[2]) == 1)
			julia_set(img, argv);
		else
			color_mandelbrot_choice(img, argv);
	}
	else
	{
		ft_printf("\nSorry, wrong info to run the program\n\n");
		ft_printf("Please type or './fractol Julia <1> or <2> or <3> or \n");
		ft_printf("Please type './fractol Mandelbrot <color>'\n");
		exit(EXIT_FAILURE);
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_imagine	*img;

	img = param;
	(void)xdelta;
	if (ydelta < 0)
	{
		img->zoom *= 1.1;
	}
	else
	{
		img->zoom *= 1 / 1.1;
	}
	if (img->julia_or_mandelbrot == 0)
		draw_mandelbrot(img);
	else
		julia(img);
	mlx_image_to_window(img->mlx, img->image, 0, 0);
}

void	hook(struct mlx_key_data key_data, void *param)
{
	t_imagine	*img;

	img = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		mlx_close_window(img->mlx);
}

int32_t	main(int argc, char **argv)
{
	mlx_t		*mlx;
	t_imagine	img;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img.image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img.image)
		exit(EXIT_FAILURE);
	img.mlx = mlx;
	add_parameters(&img, argv, argc);
	ft_memset(img.image->pixels, 255, img.image->width
		* img.image->height * sizeof(int32_t));
	if (img.julia_or_mandelbrot == 0)
		draw_mandelbrot(&img);
	else
		julia(&img);
	mlx_scroll_hook(mlx, &my_scrollhook, &img);
	if (mlx_image_to_window(mlx, img.image, 0, 0) < 0)
		exit(EXIT_FAILURE);
	mlx_key_hook(mlx, &hook, &img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
