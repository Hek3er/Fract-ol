/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:32:21 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/01 20:36:06 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	ini_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error(1);
	data->mlx_window = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fract-ol");
	if (!data->mlx_window)
	{
		ft_error(2);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	if (!data->img.mlx_img)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_window);
		ft_error(3);
	}
	data->img.img_data = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp, &data->img.len, &data->img.endian);
}

void	data_init(t_var *var)
{
	var->color_shift = 10;
	var->zoom = 1.0;
	var->shift_x = 0.0;
	var->shift_y = 0.0;
	var->iteration = 42;
	var->tmp = var->iteration;
}