/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:42:32 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/02 20:14:21 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

int	ft_close(t_var *var)
{
	mlx_destroy_image(var->data.mlx_ptr, var->data.img.mlx_img);
	mlx_destroy_window(var->data.mlx_ptr, var->data.mlx_window);
	exit(0);
}

void	shifting(int keycode, t_var *var)
{
	if (keycode == 126)
		var->shift_y += 1.2 * var->zoom;
	else if (keycode == 125)
		var->shift_y -= 1.2 * var->zoom;
	else if (keycode == 123)
		var->shift_x += 1.2 * var->zoom;
	else if (keycode == 124)
		var->shift_x -= 1.2 * var->zoom;
}

int	key_press(int keycode, t_var *var)
{
	if (keycode == 53)
		ft_close(var);
	else if (keycode == 69)
		var->iteration += 10;
	else if (keycode == 78 && var->iteration > 0)
		var->iteration -= 10;
	else if (keycode == 126 || keycode == 123
		|| keycode == 125 || keycode == 124)
		shifting(keycode, var);
	else if (keycode == 8)
		var->color_shift += 10;
	if (var->id == 1)
		render_mandelbrot_bonus(var);
	else if (var->id == 2)
		render_julia_bonus(var);
	else if (var->id == 3)
		render_burning_ship(var);
	return (0);
}

int	mouse_press(int button, int x, int y, t_var *var)
{
	(void)x;
	(void)y;
	if (button == 5)
		var->zoom *= 0.7;
	else if (button == 4)
		var->zoom *= 1.08;
	if (var->id == 1)
		render_mandelbrot_bonus(var);
	else if (var->id == 2)
		render_julia_bonus(var);
	else if (var->id == 3)
		render_burning_ship(var);
	return (0);
}

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx_window, 2, 0, key_press, data);
	mlx_hook(data->mlx_window, 4, 0, mouse_press, data);
	mlx_hook(data->mlx_window, 17, 0, ft_close, data);
}
