/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_triangles_to_gl_data.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 22:00:03 by ashih             #+#    #+#             */
/*   Updated: 2018/10/30 09:27:48 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static t_vec3	generate_random_color(void)
{
	t_vec3		color;

	color.x = (float)rand() / (float)RAND_MAX;
	color.y = (float)rand() / (float)RAND_MAX;
	color.z = (float)rand() / (float)RAND_MAX;
	return (color);
}

static void		copy_triangle_point_to_gl_data(
	float *gl_data, t_vec3 *v, t_vec2 *vt, t_vec3 *vn, t_triangle *triangle)
{
	gl_data[0] = v->x;
	gl_data[1] = v->y;
	gl_data[2] = v->z;
	gl_data[3] = (vt) ? vt->x : 0.0f;
	gl_data[4] = (vt) ? vt->y : 0.0f;
	gl_data[5] = triangle->my_color.x;
	gl_data[6] = triangle->my_color.y;
	gl_data[7] = triangle->my_color.z;
	gl_data[8] = triangle->my_normal.x;
	gl_data[9] = triangle->my_normal.y;
	gl_data[10] = triangle->my_normal.z;
	gl_data[11] = (vn) ? vn->x : 0.0f;
	gl_data[12] = (vn) ? vn->y : 0.0f;
	gl_data[13] = (vn) ? vn->z : 0.0f;
}

static t_vec3	*get_v(t_obj *obj, int v_index)
{
	return (&obj->v_array[v_index - 1]);
}

static t_vec2	*get_vt(t_obj *obj, int vt_index)
{
	if (vt_index == INVALID_VT)
		return (NULL);
	else
		return (&obj->vt_array[vt_index - 1]);
}

static t_vec3	*get_vn(t_obj *obj, int vn_index)	// USE THIS
{
	if (vn_index == INVALID_VN)
		return (NULL);
	else
		return (&obj->vn_array[vn_index - 1]);
}

int				copy_triangles_to_gl_data(
	t_master *m, t_obj *obj, t_list *triangle_list)
{
	float		*gl_data;
	t_triangle	*tri;

	gl_data = m->gl_data;
	while (triangle_list)
	{
		tri = triangle_list->content;
		tri->my_color = generate_random_color();
		tri->my_normal = generate_normal(get_v(obj, tri->v_1), get_v(obj, tri->v_2), get_v(obj, tri->v_3));
		copy_triangle_point_to_gl_data(gl_data, get_v(obj, tri->v_1), get_vt(obj, tri->vt_1), get_vn(obj, tri->vn_1), tri);
		gl_data += STRIDE_LEN;
		copy_triangle_point_to_gl_data(gl_data, get_v(obj, tri->v_2), get_vt(obj, tri->vt_2), get_vn(obj, tri->vn_2), tri);
		gl_data += STRIDE_LEN;
		copy_triangle_point_to_gl_data(gl_data, get_v(obj, tri->v_3), get_vt(obj, tri->vt_3), get_vn(obj, tri->vn_3), tri);
		gl_data += STRIDE_LEN;
		triangle_list = triangle_list->next;
	}
	return (0);
}
