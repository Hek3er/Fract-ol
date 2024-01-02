/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 17:44:24 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/02 19:59:17 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

static void	draw_julia(t_var *var)
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
		var->color = interp(var->j, 0x000000, 0xFFFFFF, var->tmp);
		draw_pixel(var->x, var->y, &var->data.img, var->color);
	}
}

void	render_julia(t_var *var)
{
	var->x = 0;
	while (var->x < W)
	{
		var->y = 0;
		while (var->y < H)
		{
			var->z.r = (interp(var->x, var->r_min, var->r_min, W) * var->zoom);
			var->z.i = (interp(var->y, var->i_min, var->i_max, H) * var->zoom);
			var->c.r = var->real;
			var->c.i = var->imaginary;
			draw_julia(var);
			var->y++;
		}
		var->x++;
	}
	mlx_put_image_to_window(var->data.mlx_ptr, var->data.mlx_window,
		var->data.img.mlx_img, 0, 0);
}

void	julia(t_var *var)
{
	ini_mlx(&var->data);
	render_julia(var);
	init_hooks(&var->data);
	mlx_loop(var->data.mlx_ptr);
}
