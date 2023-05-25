/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 14:34:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/25 18:01:02 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_color_julia(t_imagine *img, int iter)
{
	img->color = 0xFFFFFF * sin(iter * 0.01);
}

void	draw_julia_set(t_imagine *img, t_complex c, int iter)
{
	while (img->y < HEIGHT)
	{
		img->x = 0;
		while (img->x < WIDTH)
		{
			img->cx = change_imaginary_image_x(img, img->x);
			img->cy = change_imaginary_image_y(img, img->y);
			iter = 0;
			img->z.x = img->cx;
			img->z.y = img->cy;
			while (iter < 10000)
			{
				img->xtemp = img->z.x * img->z.x - img->z.y * img->z.y + c.x;
				img->ytemp = 2 * img->z.x * img->z.y + c.y;
				img->z.x = img->xtemp;
				img->z.y = img->ytemp;
				if (img->z.x * img->z.x + img->z.y * img->z.y > 4.0)
					break ;
				iter++;
			}
			draw_color_julia(img, iter);
			mlx_put_pixel(img->image, img->x, img->y, img->color);
			img->x++;
		}
		img->y++;
	}
}

void	julia(t_imagine *img)
{
	int			iter;
	//t_complex	c = {-0.7, 0.27015};
	t_complex	c = {-0.8, 0.156};
	//t_complex	c = {0.355, 0.355};

	iter = 0;
	img->y = 0;
	draw_julia_set(img, c, iter);
}
