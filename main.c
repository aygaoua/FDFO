/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:21:50 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/02 15:07:10 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf		*info;
	int			fd;

	fd = open(av[1], O_RDONLY, 0);
	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4) || \
		fd < 0)
	{
		ft_printf("Do this : ./fdf <filename.fdf(with read permission)>\n");
		return (0);
	}
	close(fd);
	info = (t_fdf *)malloc(sizeof(t_fdf));
	if (info == NULL)
		exit(1);
	ft_read_file(av[1], info);
	ft_init_struct(info);
	ft_draw(info);
	mlx_key_hook(info->win_ptr, ft_deal_key, info);
	mlx_hook(info->win_ptr, 17, 0, ft_exit_cross, info);
	mlx_loop(info->mlx_ptr);
	return (0);
}

int	ft_exit_cross(void *g)
{
	g = NULL;
	ft_printf("good bye, have a nice day !!");
	exit(0);
}

int	ft_deal_key(int k)
{
	if (k == 53)
	{
		ft_printf("good bye, have a nice day !!");
		exit(0);
	}
	return (0);
}

void	ft_init_struct(t_fdf *info)
{
	float	ratio_w;
	float	ratio_h;

	ratio_w = (float )(1920 / info->width);
	ratio_h = (float )(1080 / info->height);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 1920, 1080, "fdf");
	info->mlx.img = mlx_new_image(info->mlx_ptr, 1920, 1080);
	info->mlx.addr = mlx_get_data_addr(info->mlx.img, \
	&info->mlx.bits_per_pixel, &info->mlx.line_length, &info->mlx.endian);
	info->tita = TITA;
	if ((float )(info->width / info->height) > (float )(16 / 9))
		info->zoom = (int )(ratio_w);
	else
		info->zoom = (int )(ratio_h) / 1.75;
}
