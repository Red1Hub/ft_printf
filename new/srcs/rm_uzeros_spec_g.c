/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_uzeros_spec_g.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 18:23:23 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 20:54:17 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	rm_uzeros_spec_g(char **str)
{
	int		i;
	char	*strtmp;
	char	*strtmp0;
	int		condition;

	strtmp0 = NULL;
	condition = 0;
	i = ft_strlen(str[0]) - 1;
	while (i > 1 && !condition)
		condition = (str[0][i--] == 'e') ? 1 : 0;
	if (condition)
		strtmp0 = ft_strsub(str[0], i + 1, ft_strlen(*str) - i);
	else
		i = ft_strlen(str[0]) - 1;
	while (i > 1 && (str[0][i] == '0' || str[0][i] == '.'))
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
