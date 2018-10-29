/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ppm_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 00:56:18 by ashih             #+#    #+#             */
/*   Updated: 2018/10/27 23:20:56 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int				validate_ppm_max_value(int fd)
{
	char				*line;
	int					error;

	get_next_line_1b(fd, &line);
	error = !ft_strequ(line, "255");
	ft_strdel(&line);
	if (error)
		return (ft_puterror("Invalid PPM max value (only accept '255')",
			NULL, -1));
	else
		return (0);
}

static int				validate_ppm_dimensions(int fd, int *width, int *height)
{
	char				**tokens;
	char				*line;
	int					error;

	line = NULL;
	get_next_line_1b(fd, &line);
	tokens = ft_strsplit(line, ' ');
	error = ft_atoi_check(tokens[0], width) || *width <= 0 ||
		ft_atoi_check(tokens[1], height) || *height <= 0;
	ft_char_array_del(tokens);
	ft_strdel(&line);
	if (error)
		return (ft_puterror("Invalid PPM dimensions", NULL, -1));
	else
		return (0);
}

static int				validate_ppm_header(int fd)
{
	char				*line;
	int					error;

	line = NULL;
	get_next_line_1b(fd, &line);
	error = !(line && ft_strequ(line, "P6"));
	ft_strdel(&line);
	if (error)
		return (ft_puterror("Invalid PPM header (only accept 'P6')", NULL, -1));
	else
		return (0);
}

static unsigned char	*read_ppm_data(int fd, int width, int height)
{
	char				*data;
	size_t				bytes_read;
	size_t				total_size;

	total_size = sizeof(unsigned char) * (size_t)width * (size_t)height * 3;
	if (!(data = malloc(total_size)))
	{
		ft_puterror(ERROR_MEMORY, NULL, -1);
		return (NULL);
	}
	bytes_read = read(fd, data, total_size);
	if (bytes_read != total_size)
	{
		ft_puterror("Invalid PPM data", NULL, -1);
		ft_memdel((void **)&data);
		return (NULL);
	}
	return ((unsigned char *)data);
}

unsigned char			*parse_ppm_file(char *path, char *filename,
	int *width, int *height)
{
	int					fd;
	unsigned char		*data;

	if ((fd = ft_open(path, filename, O_RDONLY)) < 0)
	{
		ft_puterror(ERROR_OPEN_FILE, filename, -1);
		return (NULL);
	}
	if (validate_ppm_header(fd) || validate_ppm_dimensions(fd, width, height) ||
		validate_ppm_max_value(fd))
		return (NULL);
	data = read_ppm_data(fd, *width, *height);
	close(fd);
	return (data);
}
