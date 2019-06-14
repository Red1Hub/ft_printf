/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_uzeros_spec_g.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:23:23 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 14:50:05 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		spec_g_cond(char *str)
{
	int i;

	i = 0;
	while (str[i] == '0' || str[i] == '.' || str[i] == '+')
		i++;
	if (i == ft_strlen(str))
		return (0);
	else
		return (1);
}

void	rm_uzeros_spec_g(char **str, int tmpf)
{
	int		i;
	char	*strtmp;
	char	*strtmp0;
	int		condition;

	strtmp0 = NULL;
	condition = 0;
	i = ft_strlen(str[0]) - 1;
	while (i > 1 && !condition)
		condition = cond((str[0][i--] == 'e'), 1, 0);
	if (condition)
		strtmp0 = ft_strsub(str[0], i + 1, ft_strlen(*str) - i);
	else
		i = ft_strlen(str[0]) - 1;
	while (i > 1 && (str[0][i] == '0' || (str[0][i] == '.' && !tmpf)))
		i--;
	strtmp = ft_strsub(str[0], 0, i + 1);
	free(*str);
	if (strtmp0 && ((str[0] = ft_strjoin(strtmp, strtmp0)) || 1))
	{
		free(strtmp0);
		free(strtmp);
	}
	else
		str[0] = strtmp;
}
