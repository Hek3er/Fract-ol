/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:07:08 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/01 16:42:30 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

void f()
{
	system("leaks a.out");
}

int main(int ac, char **av)
{
	//if (ac == 1)
	//	exit(1);
	//if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) != 0)
	//{
		atexit(f);
		t_data data;
		t_var	var;
		//ini_mlx(&data);
		data_init(&var, &data);
		mandelbrot(&var);
	//}
}