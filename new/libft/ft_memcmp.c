/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 21:51:28 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/11 01:17:35 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		tmp;

	i = 0;
	while (i < n)
	{
		if (((char*)s1)[i] != ((char*)s2)[i])
		{
			tmp = (unsigned char)((char*)s1)[i] - (unsigned char)((char*)s2)[i];
			return (tmp);
		}
		i++;
	}
	return (0);
}
