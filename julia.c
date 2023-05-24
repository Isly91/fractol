/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/17 14:34:21 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/24 15:33:09 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void draw_julia_set(imagine_t *immagine) 
{
    double zx;
    double zy;
    Complex_t z;
    int iter;
    Complex_t c;
    //Complex_t c = {-0.7, 0.27015};
    //Complex_t c = {-0.8, 0.156};
    c = (Complex_t){0.355, 0.355};
    //c.x = -0.7;
    //c.y = 0.27015;

    immagine->image->instances->x = 0;
    while (immagine->image->instances->x < HEIGHT) 
    {
        immagine->image->instances->y = 0;
        while (immagine->image->instances->y < WIDTH) 
        {
            double x = change_imaginary_image_x(immagine, immagine->image->instances->x);
            double y = change_imaginary_image_y(immagine, immagine->image->instances->y);
            iter = 0;
            z.x = x;
            z.y = y;
            while (iter < 100)
            {
                zx = z.x * z.x - z.y * z.y + c.x;
                zy = 2 * z.x * z.y + c.y;
                z.x = zx;
                z.y = zy;
                if (z.x * z.x + z.y * z.y > 4.0)
                    break;
                iter++;
            }
            uint32_t    color = 0xFFFFFF / 101 * (iter + 1);
            mlx_put_pixel(immagine->image, immagine->image->instances->y, immagine->image->instances->x, color);
            immagine->image->instances->y++;
        }
        immagine->image->instances->x++;
    }
}

void    julia(imagine_t *image)
{
    draw_julia_set(image);
}