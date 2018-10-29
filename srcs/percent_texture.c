/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 01:34:07 by ashih             #+#    #+#             */
/*   Updated: 2018/10/26 01:34:58 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void			inc_percent_texture(t_master *m)
{
	m->percent_texture += PERCENT_TEX_INC;
	if (m->percent_texture > 1.0f)
		m->percent_texture = 1.0f;
	glUniform1f(m->percent_texture_loc, m->percent_texture);
}

void			dec_percent_texture(t_master *m)
{
	m->percent_texture -= PERCENT_TEX_INC;
	if (m->percent_texture < 0.0f)
		m->percent_texture = 0.0f;
	glUniform1f(m->percent_texture_loc, m->percent_texture);
}
