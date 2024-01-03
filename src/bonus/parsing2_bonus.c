/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:15:04 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/03 11:32:37 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	print_error(void)
{
	ft_putstr_fd("To use type: ./fractol_bonus [FRACTAL]\n", 2);
	ft_putstr_fd("Mandelbrot: ./fractal_bonus mandelbrot\n", 2);
	ft_putstr_fd("Julia: ./fractol_bonus julia [r] [i]\n", 2);
	ft_putstr_fd("Burningship: ./fractal_bonus burningship\n", 2);
	ft_putstr_fd("\nPress:\n", 2);
	ft_putstr_fd("[C]: To change the color\n", 2);
	ft_putstr_fd("[+]: To increase iterations\n", 2);
	ft_putstr_fd("[-]: To decrease iterarions\n", 2);
	ft_putstr_fd("[SCROLL_UP]: To zoom in\n", 2);
	ft_putstr_fd("[SCROLL_DOWN]: To zoom out\n", 2);
	ft_putstr_fd("[← ↕ →]: To move the fractal\n", 2);
}
