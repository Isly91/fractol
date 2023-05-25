/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 14:34:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/25 16:20:30 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_julia_set(t_imagine *img, t_complex c, int iter)
{
	t_complex	z;
	uint32_t	color;
	while (img->y < HEIGHT)
	{
		img->x = 0;
		while (img->x < WIDTH)
		{
			img->cx = change_imaginary_image_x(img, img->x);
			img->cy = change_imaginary_image_y(img, img->y);
			iter = 0;
			z.x = img->cx;
			z.y = img->cy;
			while (iter < 10000)
			{
				img->xtemp = z.x * z.x - z.y * z.y + c.x;
				img->ytemp = 2 * z.x * z.y + c.y;
				z.x = img->xtemp;
				z.y = img->ytemp;
				if (z.x * z.x + z.y * z.y > 4.0)
					break ;
				iter++;
			}
			color = 0xFFFFFF / 101 * (iter + 1);
			mlx_put_pixel(img->image, img->y, img->x, color);
			img->x++;
		}
		img->y++;
	}
}

void	julia(t_imagine *img)
{
	int			iter;
	t_complex	c = {-0.7, 0.27015};
	//t_complex	c1 = {-0.8, 0.156};
	//t_complex	c2 = {0.355, 0.355};

	iter = 0;
	img->y = 0;
	draw_julia_set(img, c, iter);
}
