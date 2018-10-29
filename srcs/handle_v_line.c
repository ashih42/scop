/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_v_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 02:37:38 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 08:27:53 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		update_obj_min_max(t_obj *obj, t_vec3 *vertex)
{
	if (vertex->x < obj->x_min)
		obj->x_min = vertex->x;
	if (vertex->x > obj->x_max)
		obj->x_max = vertex->x;
	if (vertex->y < obj->y_min)
		obj->y_min = vertex->y;
	if (vertex->y > obj->y_max)
		obj->y_max = vertex->y;
	if (vertex->z < obj->z_min)
		obj->z_min = vertex->z;
	if (vertex->z > obj->z_max)
		obj->z_max = vertex->z;
}

static int		parse_v_xyzw(char **tokens, t_obj *obj)
{
	t_vec3		vertex;
	double		x;
	double		y;
	double		z;
	double		w;

	if (ft_char_array_length(tokens) != 5 ||
		ft_atodbl_check(tokens[1], &x) ||
		ft_atodbl_check(tokens[2], &y) ||
		ft_atodbl_check(tokens[3], &z) ||
		ft_atodbl_check(tokens[4], &w))
		return (-1);
	vertex = (t_vec3){(float)x, (float)y, (float)z};
	update_obj_min_max(obj, &vertex);
	ft_lstadd(&obj->v_list, ft_lstnew(&vertex, sizeof(t_vec3)));
	return (0);
}

static int		parse_v_xyz(char **tokens, t_obj *obj)
{
	t_vec3		vertex;
	double		x;
	double		y;
	double		z;

	if (ft_char_array_length(tokens) != 4 ||
		ft_atodbl_check(tokens[1], &x) ||
		ft_atodbl_check(tokens[2], &y) ||
		ft_atodbl_check(tokens[3], &z))
		return (-1);
	vertex = (t_vec3){(float)x, (float)y, (float)z};
	update_obj_min_max(obj, &vertex);
	ft_lstadd(&obj->v_list, ft_lstnew(&vertex, sizeof(t_vec3)));
	return (0);
}

/*
** Possible formats:
** v x y z
** v x y z w
*/

int				handle_v_line(char *line, t_obj *obj)
{
	char		**tokens;
	int			error;

	if (!(tokens = ft_strsplit(line, ' ')))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	if (!parse_v_xyz(tokens, obj))
		error = 0;
	else if (!parse_v_xyzw(tokens, obj))
		error = 0;
	else
		error = ft_puterror_at_line(obj->line_num, ERROR_OBJ_LINE, line, -1);
	ft_char_array_del(tokens);
	return (error);
}
