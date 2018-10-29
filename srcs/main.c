/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 23:04:53 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 09:46:07 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		spin_randomly(t_master *m)
{
	static int	x_spin_direction;
	static int	y_spin_direction;
	static int	z_spin_direction;

	if (rand() % 1000 == 1)
		x_spin_direction = !x_spin_direction;
	if (rand() % 1000 == 1)
		y_spin_direction = !y_spin_direction;
	if (rand() % 1000 == 1)
		z_spin_direction = !z_spin_direction;
	if (x_spin_direction)
		inc_rotate_x(m);
	else
		dec_rotate_x(m);
	if (y_spin_direction)
		inc_rotate_y(m);
	else
		dec_rotate_y(m);
	if (z_spin_direction)
		inc_rotate_z(m);
	else
		dec_rotate_z(m);
}

void			loop(t_master *m)
{
	while (!glfwWindowShouldClose(m->window))
	{
		process_key_held_input(m);
		glfwSetWindowTitle(m->window, m->is_perspective ?
			"scop (Perspective)" : "scop (Orthographic)");
		if (m->is_spinning)
			spin_randomly(m);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		set_transform_matrix(m);
		glDrawArrays(GL_TRIANGLES, 0, m->obj.triangle_count * 3);
		glfwSwapBuffers(m->window);
		glfwPollEvents();
	}
}

int				main(int argc, char **argv)
{
	t_master	m;

	if (argc != 2)
		return (ft_puterror(ERROR_USAGE, NULL, EXIT_FAILURE));
	srand(time(NULL));
	ft_bzero(&m, sizeof(t_master));
	if (!init_argv0_path(argv[0], &m.path) &&
		!parse_obj_file(argv[1], &m.obj) &&
		!generate_gl_data(&m, &m.obj) &&
		!init_open_gl(&m) && !init_shaders(&m) &&
		!init_vertex_objects(&m) && !init_textures(&m))
	{

		// print_triangles(&m.obj);

		reset_scop_params(&m);
		loop(&m);
	}
	terminate(&m);
	return (EXIT_SUCCESS);
}
