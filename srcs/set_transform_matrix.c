/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_transform_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:39:38 by ashih             #+#    #+#             */
/*   Updated: 2018/10/25 01:17:36 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void				apply_local_to_world_transforms(
	float transform_matrix[4][4], t_master *m)
{
	float			scaling_matrix[4][4];
	float			rotation_x_matrix[4][4];
	float			rotation_y_matrix[4][4];
	float			rotation_z_matrix[4][4];
	float			translation_matrix[4][4];

	init_scaling_matrix(scaling_matrix, m->scale_x, m->scale_y, m->scale_z);
	init_rotation_x_matrix(rotation_x_matrix, DEG_TO_RAD(m->degrees_rotate_x));
	init_rotation_y_matrix(rotation_y_matrix, DEG_TO_RAD(m->degrees_rotate_y));
	init_rotation_z_matrix(rotation_z_matrix, DEG_TO_RAD(m->degrees_rotate_z));
	init_translation_matrix(translation_matrix,
		m->translate_x, m->translate_y, m->translate_z);
	matrix_multiply(scaling_matrix, transform_matrix);
	matrix_multiply(rotation_x_matrix, transform_matrix);
	matrix_multiply(rotation_y_matrix, transform_matrix);
	matrix_multiply(rotation_z_matrix, transform_matrix);
	matrix_multiply(translation_matrix, transform_matrix);
}

void				apply_view_transform(float transform_matrix[4][4])
{
	float			view_matrix[4][4];

	init_translation_matrix(view_matrix, 0.0f, 0.0f, -3.0f);
	matrix_multiply(view_matrix, transform_matrix);
}

void				apply_projection(
	float transform_matrix[4][4], int is_perspective)
{
	float			projection_matrix[4][4];

	if (is_perspective)
		init_perspective_projection_matrix(projection_matrix);
	else
		init_orthographic_projection_matrix(projection_matrix);
	matrix_multiply(projection_matrix, transform_matrix);
}

void				set_transform_matrix(t_master *m)
{
	float			transform_matrix[4][4];

	init_identity_matrix(transform_matrix);
	apply_local_to_world_transforms(transform_matrix, m);
	apply_view_transform(transform_matrix);
	apply_projection(transform_matrix, m->is_perspective);
	glUniformMatrix4fv(m->transform_matrix_loc, 1, GL_TRUE,
		(float *)transform_matrix);
}
