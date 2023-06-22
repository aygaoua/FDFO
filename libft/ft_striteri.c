/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:20:27 by azgaoua           #+#    #+#             */
/*   Updated: 2022/11/18 03:42:42 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		j;

	if (!s || !f)
		return ;
	j = 0;
	while (j < ft_strlen(s))
	{
		f(j, &s[j]);
		j++;
	}
}

void	f(unsigned int k, char *g)
{
	k = 0;
	*g -= 32;
}
int		main()
{
	char tab[] = "bibabrotha";

	ft_striteri(tab, &f);
	printf("%s", tab);
}