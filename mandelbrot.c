/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:20:25 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/31 13:40:29 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	draw_pixel(int x, int y, t_img *img, int color)
{
	int	offset;
	
	offset = (y * img->len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_data + offset) = color;
}

static void	draw_mandelbrot(t_data *data, t_var *var)
{
	var->z.tmp = 0;
	var->j = 0;
	while (var->j < Iteration && module(var) <= 4)
	{
		var->z.tmp = var->z.r * var->z.r - var->z.i * var->z.i + var->c.r;
		var->z.i = 2 * var->z.r * var->z.i + var->c.i;
		var->z.r = var->z.tmp;
		var->j++;
	}
	if (var->j == Iteration)
		draw_pixel(var->x, var->y, &data->img, 0xFFFFFF);
	else
	{
		var->color = interpolation(var->j, 0x000000, 0xFFFFFF, Iteration + var->color_shift);
		draw_pixel(var->x, var->y, &data->img, var->color);
	}
}

void	mandelbrot(void)
{
	t_data	data;
	t_var	var;

	var.x = 0;
	ini_mlx(&data);
	while (var.x < Width)
	{
		var.y = 0;
		while (var.y < Height)
		{
			var.z.r = 0;
			var.z.i = 0;
			var.c.r = interpolation(var.x, -2, 2, 800);
			var.c.i = interpolation(var.y, -2, 2, 800);
			draw_mandelbrot(&data, &var);
			var.y++;
		}
		var.x++;
	}
	mlx_put_image_to_window(data.mlx_ptr, data.mlx_window, data.img.mlx_img, 0, 0);
	mlx_loop(data.mlx_ptr);
}
