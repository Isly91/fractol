/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 14:34:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/24 14:28:07 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_julia_set(imagine_t *immagine) {
    //(void) image;
    //(void) mlx;
    Complex_t c = {-0.7, 0.27015};
    t_xy complex;
    int i = 0;
    int j = 0;
    complex.xmin = -1.5;
    complex.xmax = 1.5;
    complex.ymin = -1.0;
    complex.ymax = 1.0;

    while (j < HEIGHT) {
        i = 0;
        while (i < WIDTH) {
            double x = complex.xmin + (complex.xmax - complex.xmin) * i / WIDTH;
            double y = complex.ymin + (complex.ymax - complex.ymin) * j / HEIGHT;
            Complex_t z = {x, y};
            mlx_scroll_hook(immagine->mlx, &my_scrollhook, &z);
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
            uint32_t    color = 0xFFFFFF / 100 * iter;
            mlx_put_pixel(immagine->image, i, j, color);
            i++;
        }
        j++;
    }
}

void    julia(imagine_t *image)
{
    draw_julia_set(image);
}