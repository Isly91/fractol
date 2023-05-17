//#include <stdio.h>
//#include <stdlib.h>

//#define WIDTH 800
//#define HEIGHT 800

//typedef struct s_complex {
//    double real;
//    double imaginary;
//} t_complex;

//int mandelbrot_set(double x, double y, int max_iterations)
//{
//    t_complex z, c, tmp;
//    int iterations = 0;

//    z.real = 0.0;
//    z.imaginary = 0.0;

//    c.real = x;
//    c.imaginary = y;

//    while (z.real * z.real + z.imaginary * z.imaginary <= 4.0 && iterations < max_iterations)
//    {
//        tmp.real = z.real * z.real - z.imaginary * z.imaginary + c.real;
//        tmp.imaginary = 2.0 * z.real * z.imaginary + c.imaginary;

//        z.real = tmp.real;
//        z.imaginary = tmp.imaginary;

//        iterations++;
//    }

//    return iterations;
//}

//void draw_mandelbrot_set(void *mlx_ptr, void *win_ptr, double x_min, double x_max, double y_min, double y_max, int max_iterations)
//{
//    double x_range = x_max - x_min;
//    double y_range = y_max - y_min;
//    int img[WIDTH * HEIGHT];

//    int x, y;
//    double px, py;

//    for (y = 0; y < HEIGHT; y++)
//    {
//        for (x = 0; x < WIDTH; x++)
//        {
//            px = x_min + (x_range * x) / WIDTH;
//            py = y_min + (y_range * y) / HEIGHT;

//            int iterations = mandelbrot_set(px, py, max_iterations);

//            // Set color based on the number of iterations
//            int color = (iterations < max_iterations) ? (iterations % 256) : 0;
//            img[y * WIDTH + x] = (color << 16) | (color << 8) | color;
//        }
//    }

//    mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_new_image(mlx_ptr, WIDTH, HEIGHT), 0, 0);
//    mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_new_image(mlx_ptr, WIDTH, HEIGHT), 0, 0);
//    mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_new_image(mlx_ptr, WIDTH, HEIGHT), 0, 0);
//    mlx_put_image_to_window(mlx_ptr, win_ptr, mlx_new_image(mlx_ptr, WIDTH, HEIGHT), 0, 0);

//    mlx_loop(mlx_ptr);
//}

//int main()
//{
//    void *mlx_ptr;
//    void *win_ptr;

//    mlx_ptr = mlx_init();
//    win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "Mandelbrot Set");

//    draw_mandelbrot_set(mlx_ptr, win_ptr, -2.0, 1.0, -1.5, 1.5, 1000);

//    mlx_loop(mlx_ptr);

//    return 0;
//}