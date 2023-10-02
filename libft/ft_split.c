/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 23:04:20 by azgaoua           #+#    #+#             */
/*   Updated: 2023/10/02 02:37:39 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	lignes(const char *s, char c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i++;
			l++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (l + 1);
}

static char	**freeme(char **s, size_t i)
{
	while (i >= 0 && s[i] != NULL)
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**sp;

	i = 0;
	if (!s)
		return (NULL);
	sp = malloc(8 * lignes(s, c));
	if (!sp)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (j != 0)
			sp[i++] = ft_substr(s, 0, j);
		if (j != 0 && !sp[i - 1])
			return (freeme(sp, i - 1));
		s += j;
	}
	sp[i] = NULL;
	return (sp);
}
