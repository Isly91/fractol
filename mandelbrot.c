/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 19:54:01 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/15 20:40:44 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


//#include <stdio.h>
//#include <math.h>

//int mandelbrot(double x, double y, int max_iter) {
//    double cx = x;
//    double cy = y;
//    double zx = 0.0;
//    double zy = 0.0;
//    double zx_new, zy_new;
//    int iter = 0;
    
//    while (iter < max_iter && zx * zx + zy * zy < 4.0) {
//        zx_new = zx * zx - zy * zy + cx;
//        zy_new = 2.0 * zx * zy + cy;
//        zx = zx_new;
//        zy = zy_new;
//        iter++;
//    }
    
//    if (iter == max_iter) {
//        return 0;
//    } else {
//        return 1;
//    }
//}


//int main() {
//    int width = 80;
//    int height = 40;
//    int max_iter = 100;
//    double x_min = -2.0;
//    double x_max = 2.0;
//    double y_min = -2.0;
//    double y_max = 2.0;
//    double x_step = (x_max - x_min) / width;
//    double y_step = (y_max - y_min) / height;
//    int i, j;
    
//    for (j = 0; j < height; j++) {
//        for (i = 0; i < width; i++) {
//            double x = x_min + i * x_step;
//            double y = y_min + j * y_step;
//            int is_mandelbrot = mandelbrot(x, y, max_iter);
//            if (is_mandelbrot) {
//                printf("*");
//            } else {
//                printf(" ");
//            }
//        }
//        printf("\n");
//    }
    
//    return 0;
//}

