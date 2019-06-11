/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 02:32:34 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/13 07:19:22 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	l;
	char			*dup;
	int				j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	l = ft_strlen(s);
	dup = (char*)malloc(sizeof(char) * (l + 1));
	if (dup == NULL)
		return (NULL);
	while (i < l)
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && j == 0)
			i++;
		while (((s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t') &&
					s[i] != '\0'))
			l--;
		dup[j++] = s[i++];
	}
	dup[j] = '\0';
	return (dup);
}
