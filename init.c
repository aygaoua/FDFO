/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:54:17 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/01 23:19:34 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_inits(t_cordnt *cordnt, int *z, int *z0, t_fdf *info)
{
	*z = info->z_mtx[(int)cordnt->y][(int)cordnt->x];
	*z0 = info->z_mtx[(int)cordnt->y0][(int)cordnt->x0];
	if ((*z0 || *z))
		info->color = 0X00FFFF;
	else
		info->color = 0XFFFFFF;
	ft_zoom(&cordnt->x, &cordnt->y, info);
	ft_zoom(&cordnt->x0, &cordnt->y0, info);
	ft_isometric(&cordnt->x, &cordnt->y, *z, info);
	ft_isometric(&cordnt->x0, &cordnt->y0, *z0, info);
	ft_shift(&cordnt->x, &cordnt->y, info);
	ft_shift(&cordnt->x0, &cordnt->y0, info);
}
