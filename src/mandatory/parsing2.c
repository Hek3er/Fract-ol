/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:15:04 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/03 12:37:52 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	print_error(void)
{
	ft_putstr_fd("To use type: ./fractol [FRACTAL]\n", 2);
	ft_putstr_fd("Mandelbrot: ./fractal mandelbrot\n", 2);
	ft_putstr_fd("Julia: ./fractol julia [r] [i]\n", 2);
	ft_putstr_fd("\nPress:\n", 2);
	ft_putstr_fd("[+]: To increase iterations\n", 2);
	ft_putstr_fd("[-]: To decrease iterarions\n", 2);
	ft_putstr_fd("[SCROLL_UP]: To zoom in\n", 2);
	ft_putstr_fd("[SCROLL_DOWN]: To zoom out\n", 2);
}
