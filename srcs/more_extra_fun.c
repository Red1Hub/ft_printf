/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_extra_fun.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:33:51 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 16:21:11 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		cond(int condition, int tru, int flse)
{
	if (condition)
		return (tru);
	else
		return (flse);
	return (0);
}

void	rm_uzeros_charsum(char **str, char **str1, char **str2)
{
	rm_uzeros(str);
	ft_memdel((void**)str1);
	ft_memdel((void**)str2);
}
