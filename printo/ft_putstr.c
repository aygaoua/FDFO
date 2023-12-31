/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:17:13 by azgaoua           #+#    #+#             */
/*   Updated: 2022/12/04 23:43:14 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *j)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", j);
		return ;
	}
	i = 0;
	while (s[i] && *j != -1)
		ft_putchar(s[i++], j);
}
