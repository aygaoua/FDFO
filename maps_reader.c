/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:43:35 by azgaoua           #+#    #+#             */
/*   Updated: 2023/09/18 16:05:36 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     ft_get_height(char *n_file)
{
    int     fd;
    int     height;

    height = 0;
    fd = open(n_file, O_RDONLY, 0);
    while (1)
    {
        if (!get_next_line(fd))
            break ;
        height++;
    }
    close(fd);
    return (height);
}
int     ft_get_width(char *n_file)
{
    int     fd;
    int     width;
    char    *line;

    fd = open(n_file, O_RDONLY, 0);
    line =  get_next_line(fd);
    width = lignes(line, ' ') - 1; // lignes() is a function from libft ft_split.c
    free(line);
    close(fd);
    return (width);
}

void    ft_fill_matrix(int *line_z, char *line)
{
    int     i;
    char    **split;

    if (!line)
        return ;
    i = 0;
    split = ft_split(line, ' ');
    while (split[i])
    {
        line_z[i] = atoi(split[i]);
        i++;
    }
    free(split);
}

void    ft_read_file(char *n_file, fdf *info)
{
    int     fd;
    char    *ligne;
    int     i;
    
    fd = open(n_file, O_RDONLY, 0);
    info->height = ft_get_height(n_file);
    info->width = ft_get_width(n_file);
    info->z_mtx = (int**)malloc(8 * (info->height + 1));
    i = 0;
    while (i <= info->height)
        info->z_mtx[i++] = (int*)malloc(4 * (info->width + 1));
    i = 0;
    while (i < info->height)
    {
        ligne = get_next_line(fd);
        ft_fill_matrix(info->z_mtx[i], ligne);
        free(ligne);
        i++;
    }
    close(fd);
    info->z_mtx[i] = NULL;
}
