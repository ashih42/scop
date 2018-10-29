/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_inc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:22:22 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 07:41:38 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		inc_rotate_x(t_master *m)
{
	m->degrees_rotate_x += ROTATE_INC;
	clamp_degrees(&m->degrees_rotate_x);
}

void		inc_rotate_y(t_master *m)
{
	m->degrees_rotate_y += ROTATE_INC;
	clamp_degrees(&m->degrees_rotate_y);
}

void		inc_rotate_z(t_master *m)
{
	m->degrees_rotate_z += ROTATE_INC;
	clamp_degrees(&m->degrees_rotate_z);
}
