/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 23:17:21 by ashih             #+#    #+#             */
/*   Updated: 2018/10/27 21:51:47 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

static void		free_obj(t_obj *obj)
{
	ft_lstdel(&obj->v_list, (void (*)(void *, size_t))free);
	ft_lstdel(&obj->triangle_list, (void (*)(void *, size_t))free);
	ft_lstdel(&obj->vt_list, (void (*)(void *, size_t))free);
	ft_memdel((void **)&obj->v_array);
	ft_memdel((void **)&obj->vt_array);
}

/*
** glfwTerminate() will free m->window
*/

void			terminate(t_master *m)
{
	glfwTerminate();
	ft_strdel(&m->path);
	ft_memdel((void **)&m->gl_data);
	free_obj(&m->obj);
}
