/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:27:57 by abiestro          #+#    #+#             */
/*   Updated: 2018/04/10 16:28:00 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;

	new = f(lst);
	tmp = new;
	while (lst->next && lst->next)
	{
		new->next = f(lst->next);
		lst = lst->next;
		new = new->next;
	}
	return (tmp);
}
