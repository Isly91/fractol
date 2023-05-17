/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 19:54:01 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/17 16:12:56 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(mlx_image_t *image)
{
    uint32_t x = 0;
    uint32_t  y;
    double zoom = 0.8;
    double moveX = -2.0;
    double moveY = -1.0;
    int maxIterations = 100;
    
    while (x < image->width)
    {
        y = 0;
        while (y < image->height)
        {
            double zx = 0;
            double zy = 0;
            double cx = 1 * (x - image->width/ WIDTH) / (0.5 * zoom * image->width) + moveX;
            double cy = 2.7 * (y - image->height/HEIGHT) / (1.5 * zoom * image->height) + moveY;
            int iteration = 0;

            while (zx * zx + zy * zy < 4 && iteration < maxIterations)
            {
                double xtemp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = xtemp;
                iteration++;
            }
            double brightness = log2(1.75 + iteration - log2(sqrt(zx * zx + zy * zy))) / log2(maxIterations);
            int r = (int)(brightness * 0);
            int g = (int)(brightness * 255);
            int b = (int)(brightness * 0);
            int a = 255;
            uint32_t color = ft_pixel(r, g, b, a);
            mlx_put_pixel(image, x, y, color);
            y++;
        }
        x++;
    }
}
