/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:31:44 by ashih             #+#    #+#             */
/*   Updated: 2018/10/24 21:33:54 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		print_matrix(float m[4][4])
{
	int		i;

	i = -1;
	while (++i < 4)
		ft_printf("%f\t%f\t%f\t%f\n", m[i][0], m[i][1], m[i][2], m[i][3]);
	ft_printf("\n");
}

/*
** multiply A x B, and store the result in B
*/

void		matrix_multiply(float a[4][4], float b[4][4])
{
	float	result[4][4];
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] +
				a[i][2] * b[2][j] + a[i][3] * b[3][j];
		}
	}
	ft_memcpy(b, result, sizeof(float) * 16);
}

/*
** [ 1 0 0 0 ]
** [ 0 1 0 0 ]
** [ 0 0 1 0 ]
** [ 0 0 0 1 ]
*/

void		init_identity_matrix(float m[4][4])
{
	int		i;

	ft_bzero(m, sizeof(float) * 16);
	i = -1;
	while (++i < 4)
		m[i][i] = 1.0f;
}

void		init_orthographic_projection_matrix(float m[4][4])
{
	float	left;
	float	right;
	float	bottom;
	float	top;

	left = -1.0f;
	right = 1.0f;
	bottom = -1.0f;
	top = 1.0f;
	init_identity_matrix(m);
	m[0][0] = 2.0f / (right - left);
	m[1][1] = 2.0f / (top - bottom);
	m[2][2] = -2.0f / (FAR_PLANE - NEAR_PLANE);
	m[2][3] = -(FAR_PLANE + NEAR_PLANE) / (FAR_PLANE - NEAR_PLANE);
	m[0][3] = -(right + left) / (right - left);
	m[1][3] = -(top + bottom) / (top - bottom);
}

void		init_perspective_projection_matrix(float m[4][4])
{
	float	fov_radians;

	ft_bzero(m, sizeof(float) * 16);
	fov_radians = DEG_TO_RAD(FOV_DEGREES);
	m[0][0] = 1.0f / (ASPECT_RATIO * tan(fov_radians / 2));
	m[1][1] = 1.0f / (tan(fov_radians / 2.0f));
	m[2][2] = -(FAR_PLANE + NEAR_PLANE) / (FAR_PLANE - NEAR_PLANE);
	m[2][3] = -2.0f * FAR_PLANE * NEAR_PLANE / (FAR_PLANE - NEAR_PLANE);
	m[3][2] = -1.0f;
}
