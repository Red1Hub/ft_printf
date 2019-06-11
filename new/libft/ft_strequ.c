/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 04:14:53 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/13 07:15:43 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	if (s1 == NULL && s2 == NULL)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i] || s2[i] == '\0')
			return (0);
		i++;
	}
	if (s2[i] != '\0')
		return (0);
	return (1);
}
