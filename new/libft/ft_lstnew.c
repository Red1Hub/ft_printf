/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 16:08:11 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/12 23:12:06 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;
	void		*dup;

	tmp = (t_list*)malloc(sizeof(t_list));
	if (tmp == NULL)
		return (NULL);
	if (content == NULL)
	{
		tmp->content_size = 0;
		tmp->next = NULL;
		tmp->content = NULL;
		return (tmp);
	}
	dup = (char*)malloc(content_size);
	ft_memcpy(dup, content, content_size);
	if (dup == NULL)
		return (NULL);
	if (!tmp)
		return (NULL);
	tmp->content = dup;
	tmp->content_size = content_size;
	tmp->next = NULL;
	return (tmp);
}
