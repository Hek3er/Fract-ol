/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:11:34 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/03 11:20:06 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define W 800
# define H 800

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <libc.h> // need to remove it

typedef struct complex
{
	double	r;
	double	i;
	double	tmp;
}	t_complex;

typedef struct image
{
	void	*mlx_img;
	char	*img_data;
	int		bpp;
	int		len;
	int		endian;
}				t_img;

typedef struct mlx_data
{
	void	*mlx_ptr;
	void	*mlx_window;
	t_img	img;
}				t_data;

typedef struct s_var
{
	t_data			data;
	int				id;
	int				j;
	int				x;
	int				y;
	int				color;
	int				color_shift;
	int				add;
	int				iteration;
	int				tmp;
	double			real;
	double			imaginary;
	double			zoom;
	double			shift_x;
	double			shift_y;
	double			r_min;
	double			r_max;
	double			i_min;
	double			i_max;
	double			ax;
	double			ay;
	t_complex		z;
	t_complex		c;
}				t_var;

void	ini_mlx(t_data *data);
void	mandelbrot(t_var *var);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(int n);
int		ft_strncmp(char *s1, char *s2, int n);
double	interp(double value, double new_min, double new_max,
			double old_max);
double	module(t_var *var);
void	data_init(t_var *var);
void	init_hooks(t_data *data);
void	draw_pixel(int x, int y, t_img *img, int color);
void	render_mandelbrot(t_var *var);
void	julia(t_var *var);
void	render_julia(t_var *var);
double	ft_atof(char *str);
void	print_error(void);
void	mandelbrot_bonus(t_var *var);
void	render_mandelbrot_bonus(t_var *var);
void	julia_bonus(t_var *var);
void	render_julia_bonus(t_var *var);
void	burning_ship(t_var *var);
void	render_burning_ship(t_var *var);

#endif