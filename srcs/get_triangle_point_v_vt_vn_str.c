/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_triangle_point_v_vt_vn_str.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:33:58 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 08:59:51 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		get_triangle_point_v_vt_str_slash_2(
	char *str, char **v_str, char **vt_str, char **vn_str)
{
	size_t		v_str_len;
	size_t		vt_str_len;
	int			i;

	v_str_len = 0;
	vt_str_len = 0;
	i = 0;
	while (str[i] != '/')
	{
		v_str_len++;
		i++;
	}
	*v_str = ft_substr(str, v_str_len);
	i++;
	while (str[i] != '/')
	{
		vt_str_len++;
		i++;
	}
	*vt_str = ft_substr(str + v_str_len + 1, vt_str_len);
	*vn_str = ft_strdup(str + v_str_len + vt_str_len + 2);
	if (!*v_str || !*vt_str || !*vn_str)
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	return (0);
}

static int		get_triangle_point_v_vt_str_slash_1(
	char *str, char **v_str, char **vt_str, char **vn_str)
{
	char		**tokens;
	int			error;

	if (!(tokens = ft_strsplit(str, '/')))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	*v_str = ft_strdup(tokens[0]);
	*vt_str = ft_strdup(tokens[1]);
	error = (!*v_str || !*vt_str);
	ft_char_array_del(tokens);
	if (!(*vn_str = ft_strnew(0)))
		error = ft_puterror(ERROR_MEMORY, NULL, -1);
	return (error);
}

static int		get_triangle_point_v_vt_str_slash_0(
	char *str, char **v_str, char **vt_str, char **vn_str)
{
	if (!(*v_str = ft_strdup(str)) ||
		!(*vt_str = ft_strnew(0)) ||
		!(*vn_str = ft_strnew(0)))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	return (0);
}

/*
** Possible formats:
** v
** v/vt
** v/vt/vn
** v//vn
*/

int				get_triangle_point_v_vt_vn_str(
	char *str, char **v_str, char **vt_str, char **vn_str)
{
	int			slash_count;

	slash_count = count_chars(str, '/');
	if (slash_count == 0)
		return (get_triangle_point_v_vt_str_slash_0(str, v_str, vt_str, vn_str));
	else if (slash_count == 1)
		return (get_triangle_point_v_vt_str_slash_1(str, v_str, vt_str, vn_str));
	else if (slash_count == 2)
		return (get_triangle_point_v_vt_str_slash_2(str, v_str, vt_str, vn_str));
	else
		return (-1);
}
