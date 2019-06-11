/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_strjoin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:21:10 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 15:22:01 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	s_strjoin_frii(char **s1, char **s2, char **joinresult, int a)
{
	if (joinresult[0])
		free(joinresult[0]);
	if (a == 0)
	{
		free(s1[0]);
		free(s2[0]);
	}
	else if (a == 1)
		free(s1[0]);
	else if (a == 2)
		free(s2[0]);
}

void	s_strjoin(char **s1, char **s2, char **joinresult, int a)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*join;

	if (s1[0] == NULL || s2[0] == NULL)
		return ;
	i = 0;
	len1 = ft_strlen(s1[0]);
	len2 = ft_strlen(s2[0]);
	join = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == NULL)
		return ;
	join[len1 + len2] = '\0';
	while (i < len1 + len2)
	{
		if (i < len1)
			join[i] = s1[0][i];
		else
			join[i] = s2[0][i - len1];
		i++;
	}
	s_strjoin_frii(s1, s2, joinresult, a);
	joinresult[0] = join;
}
