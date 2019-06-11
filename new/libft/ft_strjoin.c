/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 05:01:59 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/13 07:18:34 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == NULL)
		return (NULL);
	join[len1 + len2] = '\0';
	while (i < len1 + len2)
	{
		if (i < len1)
			join[i] = s1[i];
		else
			join[i] = s2[i - len1];
		i++;
	}
	return (join);
}
