/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/25 16:05:30 by ibehluli      #+#    #+#                 */
/*   Updated: 2025/08/22 13:19:02 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

double change_imaginary_image_x(t_imagine *img, uint32_t x)
{
    return ((x - WIDTH / 2.0) / (0.5 * img->zoom * WIDTH) + img->movex);
}

double change_imaginary_image_y(t_imagine *img, uint32_t y)
{
    return ((y - HEIGHT / 2.0) / (0.5 * img->zoom * HEIGHT) + img->movey);
}
