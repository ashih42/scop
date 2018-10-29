/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 18:41:16 by ashih             #+#    #+#             */
/*   Updated: 2018/10/29 08:30:36 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int		validate_file_extension(char *filename, char *ext)
{
	int			filename_len;
	int			ext_len;

	filename_len = ft_strlen(filename);
	ext_len = ft_strlen(ext);
	if (filename_len >= ext_len)
	{
		filename += filename_len - ext_len;
		if (ft_strequ(filename, ext))
			return (0);
	}
	return (ft_puterror(ERROR_FILE_EXT, NULL, -1));
}

static void		init_obj(t_obj *obj)
{
	ft_bzero(obj, sizeof(t_obj));
	obj->x_min = FLT_MAX;
	obj->x_max = FLT_MIN;
	obj->y_min = FLT_MAX;
	obj->y_max = FLT_MIN;
	obj->y_min = FLT_MAX;
	obj->y_max = FLT_MIN;
}

static int		handle_line(char *line, t_obj *obj)
{
	obj->line_num++;
	if (ft_strnequ(line, "v ", 2))
		return (handle_v_line(line, obj));
	else if (ft_strnequ(line, "f ", 2))
		return (handle_f_line(line, obj));
	else if (ft_strnequ(line, "vt ", 3))
		return (handle_vt_line(line, obj));
	else if (ft_strnequ(line, "vn ", 3))
		return (handle_vn_line(line, obj));
	return (0);
}

int				parse_obj_file(char *filename, t_obj *obj)
{
	int			fd;
	char		*line;
	size_t		line_num;
	int			error;

	if (validate_file_extension(filename, ".obj"))
		return (-1);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (ft_puterror(ERROR_OPEN_FILE, filename, -1));
	init_obj(obj);
	line = NULL;
	line_num = 0;
	while (get_next_line(fd, &line) > 0)
	{
		line_num++;
		error = handle_line(line, obj);
		ft_strdel(&line);
		if (error)
			return (-1);
	}
	close(fd);
	return (0);
}
