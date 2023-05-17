/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 14:34:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/17 15:44:36 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct {
    double x;
    double y;
} Complex;

extern float g_shift;

void draw_julia_set(mlx_image_t *image) {
    Complex c = {-0.7, 0.27015};
    double xmin = -1.5;
    double xmax = 1.5;
    double ymin = -1.0;
    double ymax = 1.0;

    int i = 0;
    int j = 0;

    while (j < HEIGHT) {
        i = 0;
        while (i < WIDTH) {
            double x = xmin + (xmax - xmin) * i / WIDTH;
            double y = ymin + (ymax - ymin) * j / HEIGHT;

            Complex z = {x, y};
            int iter = 0;

            while (iter < 1000) {
                double zx = z.x * z.x - z.y * z.y + c.x;
                double zy = 2 * z.x * z.y + c.y;
                z.x = zx;
                z.y = zy;

                if (z.x * z.x + z.y * z.y > 4.0) {
                    break;
                }

                iter++;
            }

            //int brightness = iter % 256;
            //uint32_t color = ft_pixel(brightness, brightness, 100, 255);
            uint32_t    color = 0xFFFFFF / 10 * iter;
            mlx_put_pixel(image, i, j, color * g_shift);
            i++;
        }
        j++;
    }
}

void    julia(mlx_image_t *image)
{
    draw_julia_set(image);
}