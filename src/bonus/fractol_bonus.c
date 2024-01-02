/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:07:08 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/02 01:52:49 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	burning(t_var *var)
{
	data_init(var);
	var->id = 3;
	burning_ship(var);
}

int	main(int ac, char **av)
{
	t_var	var;

	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		data_init(&var);
		var.id = 1;
		mandelbrot_bonus(&var);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		data_init(&var);
		var.real = ft_atof(av[2]);
		var.imaginary = ft_atof(av[3]);
		var.id = 2;
		julia_bonus(&var);
	}
	else if (ac == 2 && ft_strncmp(av[1], "burningship", 11) == 0)
		burning(&var);
	else
		print_error();
}
