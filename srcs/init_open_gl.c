/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_open_gl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:44:05 by ashih             #+#    #+#             */
/*   Updated: 2018/10/26 01:31:14 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void			scroll_callback(
	GLFWwindow *window, double x_offset, double y_offset)
{
	t_master		*m;

	m = glfwGetWindowUserPointer(window);
	if (y_offset > 0.0)
		inc_scale_universal(m);
	else if (y_offset < 0.0)
		dec_scale_universal(m);
	(void)x_offset;
}

static void			cursor_position_callback(
	GLFWwindow *window, double x_pos, double y_pos)
{
	static double	x_pos_prev;
	static double	y_pos_prev;
	t_master		*m;

	m = glfwGetWindowUserPointer(window);
	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
	{
		if (x_pos > x_pos_prev)
			inc_rotate_y(m);
		else if (x_pos < x_pos_prev)
			dec_rotate_y(m);
		if (y_pos > y_pos_prev)
			inc_rotate_x(m);
		else if (y_pos < y_pos_prev)
			dec_rotate_x(m);
		x_pos_prev = x_pos;
		y_pos_prev = y_pos;
	}
}

static void			framebuffer_size_callback(
	GLFWwindow *window, int width, int height)
{
	glViewport(0, 0, width, height);
	(void)window;
}

/*
** Need to cache and store current working directory
** because glfwInit() changes cwd ¯\_(ツ)_/¯
*/
int					init_open_gl(t_master *m)
{
	char			cwd[256];

	getcwd(cwd, sizeof(cwd));
	if (glfwInit() == GLFW_FALSE)
		return (ft_puterror("glfwInit() failed", NULL, -1));
	chdir(cwd);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	if (!(m->window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT,
		"Scop", NULL, NULL)))
		return (ft_puterror(ERROR_MEMORY, NULL, -1));
	glfwMakeContextCurrent(m->window);
	if (glewInit() != GLEW_OK)											// using GLEW now instead of GLAD
		return (ft_puterror("glewInit() failed", NULL, -1));
	glfwSetWindowUserPointer(m->window, m);
	glfwSetWindowAspectRatio(m->window, SCREEN_WIDTH, SCREEN_HEIGHT);
	glfwSetFramebufferSizeCallback(m->window, framebuffer_size_callback);
	glfwSetKeyCallback(m->window, key_callback);
	glfwSetCursorPosCallback(m->window, cursor_position_callback);
	glfwSetScrollCallback(m->window, scroll_callback);
	glEnable(GL_DEPTH_TEST);
	return (0);
}
