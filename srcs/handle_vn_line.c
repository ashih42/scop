/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_vn_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 08:30:52 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 10:40:16 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		parse_vn_ijk(char **tokens, t_obj *obj)
{
	t_vec3		vn;
	double		i;
	double		j;
	double		k;

	if (ft_char_array_length(tokens) != 4 ||
		ft_atodbl_check(tokens[1], &i) ||
		ft_atodbl_check(tokens[2], &j) ||
		ft_atodbl_check(tokens[3], &k))
		return (-1);
	vn = (t_vec3){(float)i, (float)j, (float)k};
	ft_lstadd(&obj->vn_list, ft_lstnew(&vn, sizeof(t_vec3)));
	return (0);
}

/*
** Possible formats:
** vn i j k
*/

int				handle_vn_line(char *line, t_obj *obj)
{
	char		**tokens;
	int			error;

	if (!(tokens = ft_strsplit(line, ' ')))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	error = parse_vn_ijk(tokens, obj);
	if (error)
		ft_puterror_at_line(obj->line_num, ERROR_OBJ_LINE, line, -1);
	ft_char_array_del(tokens);
	return (error);
}
