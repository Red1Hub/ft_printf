/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 20:08:36 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/12 16:48:41 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *wilson;

	tmp = *alst;
	wilson = *alst;
	while ((*alst)->next != NULL)
	{
		tmp = (*alst)->next;
		ft_lstdelone(alst, del);
		alst = &wilson;
		wilson = tmp;
	}
	ft_lstdelone(alst, del);
	alst = NULL;
}
