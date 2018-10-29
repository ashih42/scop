/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_vt_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 02:47:58 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 08:20:28 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int				parse_vt_uvw(char **tokens, t_obj *obj)
{
	t_vec2				vt;
	double				u;
	double				v;
	double				w;

	if (ft_char_array_length(tokens) != 4 ||
		ft_atodbl_check(tokens[1], &u) ||
		ft_atodbl_check(tokens[2], &v) ||
		ft_atodbl_check(tokens[3], &w))
		return (-1);
	vt = (t_vec2){(float)u, (float)v};
	ft_lstadd(&obj->vt_list, ft_lstnew(&vt, sizeof(t_vec2)));
	return (0);
}

static int				parse_vt_uv(char **tokens, t_obj *obj)
{
	t_vec2				vt;
	double				u;
	double				v;

	if (ft_char_array_length(tokens) != 3 ||
		ft_atodbl_check(tokens[1], &u) ||
		ft_atodbl_check(tokens[2], &v))
		return (-1);
	vt = (t_vec2){(float)u, (float)v};
	ft_lstadd(&obj->vt_list, ft_lstnew(&vt, sizeof(t_vec2)));
	return (0);
}

/*
** Possible formats:
** vt u v
** vt u v w
*/

int						handle_vt_line(char *line, t_obj *obj)
{
	char				**tokens;
	int					error;

	if (!(tokens = ft_strsplit(line, ' ')))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	if (!parse_vt_uv(tokens, obj))
		error = 0;
	else if (!parse_vt_uvw(tokens, obj))
		error = 0;
	else
		error = ft_puterror_at_line(obj->line_num, ERROR_OBJ_LINE, line, -1);
	ft_char_array_del(tokens);
	return (error);
}
