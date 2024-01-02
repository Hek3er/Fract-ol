/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 20:15:04 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/02 02:06:06 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void	print_error(void)
{
	write(1, "Enter a valid fractal name!\n\n", 29);
	write(1, "There is three fractals available:", 34);
	write(1, " mandelbrot, julia and burningship\n\n", 36);
	write(1, "Usage:\n\nMandelbrot: ./fractol_bonus mandelbrot\n", 47);
	write(1, "\nJulia: ./fractol_bonus julia [real] [imaginary]\n", 49);
	write(1, "\nBurningship: ./fractol_bonus burningship\n", 42);
}
