/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 20:05:58 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/14 15:59:49 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*lst;
	unsigned int	i;

	if (begin_list == NULL || nbr == 0)
		return (NULL);
	i = 0;
	lst = begin_list;
	while (lst->next && i < nbr - 1)
	{
		lst = lst->next;
		i++;
	}
	if (i == nbr - 1)
		return (lst);
	return (NULL);
}
