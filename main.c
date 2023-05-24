/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 11:54:14 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/24 14:27:18 by ibehluli      ########   odam.nl         */
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

double change_imaginary_image_x(imagine_t *immagine, uint32_t x_coordinate)
{
    double interval;
    double coordinate;

    immagine->image->instances->moveX = immagine->image->instances->zoom;
    interval = immagine->image->instances->zoom * (immagine->image->instances->z_max_x - immagine->image->instances->zx) / immagine->image->width;
    coordinate = immagine->image->instances->zx + interval * (double)x_coordinate - immagine->image->instances->moveX;
    return (coordinate);
}

double change_imaginary_image_y(imagine_t *immagine, uint32_t y_coordinate)
{
    double interval;
    double coordinate;

    immagine->image->instances->moveY = immagine->image->instances->moveX * 3 / 4;
    interval = immagine->image->instances->zoom * (immagine->image->instances->zy - immagine->image->instances->z_max_y) / immagine->image->height;
    coordinate = immagine->image->instances->zy + interval * (double)y_coordinate - immagine->image->instances->moveY;
    return (coordinate);
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
    imagine_t *immagine = param;

    (void)xdelta;
    if (ydelta < 0)
        immagine->image->instances->zoom *= 1.1;
    else
        immagine->image->instances->zoom *= 0.9;
    if (immagine->julia_or_mandelbrot == 0)
        mandelbrot(immagine);
    else
        julia(immagine);
    mlx_image_to_window(immagine->mlx, immagine->image, 0, 0);
}


void hook(struct mlx_key_data key_data, void* param)
{
	mlx_t	*mlx;

	mlx = param;
	if (key_data.key == MLX_KEY_ESCAPE && key_data.action == MLX_RELEASE)
		mlx_close_window(mlx);
}

int32_t main(int argc, char **argv)
{
    mlx_t *mlx;
    imagine_t *immagine;
    mlx_instance_t *image_pos;

    if (argc == 2)
    {
        mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
        immagine = malloc(sizeof(imagine_t));
        immagine->image = mlx_new_image(mlx, WIDTH, HEIGHT);
        image_pos = malloc(sizeof(mlx_instance_t));
        immagine->julia_or_mandelbrot = julia_or_mandelbrot(argv[1]);
        immagine->image->instances = image_pos;
        immagine->image->width = WIDTH;
        immagine->image->height = HEIGHT;
        immagine->image->instances->zoom = 20;
        immagine->image->instances->z_max_y = -2;
        immagine->image->instances->z_max_x = 2;
        immagine->mlx = mlx;
        if (!mlx)
            exit(EXIT_FAILURE);
        ft_memset(immagine->image->pixels, 255, immagine->image->width * immagine->image->height * BPP);
        if (immagine->julia_or_mandelbrot == 0)
            mandelbrot(immagine);
        else
            julia(immagine);
        mlx_scroll_hook(mlx, &my_scrollhook, immagine);
        mlx_image_to_window(mlx, immagine->image, 0, 0);
        mlx_key_hook(mlx, &hook, mlx);
        mlx_loop(mlx);
        mlx_terminate(mlx);
    }
    else
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}