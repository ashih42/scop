/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashih <ashih@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 21:24:39 by ashih             #+#    #+#             */
/*   Updated: 2018/10/24 21:25:04 by ashih            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		dec_translate_x(t_master *m)
{
	m->translate_x -= TRANSLATE_INC;
}

void		dec_translate_y(t_master *m)
{
	m->translate_y -= TRANSLATE_INC;
}

void		dec_translate_z(t_master *m)
{
	m->translate_z -= TRANSLATE_INC;
}
