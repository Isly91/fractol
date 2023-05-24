/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/12 11:54:14 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/24 16:12:58 by ibehluli      ########   odam.nl         */
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

    immagine->moveX = immagine->zoom;
    interval = immagine->zoom * (immagine->z_max_x - immagine->zx) / immagine->image->width;
    coordinate = immagine->zx + interval * (double)x_coordinate - immagine->moveX;
    return (coordinate);
}

double change_imaginary_image_y(imagine_t *immagine, uint32_t y_coordinate)
{
    double interval;
    double coordinate;

    immagine->moveY = immagine->moveX * 3 / 4;
    interval = immagine->zoom * (immagine->zy - immagine->z_max_y) / immagine->image->height;
    coordinate = immagine->zy + interval * (double)y_coordinate - immagine->moveY;
    return (coordinate);
}

void my_scrollhook(double xdelta, double ydelta, void *param)
{
    imagine_t *immagine = param;

    (void)xdelta;
    if (ydelta < 0)
        immagine->zoom *= 1.1;
    else
        immagine->zoom *= 0.9;
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
    imagine_t immagine;

    if (argc == 2)
    {
        mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
        immagine.image = mlx_new_image(mlx, WIDTH, HEIGHT);
        immagine.julia_or_mandelbrot = julia_or_mandelbrot(argv[1]);
        immagine.image->width = WIDTH;
        immagine.image->height = HEIGHT;
        immagine.zoom = 10;
        immagine.z_max_y = -2;
        immagine.z_max_x = 2;
        immagine.mlx = mlx;
        if (!mlx)
            exit(EXIT_FAILURE);
        ft_memset(immagine.image->pixels, 255, immagine.image->width * immagine.image->height * BPP);
        if (immagine.julia_or_mandelbrot == 0)
            mandelbrot(&immagine);
        else
            julia(&immagine);
        mlx_scroll_hook(mlx, &my_scrollhook, &immagine);
        mlx_image_to_window(mlx, immagine.image, 0, 0);
        mlx_key_hook(mlx, &hook, mlx);
        mlx_loop(mlx);
        mlx_terminate(mlx);
    }
    else
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}