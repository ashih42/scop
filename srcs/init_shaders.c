/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shaders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 00:59:51 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 09:58:19 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int			join_lines(int fd, char **str)
{
	char			*temp;
	char			buffer[4096 + 1];
	int				n_bytes;

	while ((n_bytes = read(fd, buffer, 4096)))
	{
		if (n_bytes < 0)
			return (ft_puterror("read() failed", NULL, -1));
		buffer[n_bytes] = '\0';
		temp = *str;
		*str = ft_strjoin(temp, buffer);
		ft_strdel(&temp);
		if (!*str)
			return (ft_puterror(ERROR_MEMORY, NULL, -1));
	}
	return (0);
}

static char			*load_shader(char *filename, char *path)
{
	int				fd;
	char			*str;

	if ((fd = ft_open(path, filename, O_RDONLY)) < 0)
	{
		ft_puterror(ERROR_OPEN_FILE, filename, -1);
		return (NULL);
	}
	if (!(str = ft_strnew(0)))
	{
		ft_puterror(ERROR_MEMORY, NULL, -1);
		return (NULL);
	}
	join_lines(fd, &str);
	close(fd);
	return (str);
}

static int			compile_shader(unsigned int *id, GLenum type,
	char *file, char *path)
{
	char			*shader_str;
	int				success;
	char			info_log[512];

	*id = glCreateShader(type);
	if (!(shader_str = load_shader(file, path)))
		return (-1);
	glShaderSource(*id, 1, (const char *const *)&shader_str, NULL);
	glCompileShader(*id);
	glGetShaderiv(*id, GL_COMPILE_STATUS, &success);
	ft_strdel(&shader_str);
	if (!success)
	{
		glGetShaderInfoLog(*id, 512, NULL, info_log);
		return (ft_puterror(ERROR_SHADER, info_log, -1));
	}
	return (0);
}

static int			link_shader(unsigned int vs, unsigned int fs, t_master *m)
{
	int				success;
	char			info_log[512];

	m->shader_id = glCreateProgram();
	glAttachShader(m->shader_id, vs);
	glAttachShader(m->shader_id, fs);
	glLinkProgram(m->shader_id);
	glGetProgramiv(m->shader_id, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(m->shader_id, 512, NULL, info_log);
		return (ft_puterror(ERROR_SHADER, info_log, -1));
	}
	glUseProgram(m->shader_id);
	glDeleteShader(vs);
	glDeleteShader(fs);
	return (0);
}

int					init_shaders(t_master *m)
{
	unsigned int	vs;
	unsigned int	fs;
	int				error;

	error = compile_shader(&vs, GL_VERTEX_SHADER,
			"shaders/vertex_shader.glsl", m->path) ||
		compile_shader(&fs, GL_FRAGMENT_SHADER,
			"shaders/fragment_shader.glsl", m->path) ||
		link_shader(vs, fs, m);
	if (error)
		return (-1);
	m->percent_texture_loc = glGetUniformLocation(m->shader_id, "percent_texture");
	m->transform_matrix_loc = glGetUniformLocation(m->shader_id, "transform_matrix");
	m->is_grayscale_loc = glGetUniformLocation(m->shader_id, "is_grayscale");
	m->is_smooth_color_loc = glGetUniformLocation(m->shader_id, "is_smooth_color");
	m->is_default_uv_loc = glGetUniformLocation(m->shader_id, "is_default_uv");
	m->light_position_loc = glGetUniformLocation(m->shader_id, "light_position");
	m->percent_specular_loc = glGetUniformLocation(m->shader_id, "percent_specular");
	m->is_light_on_loc = glGetUniformLocation(m->shader_id, "is_light_on");
	m->is_my_normal_loc = glGetUniformLocation(m->shader_id, "is_my_normal");
	return (0);
}
