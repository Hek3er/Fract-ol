/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:11:34 by azainabi          #+#    #+#             */
/*   Updated: 2023/12/31 13:36:53 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define Width 800
#define Height 800
#define Iteration 42

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct complex
{
	double	r;
	double	i;
	double	tmp;
}	t_complex;

typedef struct image
{
	void *mlx_img;
	char *img_data;
	int	bpp;
	int	len;
	int endian;
}				t_img;

typedef struct mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_img	img;
}				t_data;

typedef struct	s_var
{
	int			j;
	int			x;
	int			y;
	int			color;
	int			zoom;
	int			color_shift;
	int			shift_x;
	int			shift_y;
	t_complex	z;
	t_complex	c;
}				t_var;

void	ini_mlx(t_data *data);
void	mandelbrot(void);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(int n);
int 	ft_strncmp(char *s1, char *s2, int n);
double	interpolation(double value, double new_min, double new_max, double old_max);
double	module(t_var *var);

#endif