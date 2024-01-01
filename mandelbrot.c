/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:20:25 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/01 20:47:59 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	draw_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->img_data + offset) = color;
}

static void	draw_mandelbrot(t_var *var)
{
	var->z.tmp = 0;
	var->j = 0;
	while (var->j < var->iteration && module(var) <= 4)
	{
		var->z.tmp = var->z.r * var->z.r - var->z.i * var->z.i + var->c.r;
		var->z.i = 2 * var->z.r * var->z.i + var->c.i;
		var->z.r = var->z.tmp;
		var->j++;
	}
	if (var->j == var->iteration)
		draw_pixel(var->x, var->y, &var->data.img, 0xFFFFFF);
	else
	{
		var->color = interpolation(var->j, 0x000000, 0xFFFFFF, var->tmp);
		draw_pixel(var->x, var->y, &var->data.img, var->color);
	}
}

void	render_mandelbrot(t_var *var)
{
	var->x = 0;
	while (var->x < WIDTH)
	{
		var->y = 0;
		while (var->y < HEIGHT)
		{
			var->z.r = 0;
			var->z.i = 0;
			var->c.r = (interpolation(var->x, -2, 2, 800) * var->zoom)
				+ var->shift_x;
			var->c.i = (interpolation(var->y, -2, 2, 800) * var->zoom)
				+ var->shift_y;
			draw_mandelbrot(var);
			var->y++;
		}
		var->x++;
	}
	mlx_put_image_to_window(var->data.mlx_ptr, var->data.mlx_window,
		var->data.img.mlx_img, 0, 0);
}

void	mandelbrot(t_var *var)
{
	ini_mlx(&var->data);
	render_mandelbrot(var);
	init_hooks(&var->data);
	mlx_loop(var->data.mlx_ptr);
}
