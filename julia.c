/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 14:34:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2025/08/22 12:49:16 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_color_julia(t_imagine *img, int iter)
{
	img->color = 0xFFFFFF * sin(iter);
	mlx_put_pixel(img->image, img->x, img->y, img->color);
}

void	draw_julia_set(t_imagine *img, t_complex c, int i)
{
	while (img->y < img->image->height)
	{
		img->x = 0;
		while (img->x < img->image->width)
		{
			img->cx = change_imaginary_image_x(img, img->x);
			img->cy = change_imaginary_image_y(img, img->y);
			i = 0;
			img->z.x = img->cx;
			img->z.y = img->cy;
			while (img->z.x * img->z.x + img->z.y * img->z.y <= 4.0 && i < 300)
			{
				img->xtemp = img->z.x * img->z.x - img->z.y * img->z.y + c.x;
				img->ytemp = 2 * img->z.x * img->z.y + c.y;
				img->z.x = img->xtemp;
				img->z.y = img->ytemp;
				if (img->z.x * img->z.x + img->z.y * img->z.y > 4.0)
					break ;
				i++;
			}
			draw_color_julia(img, i);
			img->x++;
		}
		img->y++;
	}
}

void	julia(t_imagine *img)
{
	int			iter;

	iter = 0;
	img->y = 0;
	img->z_max_x = 2;
	img->z_max_y = 2.5;
	img->image->width = img->image->width;
	img->image->height = img->image->height;
	draw_julia_set(img, img->input_julia, iter);
}
