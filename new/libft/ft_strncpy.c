/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:04:24 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/11 17:52:43 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t len2;
	size_t i;

	i = 0;
	len2 = ft_strlen(src);
	while (i < len2 && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (len2 < len)
	{
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (dst);
}
