/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 19:54:01 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/25 16:20:35 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	give_color_mandelbrot(t_imagine *img, int iter)
{
	t_color	color;

	color.brightness = log2(1.75 + iter - log(log2(sqrt(img->zx * img->zx
						+ img->zy * img->zy)))) / log2(100);
	color.r = (int)(color.brightness * 100 / iter * 20);
	color.g = (int)(color.brightness);
	color.b = (int)(color.brightness * 10 / iter * 25);
	color.a = 255;
	img->color = ft_pixel(color.r, color.g, color.b, color.a);
}

void	mandelbrot(t_imagine *img, int iter)
{
	double	xtemp;

	while ((uint32_t) img->y < img->image->height)
	{
		img->x = 0;
		while ((uint32_t) img->x < img->image->width)
		{
			img->zx = 0.0;
			img->zy = 0.0;
			img->cx = change_imaginary_image_x(img, img->x);
			img->cy = change_imaginary_image_y(img, img->y);
			iter = 0;
			while (img->zx * img->zx + img->zy * img->zy < 4 && iter < 100)
			{
				xtemp = img->zx * img->zx - img->zy * img->zy + img->cx;
				img->zy = 2 * img->zx * img->zy + img->cy;
				img->zx = xtemp;
				iter++;
			}
			give_color_mandelbrot(img, iter);
			mlx_put_pixel(img->image, img->x, img->y, img->color);
			img->x++;
		}
		img->y++;
	}
}

void	draw_mandelbrot(t_imagine *img)
{
	int	iter;

	iter = 0;
	img->y = 0;
	mandelbrot(img, iter);
}
