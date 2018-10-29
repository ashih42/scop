/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale_dec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:20:56 by ashih             #+#    #+#             */
/*   Updated: 2018/10/26 01:31:30 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		dec_scale_x(t_master *m)
{
	m->scale_x *= SCALE_DEC;
}

void		dec_scale_y(t_master *m)
{
	m->scale_y *= SCALE_DEC;
}

void		dec_scale_z(t_master *m)
{
	m->scale_z *= SCALE_DEC;
}

void		dec_scale_universal(t_master *m)
{
	m->scale_x *= SCALE_DEC;
	m->scale_y *= SCALE_DEC;
	m->scale_z *= SCALE_DEC;
}
