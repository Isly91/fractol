/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 16:05:30 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/30 18:46:55 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double	change_imaginary_image_x(t_imagine *img, uint32_t x_coordinate)
{
	double	interval;
	double	coordinate;

	interval = img->z_max_x / img->image->width;
	img->movex = img->zoom;
	coordinate = img->zoom * interval * (double)x_coordinate - img->movex;
	return (coordinate);
}

double	change_imaginary_image_y(t_imagine *img, uint32_t y_coordinate)
{
	double	interval;
	double	coordinate;

	interval = img->z_max_y / img->image->height;
	img->movey = img->zoom;
	coordinate = img->zoom * interval * (double)y_coordinate - img->movey;
	return (coordinate);
}
