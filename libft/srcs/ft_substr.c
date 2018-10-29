/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:30:55 by ashih             #+#    #+#             */
/*   Updated: 2018/10/27 21:31:14 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_substr(char *str, size_t len)
{
	char		*substr;

	if (!(substr = ft_strnew(len)))
		return (NULL);
	substr = ft_strncpy(substr, str, len);
	return (substr);
}
