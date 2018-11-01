/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 22:45:22 by ashih             #+#    #+#             */
/*   Updated: 2018/10/30 09:26:12 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static int			load_texture(
	t_master *m, unsigned int *texture_id, char *filename)
{
	unsigned char	*data;
	int				width;
	int				height;

	if (!(data = parse_ppm_file(m->path, filename, &width, &height)))
		return (-1);
	glGenTextures(1, texture_id);
	glBindTexture(GL_TEXTURE_2D, *texture_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	ft_memdel((void **)&data);
	return (0);
}

int					init_textures(t_master *m)
{
	return (load_texture(m, &m->texture_id[0], TEX_FILE_0) ||
		load_texture(m, &m->texture_id[1], TEX_FILE_1) ||
		load_texture(m, &m->texture_id[2], TEX_FILE_2) ||
		load_texture(m, &m->texture_id[3], TEX_FILE_3) ||
		load_texture(m, &m->texture_id[4], TEX_FILE_4) ||
		load_texture(m, &m->texture_id[5], TEX_FILE_5));
}
