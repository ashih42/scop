/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:42:06 by ashih             #+#    #+#             */
/*   Updated: 2018/10/25 23:30:00 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		add_decimal(double *total, const char *str, int sign)
{
	int			i;

	if (*str != '.')
		return ;
	i = 1;
	while (ft_isdigit(*(++str)))
		*total += (double)(*str - '0') / ft_exp_dbl(10, i++) * sign;
}

double			ft_atodbl(const char *str)
{
	double		total;
	double		subtotal;
	int			sign;

	subtotal = 0.0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
		*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		sign = -1;
	else if (*str == '+')
		sign = 1;
	else
		str--;
	str++;
	while (ft_isdigit(*str))
	{
		subtotal = subtotal * 10 + (double)(*str - '0');
		str++;
	}
	total = (double)subtotal * sign;
	add_decimal(&total, str, sign);
	return (total);
}

static int		validate_dbl_regex(char *str)
{
	size_t		digits_before_dot;
	size_t		digits_after_dot;

	digits_before_dot = 0;
	digits_after_dot = 0;
	if (*str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		str++;
		digits_before_dot++;
	}
	if (*str == '.')
		str++;
	else
		return (!(*str == '\0'));
	while (ft_isdigit(*str))
	{
		str++;
		digits_after_dot++;
	}
	if (!(*str == '\0' && digits_before_dot > 0 && digits_after_dot > 0))
		return (1);
	return (0);
}

/*
** Return 1 if the str does not match reg expr [-][0-9]?.[0-9]?
** Otherwise, return 0, and store the double value at *d;
*/

int				ft_atodbl_check(char *str, double *d)
{
	if (validate_dbl_regex(str))
		return (1);
	*d = ft_atodbl(str);
	return (0);
}
