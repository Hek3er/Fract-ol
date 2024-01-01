/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azainabi <azainabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 10:15:53 by azainabi          #+#    #+#             */
/*   Updated: 2024/01/01 20:47:04 by azainabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] > str2[i])
			return (str1[i] - str2[i]);
		if (str1[i] < str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0)
		return ;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_error(int n)
{
	ft_putstr_fd("Error!\n", 2);
	exit(n);
}

static double	get_after_deci(char *str, int i)
{
	double	tmp;
	int		mult;

	tmp = 0;
	mult = 1;
	if (str[i] == '.')
	{
		i++;
		while (str[i] && str[i] >= '0' && str[i] <= '9')
		{
			tmp = tmp * 10 + (str[i] - '0');
			mult *= 10;
			i++;
		}
		tmp /= mult;
	}
	return (tmp);
}

double	ft_atof(char *str)
{
	int		i;
	int		sign;
	double	result;
	double	tmp;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && str[i] != '.')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	tmp = get_after_deci(str, i);
	return ((result + tmp) * sign);
}
