/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:15:04 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/01 20:22:30 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

void	print_error(void)
{
	write(1, "Enter a valid fractal name!\n\n", 29);
	write(1, "There is two fractals available:", 32);
	write(1, " mandelbrot and julia\n\n", 23);
	write(1, "Usage:\n\nMandelbrot: ./fractol mandelbrot\n", 41);
	write(1, "\nJulia: ./fractol julia [real] [imaginary]\n", 43);
}
