/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_position_inc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 02:04:42 by ashih             #+#    #+#             */
/*   Updated: 2018/10/27 21:04:32 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		inc_light_position_x(t_master *m)
{
	m->light_position.x += TRANSLATE_INC / m->scale_x;
	glUniform3fv(m->light_position_loc, 1, (float *)&m->light_position);
}

void		inc_light_position_y(t_master *m)
{
	m->light_position.y += TRANSLATE_INC / m->scale_x;
	glUniform3fv(m->light_position_loc, 1, (float *)&m->light_position);
}

void		inc_light_position_z(t_master *m)
{
	m->light_position.z += TRANSLATE_INC / m->scale_x;
	glUniform3fv(m->light_position_loc, 1, (float *)&m->light_position);
}
