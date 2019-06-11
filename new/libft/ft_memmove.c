/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 20:38:49 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/11 15:27:44 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*tmp;

	tmp = (char*)src;
	i = 0;
	while (i < len)
	{
		if (src + i == dst)
			tmp = ft_strdup(((char*)src));
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char*)dst)[i] = tmp[i];
		i++;
	}
	return (dst);
}
