/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:53:11 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/02 20:11:38 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fractol.h"

void zoom(t_var *var, int x, int y) {
    double  ax;
    double  ay;

    ax = (var->r_max - var->r_min) / W;
    ay = (var->i_max - var->i_min) / H;
    var->r_min = (var->r_min + ((ax * x) * 0.2));
	var->r_max = (var->r_max - ((ax * (W - x)) * 0.2));
	var->i_max = (var->i_max - ((ay * y) * 0.2));
	var->i_min = (var->i_min + ((ay * (H - y)) * 0.2));
}