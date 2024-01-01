/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:42:32 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/01 16:54:18 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int	ft_close(t_var *var)
{
	mlx_destroy_image(var->data.mlx_ptr, var->data.img.mlx_img);
	mlx_destroy_window(var->data.mlx_ptr, var->data.mlx_window);
	exit(0);
}

void	shifting(int keycode, t_var *var)
{
	if (keycode == 126)
	{
		var->shift_y += 1.2;
		render_image(var);
	}
	else if (keycode == 125)
	{
		var->shift_y -= 1.2;
		render_image(var);
	}
	else if (keycode == 123)
	{
		var->shift_x += 1.2;
		render_image(var);
	}
	else if (keycode == 124)
	{
		var->shift_x -= 1.2;
		render_image(var);
	}
}

int	key_press(int keycode, t_var *var)
{
	if (keycode == 53)
		ft_close(var);
	else if (keycode == 69)
	{
		var->iteration += 10;
		render_image(var);
	}
	else if (keycode == 78 )
	{
		var->iteration -= 10;
		render_image(var);
	}
	else if (keycode == 126 || keycode == 123 || keycode == 125 || keycode == 124)
		shifting(keycode, var);
	printf("Keypressed: %d\n", keycode);  // need to remove it
	return (0);
}

// int	mouse_press(int button, int x, int y, void *param)
// {
	
// }


void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx_window, 2, 0, key_press, data);
	// mlx_hook(data->mlx_window, 4, 0, mouse_press, data);
	mlx_hook(data->mlx_window, 17, 0, ft_close, data);
	
}