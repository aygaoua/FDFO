/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uphexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:18:28 by azgaoua           #+#    #+#             */
/*   Updated: 2022/12/03 09:18:31 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uphexa(unsigned int n, int *j)
{
	if (n >= 16)
	{
		ft_uphexa(n / 16, j);
		ft_uphexa(n % 16, j);
	}
	else if (n < 10)
		ft_putchar(n + 48, j);
	else
		ft_putchar(n + 55, j);
}
