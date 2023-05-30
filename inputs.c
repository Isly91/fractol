/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inputs.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibehluli <ibehluli@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/30 17:59:46 by ibehluli      #+#    #+#                 */
/*   Updated: 2023/05/30 18:23:13 by ibehluli      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_set(t_imagine *img, char **argv)
{
	if (argv[2][0] == '1')
	{
		img->input_julia.x = -0.7;
		img->input_julia.y = 0.27015;
	}
	else if (argv[2][0] == '2')
	{
		img->input_julia.x = 0.355;
		img->input_julia.y = 0.355;
	}
	else if (argv[2][0] == '3')
	{
		img->input_julia.x = 0.285;
		img->input_julia.y = 0.01;
	}
	else
	{
		ft_printf("\nThird parameter is not accepted\n\n");
		ft_printf("\tPlease type or './fractol Julia <1> or <2> or <3>'\n\n");
		exit(EXIT_FAILURE);
	}	
}

void	color_mandelbrot_choice(t_imagine *img, char **argv)
{
	if (ft_strncmp("GREEN", argv[2], 5) == 0)
	{
		img->color_set.new_r = 1;
		img->color_set.new_g = 100;
		img->color_set.new_b = 1;
	}
	else if (ft_strncmp("PURPLE", argv[2], 5) == 0)
	{
		img->color_set.new_r = 100;
		img->color_set.new_g = 1;
		img->color_set.new_b = 100;
	}
	else if (ft_strncmp("RED", argv[2], 3) == 0)
	{
		img->color_set.new_r = 100;
		img->color_set.new_g = 1;
		img->color_set.new_b = 1;
	}
	else
	{
		ft_printf("\nThird parameter is not accepted\n\n");
		ft_printf("\tPlease type './fractol Mandelbrot <color>'\n");
		ft_printf("\tchange <color> with PURPLE, RED or GREEN'\n");
		exit(EXIT_FAILURE);
	}	
}
