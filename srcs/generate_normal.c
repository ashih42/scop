/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 22:05:54 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 08:25:46 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		normalize(t_vec3 *v)
{
	float		magnitude;

	magnitude = sqrt(SQ(v->x) + SQ(v->y) + SQ(v->z));
	if (magnitude != 0.0f)
	{
		v->x /= magnitude;
		v->y /= magnitude;
		v->z /= magnitude;
	}
}

static t_vec3	get_cross_product(t_vec3 *a, t_vec3 *b)
{
	t_vec3		product;

	product.x = (a->y * b->z - a->z * b->y);
	product.y = (a->z * b->x - a->x * b->z);
	product.z = (a->x * b->y - a->y * b->x);
	normalize(&product);
	return (product);
}

t_vec3			generate_normal(t_vec3 *v1, t_vec3 *v2, t_vec3 *v3)
{
	t_vec3		side_1_2;
	t_vec3		side_1_3;

	side_1_2.x = v2->x - v1->x;
	side_1_2.y = v2->y - v1->y;
	side_1_2.z = v2->z - v1->z;
	side_1_3.x = v3->x - v1->x;
	side_1_3.y = v3->y - v1->y;
	side_1_3.z = v3->z - v1->z;
	return (get_cross_product(&side_1_2, &side_1_3));
}
