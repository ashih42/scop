/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_triangle_point.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 03:38:34 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 09:01:14 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		parse_v_vt_vn_str(int *v, int *vt, int *vn,
	char *v_str, char *vt_str, char *vn_str)
{
	int			error;

	error = ft_atoi_check(v_str, v) || *v <= 0;
	if (*vt_str == '\0')
		*vt = INVALID_VT;
	else
		error |= ft_atoi_check(vt_str, vt) || *vt <= 0;
	if (*vn_str == '\0')
		*vn = INVALID_VN;
	else
		error |= ft_atoi_check(vn_str, vn) || *vn <= 0;
	return (error);
}

int				handle_triangle_point(char *str, int *v, int *vt, int *vn)
{
	char		*v_str;
	char		*vt_str;
	char		*vn_str;
	int			error;

	v_str = NULL;
	vt_str = NULL;
	vn_str = NULL;
	error = get_triangle_point_v_vt_vn_str(str, &v_str, &vt_str, &vn_str) ||
		parse_v_vt_vn_str(v, vt, vn, v_str, vt_str, vn_str);
	ft_strdel(&v_str);
	ft_strdel(&vt_str);
	ft_strdel(&vn_str);
	return (error);
}
