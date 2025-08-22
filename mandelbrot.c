/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 19:54:01 by ibehluli      #+#    #+#                 */
/*   Updated: 2025/08/22 13:56:30 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void give_color_mandelbrot(t_imagine *img, int iter)
{
    t_color color;

    color.brightness = log2(1.75 + iter - log2(log2(sqrt(img->zx * img->zx + img->zy * img->zy))));
    if (!img->color_set.new_r || !img->color_set.new_g || !img->color_set.new_b)
    {
        color.r = (int)(color.brightness * 100 / iter * 20);
        color.g = (int)(color.brightness);
        color.b = (int)(color.brightness * 10 / iter * 25);
    }
    else
    {
        color.r = (int)(color.brightness * img->color_set.new_r / iter * 25);
        color.g = (int)(color.brightness * img->color_set.new_g / iter * 25);
        color.b = (int)(color.brightness * img->color_set.new_b / iter * 25);
    }
    color.a = 255;
    img->color = ft_pixel(color.r, color.g, color.b, color.a);
}

void mandelbrot_pixel(t_imagine *img, int x, int y)
{
    double zx = 0.0;
    double zy = 0.0;
    double cx = change_imaginary_image_x(img, x);
    double cy = change_imaginary_image_y(img, y);
    double xtemp;
    int iter = 0;

    while (zx * zx + zy * zy < 4 && iter < MAX_ITER)
    {
        xtemp = zx * zx - zy * zy + cx;
        zy = 2 * zx * zy + cy;
        zx = xtemp;
        iter++;
    }
    img->zx = zx;
    img->zy = zy;
    give_color_mandelbrot(img, iter);
    mlx_put_pixel(img->image, x, y, img->color);
}

void *mandelbrot_worker(void *arg)
{
    t_thread *data = (t_thread *)arg;

    for (int y = data->start_y; y < data->end_y; y++)
    {
        for (int x = 0; x < WIDTH; x++)
            mandelbrot_pixel(data->img, x, y);
    }
    return NULL;
}

void draw_mandelbrot_threaded(t_imagine *img)
{
    pthread_t threads[THREADS];
    t_thread args[THREADS];
    int slice = HEIGHT / THREADS;

    for (int i = 0; i < THREADS; i++)
    {
        args[i].img = img;
        args[i].start_y = i * slice;
        args[i].end_y = (i + 1) * slice;
        pthread_create(&threads[i], NULL, mandelbrot_worker, &args[i]);
    }
    for (int i = 0; i < THREADS; i++)
        pthread_join(threads[i], NULL);
}
