/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_key_held_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:56:54 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 07:38:07 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		process_input_with_left_shift(t_master *m)
{
	if (glfwGetKey(m->window, GLFW_KEY_KP_7) == GLFW_PRESS)
		inc_scale_x(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_8) == GLFW_PRESS)
		dec_scale_x(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_4) == GLFW_PRESS)
		inc_scale_y(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_5) == GLFW_PRESS)
		dec_scale_y(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_1) == GLFW_PRESS)
		inc_scale_z(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_2) == GLFW_PRESS)
		dec_scale_z(m);
}

static void		process_input_with_left_control(t_master *m)
{
	if (glfwGetKey(m->window, GLFW_KEY_KP_7) == GLFW_PRESS)
		inc_translate_x(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_8) == GLFW_PRESS)
		dec_translate_x(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_4) == GLFW_PRESS)
		inc_translate_y(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_5) == GLFW_PRESS)
		dec_translate_y(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_1) == GLFW_PRESS)
		inc_translate_z(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_2) == GLFW_PRESS)
		dec_translate_z(m);
}

# define SPECULAR_INC	0.01f

void			inc_percent_specular(t_master *m)
{
	m->percent_specular += SPECULAR_INC;
	CLAMP(m->percent_specular, 0.0f, 1.0f);
	glUniform1f(m->percent_specular_loc, m->percent_specular);
}

void			dec_percent_specular(t_master *m)
{
	m->percent_specular -= SPECULAR_INC;
	CLAMP(m->percent_specular, 0.0f, 1.0f);
	glUniform1f(m->percent_specular_loc, m->percent_specular);
}

static void		process_input_with_left_alt(t_master *m)
{
	if (glfwGetKey(m->window, GLFW_KEY_KP_7) == GLFW_PRESS)
		inc_light_position_x(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_8) == GLFW_PRESS)
		dec_light_position_x(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_4) == GLFW_PRESS)
		inc_light_position_y(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_5) == GLFW_PRESS)
		dec_light_position_y(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_1) == GLFW_PRESS)
		inc_light_position_z(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_2) == GLFW_PRESS)
		dec_light_position_z(m);
	if (glfwGetKey(m->window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
		inc_percent_specular(m);
	if (glfwGetKey(m->window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		dec_percent_specular(m);
}

static void		process_input_without_modifier(t_master *m)
{
	if (glfwGetKey(m->window, GLFW_KEY_KP_7) == GLFW_PRESS)
		inc_rotate_x(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_8) == GLFW_PRESS)
		dec_rotate_x(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_4) == GLFW_PRESS)
		inc_rotate_y(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_5) == GLFW_PRESS)
		dec_rotate_y(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_1) == GLFW_PRESS)
		inc_rotate_z(m);
	if (glfwGetKey(m->window, GLFW_KEY_KP_2) == GLFW_PRESS)
		dec_rotate_z(m);
	if (glfwGetKey(m->window, GLFW_KEY_PAGE_UP) == GLFW_PRESS)
		inc_percent_texture(m);
	if (glfwGetKey(m->window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS)
		dec_percent_texture(m);
}

/*
** for continuous key events, no delay
*/

void			process_key_held_input(t_master *m)
{
	if (glfwGetKey(m->window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		process_input_with_left_shift(m);
	else if (glfwGetKey(m->window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		process_input_with_left_control(m);
	else if (glfwGetKey(m->window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
		process_input_with_left_alt(m);
	else
		process_input_without_modifier(m);
	if (glfwGetKey(m->window, GLFW_KEY_HOME) == GLFW_PRESS)
		inc_scale_universal(m);
	if (glfwGetKey(m->window, GLFW_KEY_END) == GLFW_PRESS)
		dec_scale_universal(m);
}
