/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:21:50 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/18 13:36:27 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_deal_key(int k, fdf *info)
{
    printf("Key : %d\n", k);
    if (k == 53)
        exit(0);
    if (k == 126)
        info->sh_y -= 100;
    if (k == 125)
        info->sh_y += 100;
    if (k == 123)
        info->sh_x -= 100;
    if (k == 124)
        info->sh_x += 100;
    if ((k == 69 || k == 24))
        info->zoom += 1;
    if ((k == 78 || k == 27))
        info->zoom /= 1.1;
    if (k == 257)
        info->z += 1;
    mlx_clear_window(info->mlx_ptr, info->win_ptr);
    mlx_destroy_image(info->mlx_ptr, info->mlx.img);
    ft_draw(info);  
    return (0);
}


int main(int ac, char **av)
{
    fdf *info;
    
    if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".fdf", 4) || open(av[1], O_RDONLY, 0) == -1) // check if file is .fdf or not
    {
        printf("Do this : ./fdf <filename>\n");
        return (0);
    }
    info = (fdf*)malloc(sizeof(fdf));
    ft_read_file(av[1], info);
	info->mlx_ptr = mlx_init();
	info->win_ptr = mlx_new_window(info->mlx_ptr, 1920, 1080, "fdf");
    info->mlx.img = mlx_new_image(info->mlx_ptr, 1920, 1080);
	info->mlx.addr = mlx_get_data_addr(info->mlx.img, &info->mlx.bits_per_pixel, &info->mlx.line_length,
								&info->mlx.endian);
    info->zoom = 20;
    ft_draw(info);
	mlx_key_hook(info->win_ptr, ft_deal_key, info);
    mlx_loop(info->mlx_ptr);
    return (0);
}
