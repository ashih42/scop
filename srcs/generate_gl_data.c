/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_gl_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:11:42 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 09:25:45 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static float	get_centered_value(float value, float low, float high)
{
	if (low != FLT_MAX && high != FLT_MIN)
		return ((value - low) - (high - low) / 2.0f);
	else
		return (value);
}

static int		copy_obj_v_list_to_v_array(t_obj *obj)
{
	t_list		*v_list;
	t_vec3		*vertex;
	int			index;

	if (!(obj->v_array = malloc(sizeof(t_vec3) * (size_t)obj->v_count)))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	index = obj->v_count - 1;
	v_list = obj->v_list;
	while (v_list)
	{
		vertex = v_list->content;
		vertex->x = get_centered_value(vertex->x, obj->x_min, obj->x_max);
		vertex->y = get_centered_value(vertex->y, obj->y_min, obj->y_max);
		vertex->z = get_centered_value(vertex->z, obj->z_min, obj->z_max);
		obj->v_array[index] = *vertex;
		v_list = v_list->next;
		index--;
	}
	return (0);
}

static int		copy_obj_vt_list_to_vt_array(t_obj *obj)
{
	t_list		*vt_list;
	t_vec2		*vt;
	int			index;

	if (!(obj->vt_array = malloc(sizeof(t_vec2) * (size_t)obj->vt_count)))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	index = obj->vt_count - 1;
	vt_list = obj->vt_list;
	while (vt_list)
	{
		vt = vt_list->content;
		obj->vt_array[index] = *vt;
		vt_list = vt_list->next;
		index--;
	}
	return (0);
}

static int		copy_obj_vn_list_to_vn_array(t_obj *obj)
{
	t_list		*vn_list;
	t_vec3		*vn;
	int			index;

	if (!(obj->vn_array = malloc(sizeof(t_vec3) * (size_t)obj->vn_count)))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	index = obj->vn_count - 1;
	vn_list = obj->vn_list;
	while(vn_list)
	{
		vn = vn_list->content;
		obj->vn_array[index] = *vn;
		vn_list = vn_list->next;
		index--;
	}
	return (0);
}

static int		validate_triangle_indices(t_obj *obj)
{
	t_list		*triangle_list;
	t_triangle	*triangle;

	triangle_list = obj->triangle_list;
	while (triangle_list)
	{
		triangle = triangle_list->content;
		if (triangle->v_1 > obj->v_count ||
			triangle->v_2 > obj->v_count ||
			triangle->v_3 > obj->v_count ||
			triangle->vt_1 > obj->vt_count ||
			triangle->vt_2 > obj->vt_count ||
			triangle->vt_3 > obj->vt_count ||
			triangle->vn_1 > obj->vn_count ||
			triangle->vn_2 > obj->vn_count ||
			triangle->vn_3 > obj->vn_count)
			return (ft_puterror("Out of range v/vt index detected", NULL, -1));
		triangle_list = triangle_list->next;
	}
	return (0);
}

int				generate_gl_data(t_master *m, t_obj *obj)
{
	obj->v_count = ft_lst_size(obj->v_list);
	obj->vt_count = ft_lst_size(obj->vt_list);
	obj->vn_count = ft_lst_size(obj->vn_list);
	obj->triangle_count = ft_lst_size(obj->triangle_list);
	if (validate_triangle_indices(obj) || copy_obj_v_list_to_v_array(obj) ||
		copy_obj_vt_list_to_vt_array(obj) || copy_obj_vn_list_to_vn_array(obj))
		return (-1);
	if (!(m->gl_data = malloc(sizeof(float) * STRIDE_LEN * 3 *
		(size_t)obj->triangle_count)))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	return (copy_triangles_to_gl_data(m, obj, obj->triangle_list));
}
