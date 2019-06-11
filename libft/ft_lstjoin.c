/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 12:08:28 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/13 15:47:27 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstjoin(t_list *lst1, t_list *lst2)
{
	t_list	*wilson;

	wilson = lst1;
	while (lst1->next != NULL)
		lst1 = lst1->next;
	lst1->next = lst2;
	return (wilson);
}
