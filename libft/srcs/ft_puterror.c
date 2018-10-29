/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 00:47:08 by ashih             #+#    #+#             */
/*   Updated: 2018/10/27 02:33:10 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_puterror(char *message, char *term, int ret)
{
	if (term)
		ft_printf("{poop} Error: %s: {red}%s{reset}\n", message, term);
	else
		ft_printf("{poop} Error: %s\n", message);
	return (ret);
}

int		ft_puterror_at_line(size_t line_num, char *message, char *term, int ret)
{
	if (term)
		ft_printf("{poop} [Line %lu] Error: %s: {red}%s{reset}\n",
			line_num, message, term);
	else
		ft_printf("{poop} [Line %lu] Error: %s\n", line_num, message);
	return (ret);
}
