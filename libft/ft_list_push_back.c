/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 16:16:35 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/13 20:01:22 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_back(t_list **begin_list, void *data, size_t data_size)
{
	t_list *tmp;

	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_lstnew(data, data_size);
}
