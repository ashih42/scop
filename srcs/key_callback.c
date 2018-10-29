/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:06:36 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 09:58:36 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		reset_transform_params(t_master *m)
{
	m->degrees_rotate_x = 0;
	m->degrees_rotate_y = 0;
	m->degrees_rotate_z = 0;
	m->scale_x = 1.0f;
	m->scale_y = 1.0f;
	m->scale_z = 1.0f;
	m->translate_x = 0.0f;
	m->translate_y = 0.0f;
	m->translate_z = 0.0f;
	m->is_spinning = 0;
	m->is_perspective = 1;
}

void			reset_scop_params(t_master *m)
{
	reset_transform_params(m);
	m->is_wireframe = 0;
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	m->current_texture_index = 0;
	glBindTexture(GL_TEXTURE_2D, m->texture_id[m->current_texture_index]);
	m->percent_texture = 0.0f;
	glUniform1f(m->percent_texture_loc, m->percent_texture);
	m->is_grayscale = 0;
	glUniform1i(m->is_grayscale_loc, m->is_grayscale);
	m->is_smooth_color = 0;
	glUniform1i(m->is_smooth_color_loc, m->is_smooth_color);
	m->is_default_uv = 1;
	glUniform1i(m->is_default_uv_loc, m->is_default_uv);
	m->light_position = (t_vec3){0.0f, 5.0f, 5.0f};
	glUniform3fv(m->light_position_loc, 1, (float *)&m->light_position);
	m->is_light_on = 0;
	glUniform1i(m->is_light_on_loc, m->is_light_on);
	m->percent_specular = 0.0f;
	glUniform1f(m->percent_specular_loc, m->percent_specular);
	m->is_my_normal = 1;
	glUniform1i(m->is_my_normal_loc, m->is_my_normal);
}

static void		select_next_texture(t_master *m)
{
	m->current_texture_index = (m->current_texture_index + 1)
		% NUM_TEXTURES;
	glBindTexture(GL_TEXTURE_2D, m->texture_id[m->current_texture_index]);
}

/*
** for single press key events
*/

void			key_callback(
	GLFWwindow *window, int key, int scancode, int action, int mods)
{
	t_master	*m;

	m = glfwGetWindowUserPointer(window);
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	else if (key == GLFW_KEY_P && action == GLFW_PRESS)
		m->is_perspective = !m->is_perspective;
	else if (key == GLFW_KEY_W && action == GLFW_PRESS)
		toggle_wireframe_mode(m);
	else if (key == GLFW_KEY_S && action == GLFW_PRESS)
		m->is_spinning = !m->is_spinning;
	else if (key == GLFW_KEY_R && action == GLFW_PRESS)
		reset_scop_params(m);
	else if (key == GLFW_KEY_TAB && action == GLFW_PRESS)
		select_next_texture(m);
	else if (key == GLFW_KEY_G && action == GLFW_PRESS)
		toggle_grayscale(m);
	else if (key == GLFW_KEY_C && action == GLFW_PRESS)
		toggle_smooth_color(m);
	else if (key == GLFW_KEY_U && action == GLFW_PRESS)
		toggle_default_uv(m);
	else if (key == GLFW_KEY_L && action == GLFW_PRESS)
		toggle_light_on(m);
	else if (key == GLFW_KEY_N && action == GLFW_PRESS)
		toggle_my_normal(m);
	(void)scancode;
	(void)mods;
}
