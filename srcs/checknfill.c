/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:57:16 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 16:58:57 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		check_fill_specif(t_printfv *printfv)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (printfv->cursor[i] != '\0' && count == 0)
	{
		j = 0;
		while (printfv->allspecifiers[j] != '\0')
			if (printfv->cursor[i] == printfv->allspecifiers[j++])
			{
				count++;
				printfv->percent.specifier = printfv->allspecifiers[j - 1];
				break ;
			}
		if (!count)
			i++;
	}
	if (count == 0)
	{
		printfv->cursor += i;
		return (0);
	}
	return (1);
}

int		checknfill(t_printfv *printfv, va_list ap)
{
	if (check_fill_specif(printfv))
	{
		fill_width_precision(printfv, ap);
		fill_flags_length(printfv);
		return (1);
	}
	return (0);
}
