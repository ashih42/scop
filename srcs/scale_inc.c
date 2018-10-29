/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_inc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:20:35 by ashih             #+#    #+#             */
/*   Updated: 2018/10/26 01:31:28 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		inc_scale_x(t_master *m)
{
	m->scale_x *= SCALE_INC;
}

void		inc_scale_y(t_master *m)
{
	m->scale_y *= SCALE_INC;
}

void		inc_scale_z(t_master *m)
{
	m->scale_z *= SCALE_INC;
}

void		inc_scale_universal(t_master *m)
{
	m->scale_x *= SCALE_INC;
	m->scale_y *= SCALE_INC;
	m->scale_z *= SCALE_INC;
}
