/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 04:40:58 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/13 07:17:10 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i] || s2[i] == '\0')
			return (0);
		i++;
	}
	if (s2[i] != '\0' && s1[i] == '\0')
		return (0);
	return (1);
}
