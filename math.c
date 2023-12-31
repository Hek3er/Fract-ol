/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:39:16 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/31 12:31:06 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

double	interpolation(double value, double new_min, double new_max, double old_max)
{
	return (new_min + ((new_max - new_min) * (value) / (old_max)));
}

double	module(t_var *var)
{
	return (var->z.r * var->z.r + var->z.i * var->z.i);
}
