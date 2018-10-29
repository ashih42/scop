/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:22:28 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 07:42:24 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		clamp_degrees(int *degrees)
{
	if (*degrees > 360)
		*degrees -= 360;
	else if (*degrees < 0)
		*degrees += 360;
}

void		dec_rotate_x(t_master *m)
{
	m->degrees_rotate_x -= ROTATE_INC;
	clamp_degrees(&m->degrees_rotate_x);
}

void		dec_rotate_y(t_master *m)
{
	m->degrees_rotate_y -= ROTATE_INC;
	clamp_degrees(&m->degrees_rotate_y);
}

void		dec_rotate_z(t_master *m)
{
	m->degrees_rotate_z -= ROTATE_INC;
	clamp_degrees(&m->degrees_rotate_z);
}
