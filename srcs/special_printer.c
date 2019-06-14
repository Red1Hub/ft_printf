/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:20:09 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 16:23:15 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	modify_flagzerospace(t_printfv *printfv)
{
	if (!ft_strcmp(printfv->percent.charg + 1, "inf"))
		printfv->percent.zero = 0;
	if (!ft_strcmp(printfv->percent.charg, "nan"))
		printfv->percent.zero = 0;
	if (!ft_strcmp(printfv->percent.charg, "nan"))
		printfv->percent.space = 0;
}

void	special_printerr(t_printfv *printfv)
{
	if (strchrchr("efg", "\0", printfv->percent.specifier))
	{
		modify_flagzerospace(printfv);
		insert_flgplusspace(printfv);
		insert_flgminuszeroprint(printfv);
	}
	else if (printfv->percent.specifier == 's')
	{
		insert_precision(printfv);
		insert_flgminuszeroprint(printfv);
	}
	else if (strchrchr("c%", "\0", printfv->percent.specifier))
		insert_flgminuszeroprint(printfv);
	else if (printfv->percent.specifier == 'b')
	{
		printfv->percent.plus = 0;
		insert_flgminuszeroprint(printfv);
	}
	else
	{
		insert_flghash(printfv);
		insert_flgminuszeroprint(printfv);
	}
}

void	special_printer(t_printfv *printfv)
{
	char *strtmp;

	if (strchrchr("uoxXp", "\0", printfv->percent.specifier))
		if (printfv->percent.charg[0] == '+' ||
			printfv->percent.charg[0] == '-')
		{
			strtmp = ft_strdup(printfv->percent.charg + 1);
			free(printfv->percent.charg);
			printfv->percent.charg = strtmp;
		}
	if (strchrchr("diouxX", "\0", printfv->percent.specifier))
	{
		insert_flghash(printfv);
		insert_precision(printfv);
		insert_flgplusspace(printfv);
		insert_flgminuszeroprint(printfv);
	}
	else
		special_printerr(printfv);
	while (printfv->cursor[0] != printfv->percent.specifier)
		printfv->cursor++;
	printfv->cursor++;
}
