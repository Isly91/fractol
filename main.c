/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 11:54:14 by ibehluli      #+#    #+#                 */
/*   Updated: 2025/08/22 13:57:05 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int julia_or_mandelbrot(char *which_fractal, t_imagine *img)
{
	if (ft_strncmp("Julia", which_fractal, 7) == 0)
	{
		img->zoom = 1.0;
		img->movex = 0.0;
		img->movey = 0.0;
		return 1;
	}
	else if (ft_strncmp("Mandelbrot", which_fractal, 11) == 0)
	{
		img->zoom = 1.0;
		img->movex = -0.5;
		img->movey = 0.0;
		return 0;
	}
	else
	{
		ft_printf("Please type './fractol Mandelbrot' or './fractol Julia'\n");
		exit(EXIT_FAILURE);
		return 0;
	}
}

void add_parameters(t_imagine *img, char **argv, int argc)
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
		ft_printf("\nSorry, wrong info to run the program.\n\n");
		ft_printf("Please type './fractol Julia <1> or <2> or <3>'\n");
		ft_printf("Please type './fractol Mandelbrot <color>'\n");
		exit(EXIT_FAILURE);
	}
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_imagine *img = param;
	(void)xdelta;

	double mouse_x = img->mouse_x;
	double mouse_y = img->mouse_y;
	double zoom_factor = (ydelta < 0) ? 1.1 : (1.0 / 1.1);

	img->zoom *= zoom_factor;
	img->movex += ((mouse_x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH)) * (1 - 1.0 / zoom_factor);
	img->movey += ((mouse_y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT)) * (1 - 1.0 / zoom_factor);

	if (img->julia_or_mandelbrot == 0)
		draw_mandelbrot_threaded(img);
	else
		julia(img);

	mlx_image_to_window(img->mlx, img->image, 0, 0);
}

void mouse_move(double xpos, double ypos, void *param)
{
	t_imagine *img = param;
	img->mouse_x = xpos;
	img->mouse_y = ypos;
}

void hook(struct mlx_key_data key_data, void *param)
{
	t_imagine *img = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		mlx_close_window(img->mlx);
}

int32_t main(int argc, char **argv)
{
	mlx_t *mlx;
	t_imagine img;

	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);

	img.image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!img.image)
		exit(EXIT_FAILURE);

	img.mlx = mlx;
	img.mouse_x = WIDTH / 2.0;
	img.mouse_y = HEIGHT / 2.0;

	add_parameters(&img, argv, argc);

	if (img.julia_or_mandelbrot == 0)
		draw_mandelbrot_threaded(&img);
	else
		julia(&img);

	mlx_scroll_hook(mlx, &my_scrollhook, &img);
	mlx_cursor_hook(mlx, &mouse_move, &img);
	mlx_key_hook(mlx, &hook, &img);

	if (mlx_image_to_window(mlx, img.image, 0, 0) < 0)
		exit(EXIT_FAILURE);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
