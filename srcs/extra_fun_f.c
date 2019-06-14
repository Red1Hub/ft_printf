/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:22:13 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/12 22:13:26 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	rm_uzeros(char **str)
{
	int		i;
	char	*strtmp;

	i = 0;
	if (str[0][0] != '0')
		return ;
	while (str[0][i] == '0')
		i++;
	strtmp = ft_strsub(str[0], i, ft_strlen(str[0]) - i);
	free(str[0]);
	str[0] = strtmp;
}

char	*infinity(int sign)
{
	char *result;

	if (sign)
		result = ft_strdup("-inf");
	else
		result = ft_strdup("+inf");
	return (result);
}

char	*nani(void)
{
	char *result;

	result = ft_strdup("nan");
	return (result);
}
