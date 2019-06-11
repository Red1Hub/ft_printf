/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insrt_hash_spc_pls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:48:00 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 18:00:06 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		condition_flghash(t_printfv *printfv)
{
	if ((printfv->percent.charg[0] == '0' &&
				printfv->percent.charg[1] == '\0' &&
				printfv->percent.specifier != 'p') ||
			(printfv->percent.charg[0] == '\0'
			&& printfv->percent.specifier != 'o'))
		return (1);
	return (0);
}

void	insert_flghash(t_printfv *printfv)
{
	char *tmp;

	if (condition_flghash(printfv))
		return ;
	if ((printfv->percent).hash || printfv->percent.specifier == 'p')
	{
		if ((printfv->percent).specifier == 'o')
			tmp = ft_strjoin("0", (const char*)(printfv->percent).charg);
		else if ((printfv->percent).specifier == 'x' ||
				printfv->percent.specifier == 'p')
			tmp = ft_strjoin("0x", (const char*)(printfv->percent).charg);
		else if ((printfv->percent).specifier == 'X')
			tmp = ft_strjoin("0X", (const char*)(printfv->percent).charg);
		if (strchrchr("oxpX", "\0", printfv->percent.specifier))
		{
			ft_memdel((void**)&((printfv->percent).charg));
			(printfv->percent).charg = tmp;
		}
	}
}

void	insert_flgplusspace(t_printfv *printfv)
{
	char *tmp;

	if ((printfv->percent).plus)
		return ;
	if ((printfv->percent).space &&
			strchrchr("dif", "\0", (printfv->percent).specifier))
	{
		if ((printfv->percent).charg[0] != '-')
		{
			tmp = ft_strjoin(" ", (const char*)((printfv->percent).charg + 1));
			ft_memdel((void**)&((printfv->percent).charg));
			(printfv->percent).charg = tmp;
		}
	}
}
