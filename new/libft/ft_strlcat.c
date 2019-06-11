/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:46:09 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/06 17:23:30 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	len2;

	len = 0;
	i = 0;
	len2 = 0;
	while (dst[len] != '\0')
	{
		len++;
	}
	while (src[len2] != '\0')
		len2++;
	while (src[i] != '\0' && size > len && i < (size - 1 - len))
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = '\0';
	if (size < len)
	{
		len2 = len2 + size;
		len = 0;
	}
	return (len + len2);
}
