/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 21:39:35 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 10:04:54 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		toggle_wireframe_mode(t_master *m)
{
	m->is_wireframe = !m->is_wireframe;
	glPolygonMode(GL_FRONT_AND_BACK, m->is_wireframe ? GL_LINE : GL_FILL);
}

void		toggle_grayscale(t_master *m)
{
	m->is_grayscale = !m->is_grayscale;
	glUniform1i(m->is_grayscale_loc, m->is_grayscale);
}

void		toggle_smooth_color(t_master *m)
{
	m->is_smooth_color = !m->is_smooth_color;
	glUniform1i(m->is_smooth_color_loc, m->is_smooth_color);
}

void		toggle_default_uv(t_master *m)
{
	m->is_default_uv = !m->is_default_uv;
	glUniform1i(m->is_default_uv_loc, m->is_default_uv);
}

void		toggle_light_on(t_master *m)
{
	m->is_light_on = !m->is_light_on;
	glUniform1i(m->is_light_on_loc, m->is_light_on);
}

void		toggle_my_normal(t_master *m)
{
	m->is_my_normal = !m->is_my_normal;
	glUniform1i(m->is_my_normal_loc, m->is_my_normal);
}
