/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 19:54:01 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/24 16:16:34 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(imagine_t *immagine)
{
    int iteration;
    double xtemp;

    immagine->x = 0;
    while (((uint32_t) immagine->x) < immagine->image->width)
    {
        immagine->y = 0;
        while (((uint32_t) immagine->y) < immagine->image->height)
        {
            double zx = 0.0;
            double zy = 0.0;
            double cx = change_imaginary_image_x(immagine, immagine->x);
            double cy = change_imaginary_image_y(immagine, immagine->y);
            iteration = 0;
            while (zx * zx + zy * zy < 4 && iteration < 100)
            {
                xtemp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = xtemp;
                iteration++;
            }
            double brightness = log2(1.75 + iteration - log2(sqrt(zx * zx + zy * zy))) / log2(100);
            int r = (int)(brightness * 100/ iteration * 20);
            int g = (int)(brightness );
            int b = (int)(brightness * 10 / iteration * 25);
            int a = 255;
            uint32_t color = ft_pixel(r, g, b, a);
            mlx_put_pixel(immagine->image, immagine->x, immagine->y, color);
            immagine->y++;
        }
        immagine->x++;
    }
}

