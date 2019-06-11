/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:41:17 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/14 16:01:47 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, size_t data_size)
{
	t_list	*lst;
	int		diff;

	if (begin_list == NULL)
		return (NULL);
	lst = begin_list;
	while (lst)
	{
		while ((diff = lst->content_size - data_size) && lst->next)
			lst = lst->next;
		if (!lst)
			return (NULL);
		if (!(ft_memcmp(data_ref, lst->content, lst->content_size)))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
