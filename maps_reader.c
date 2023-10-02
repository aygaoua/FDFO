/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:43:35 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/02 15:17:43 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_height(char *n_file)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	fd = open(n_file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		free(line);
		height++;
	}
	close(fd);
	return (height);
}

int	ft_get_width(char *n_file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(n_file, O_RDONLY);
	line = get_next_line(fd);
	width = lignes(line, ' ') - 1;
	free(line);
	close(fd);
	return (width);
}

void	ft_fill_mtx(int **line_z, char *line, t_fdf *info)
{
	int		i;
	char	**split;
	int		num;

	i = 0;
	split = ft_split(line, ' ');
	free(line);
	*line_z = (int *)malloc(info->width * sizeof(int));
	if (*line_z == NULL)
		exit(1);
	while (split[i]) 
	{
		num = ft_atoi(split[i]);
		if (num == 0 && split[i][0] != '0' && split[i][0] != '\n')
		{
			ft_printf("Invalid integer: \"%s\"\n", split[i]);
			free(*line_z);
			exit(1);
		}
		(*line_z)[i] = num;
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_read_file(char *n_file, t_fdf *info)
{
	int		fd;
	char	*ligne;
	int		i;

	info->height = ft_get_height(n_file);
	info->width = ft_get_width(n_file);
	if (info->height <= 0 || info->width <= 0)
	{
		ft_printf("no data found. !!\n");
		exit (0);
	}
	info->z_mtx = (int **)malloc(8 * (info->height + 1));
	if (info->z_mtx == NULL)
		exit(0);
	i = 0;
	fd = open(n_file, O_RDONLY);
	while (i < info->height)
	{
		ligne = get_next_line(fd);
		if (ligne == NULL)
			break ;
		ft_fill_mtx(&info->z_mtx[i], ligne, info);
		i++;
	}
	close(fd);
}
