/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 09:02:48 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 09:36:06 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		print_triangle(t_triangle *tri)
{
	ft_printf("triangle: ");
	ft_printf("(%d/%d/%d) ", tri->v_1, tri->vt_1, tri->vn_1);
	ft_printf("(%d/%d/%d) ", tri->v_2, tri->vt_2, tri->vn_2);
	ft_printf("(%d/%d/%d) ", tri->v_3, tri->vt_3, tri->vn_3);
	ft_printf("\n");
}

void			print_triangles(t_obj *obj)
{
	t_list		*triangle_list;

	triangle_list = obj->triangle_list;
	while (triangle_list)
	{
		print_triangle(triangle_list->content);
		triangle_list = triangle_list->next;
	}
}
