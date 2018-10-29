/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vertex_objects.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 22:57:17 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 09:54:41 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
** Each vertex data contains:
** position				(x, y, z)		(from .obj file)
** texture coordinates	(u, v)			(from .obj file)
** color				(r, g, b)		(randomly generated per triangle)
** my normal			(x, y, z)		(generated per triangle)
** their normal			(x, y, z)		(from .obj file)
*/

int					init_vertex_objects(t_master *m)
{
	unsigned int	vbo;
	unsigned int	vao;

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * STRIDE_LEN * 3 * m->obj.triangle_count, m->gl_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, STRIDE_LEN * sizeof(float), (void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, STRIDE_LEN * sizeof(float), (void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, STRIDE_LEN * sizeof(float), (void *)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, STRIDE_LEN * sizeof(float), (void *)(8 * sizeof(float)));
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, STRIDE_LEN * sizeof(float), (void *)(11 * sizeof(float)));
	glEnableVertexAttribArray(4);
	return (0);
}
