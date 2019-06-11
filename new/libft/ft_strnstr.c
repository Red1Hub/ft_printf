/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:19:00 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/09 03:53:20 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	j = 0;
	i = 0;
	tmp = (char*)h;
	if (needle[0] == '\0')
		return (tmp);
	while (h[i] != '\0' && i < len)
	{
		if (h[i] == needle[0])
		{
			while (h[i + j] == needle[j] && h[i + j] != '\0' && i + j < len)
			{
				j++;
				if (needle[j] == '\0')
					return (tmp + i);
			}
		}
		i++;
	}
	return (NULL);
}
