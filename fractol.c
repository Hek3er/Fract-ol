/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:07:08 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/01 20:36:33 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void f()
{
	system("leaks a.out");
}

int main(int ac, char **av)
{
	t_var	var;
	
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
	{
		data_init(&var);
		var.id = 1;
		mandelbrot(&var);
	}
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
	{
		data_init(&var);
		var.real = ft_atof(av[2]);
		var.imaginary = ft_atof(av[3]);
		var.id = 2;
		julia(&var);
	}
	else
	{
		print_error();
	}
}
