/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:31:35 by ashih             #+#    #+#             */
/*   Updated: 2018/10/24 21:32:23 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** [ Sx 0  0  0 ]
** [ 0  Sy 0  0 ]
** [ 0  0  Sz 0 ]
** [ 0  0  0  1 ]
*/

void		init_scaling_matrix(float m[4][4], float scale_x,
	float scale_y, float scale_z)
{
	ft_bzero(m, sizeof(float) * 16);
	m[0][0] = scale_x;
	m[1][1] = scale_y;
	m[2][2] = scale_z;
	m[3][3] = 1.0f;
}

/*
** [ 1 0 0 Tx ]
** [ 0 1 0 Ty ]
** [ 0 0 1 Tz ]
** [ 0 0 0 1  ]
*/

void		init_translation_matrix(float m[4][4], float translate_x,
	float translate_y, float translate_z)
{
	init_identity_matrix(m);
	m[0][3] = translate_x;
	m[1][3] = translate_y;
	m[2][3] = translate_z;
}

/*
** [ 1    0    0    0 ]
** [ 0    cos  -sin 0 ]
** [ 0    sin  cos  0 ]
** [ 0    0    0    1 ]
*/

void		init_rotation_x_matrix(float m[4][4], float radians)
{
	init_identity_matrix(m);
	m[1][1] = cos(radians);
	m[1][2] = -sin(radians);
	m[2][1] = sin(radians);
	m[2][2] = cos(radians);
}

/*
** [ cos  0    sin  0 ]
** [ 0    1    0    0 ]
** [ -sin 0    cos  0 ]
** [ 0    0    0    1 ]
*/

void		init_rotation_y_matrix(float m[4][4], float radians)
{
	init_identity_matrix(m);
	m[0][0] = cos(radians);
	m[0][2] = sin(radians);
	m[2][0] = -sin(radians);
	m[2][2] = cos(radians);
}

/*
** [ cos  -sin 0    0 ]
** [ sin  cos  0    0 ]
** [ 0    0    1    0 ]
** [ 0    0    0    1 ]
*/

void		init_rotation_z_matrix(float m[4][4], float radians)
{
	init_identity_matrix(m);
	m[0][0] = cos(radians);
	m[0][1] = -sin(radians);
	m[1][0] = sin(radians);
	m[1][1] = cos(radians);
}
