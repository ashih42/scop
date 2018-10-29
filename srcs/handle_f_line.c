/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 02:42:08 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 08:53:01 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		parse_one_triangle(
	char *str_1, char *str_2, char *str_3, t_triangle *tri)
{
	return (handle_triangle_point(str_1, &tri->v_1, &tri->vt_1, &tri->vn_1) ||
		handle_triangle_point(str_2, &tri->v_2, &tri->vt_2, &tri->vn_2) ||
		handle_triangle_point(str_3, &tri->v_3, &tri->vt_3, &tri->vn_3));
}

static int		parse_and_triangulate(char **tokens, t_obj *obj)
{
	t_triangle	triangle;
	int			sides;
	int			i;

	sides = ft_char_array_length(tokens) - 1;
	if (sides < 3)
		return (-1);
	i = 2;
	while (++i <= sides)
	{
		if (parse_one_triangle(tokens[1], tokens[i - 1], tokens[i], &triangle))
			return (-1);
		ft_lstadd(&obj->triangle_list,
			ft_lstnew(&triangle, sizeof(t_triangle)));
	}
	return (0);
}

/*
** Possible formats:
** f	v1				v2				v3
** f	v1/vt1			v2/vt2			v3/vt3
** f	v1/vt1/vn1		v2/vt2/vn2		v3/vt3/vn3
** f	v1//vn1			v2//vn2			v3//vn3
*/

int				handle_f_line(char *line, t_obj *obj)
{
	char		**tokens;
	int			error;

	if (!(tokens = ft_strsplit(line, ' ')))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	error = parse_and_triangulate(tokens, obj);
	if (error)
		error = ft_puterror_at_line(obj->line_num, ERROR_OBJ_LINE, line, -1);
	ft_char_array_del(tokens);
	return (error);
}
