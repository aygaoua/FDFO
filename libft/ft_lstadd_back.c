/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azgaoua <azgaoua@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 12:19:48 by azgaoua           #+#    #+#             */
/*   Updated: 2022/11/18 17:07:47 by azgaoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst)
		return ;
	last = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (last -> next != NULL)
			last = last -> next;
		last -> next = new;
	}
}

int main()
{
	t_list	*head;
	t_list *a = ft_lstnew(ft_strdup("biba"));
	t_list *b = ft_lstnew(ft_strdup("khawa"));
	t_list	*c = ft_lstnew(ft_strdup("mossa7i7"));
	head = a;
	a -> next = b;
	b -> next = NULL;
	ft_lstadd_back(&a, c);
	while (head != NULL)
	{
		printf("%s || ", head -> content);
		head = head -> next;
	}
}