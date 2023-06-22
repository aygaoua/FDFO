/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:18:13 by azgaoua           #+#    #+#             */
/*   Updated: 2022/12/03 09:18:15 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unbr(unsigned int n, int *j)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, j);
		ft_putnbr(n % 10, j);
	}
	else
		ft_putchar((char)(n + 48), j);
}
