/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:21:50 by azgaoua           #+#    #+#             */
/*   Updated: 2023/06/22 19:40:23 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int k, void *inf)
{
    printf("%d", k);
    return (0);
}

int main(int ac, char **av)
{
    fdf *info;
    int i;
    int j;
    
    info = (fdf*)malloc(sizeof(fdf));
    ft_read_file(av[1], info);
    i = 0;
    while (i < info->height)
    {
        j = 0;
        while (j < info->width)
        {
            printf("%3d", info->z_mtx[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
