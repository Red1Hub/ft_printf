/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:51:25 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/14 16:11:07 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	printer(t_printfv *printfv, va_list ap)
{
	int	i;

	i = 0;
	while ((printfv->cursor)[0] != '\0')
	{
		if ((printfv->cursor)[0] == '%')
		{
			init_percent_flag(printfv);
			printfv->cursor++;
			if (checknfill(printfv, ap))
			{
				fill_arg(printfv, ap);
				special_printer(printfv);
				init_percent_flag(printfv);
				ft_memdel((void**)&((printfv->percent).charg));
			}
		}
		else
		{
			printf_putchar((printfv->cursor)[0], &(printfv->printed));
			(printfv->cursor)++;
		}
	}
}

void	init_gth_allgth(t_printfv *printfv)
{
	int i;

	i = 0;
	printfv->alllengths = (int*)malloc(sizeof(int) * (NBRLENGTH + 1));
	printfv->alllengths[0] = cantor('h', 'h');
	printfv->alllengths[1] = cantor('h', 1);
	printfv->alllengths[2] = cantor('l', 1);
	printfv->alllengths[3] = cantor('l', 'l');
	printfv->alllengths[4] = cantor('z', 1);
	printfv->alllengths[5] = cantor('j', 1);
	printfv->alllengths[6] = cantor('t', 1);
	printfv->alllengths[7] = cantor('L', 1);
	printfv->alllengths[8] = cantor('0', '0');
	(printfv->percent).length = cantor(1000, 1000);
}

void	init_percent_flag(t_printfv *printfv)
{
	(printfv->percent).minus = 0;
	(printfv->percent).plus = 0;
	(printfv->percent).space = 0;
	(printfv->percent).hash = 0;
	(printfv->percent).zero = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printfv	printfv;
	char		*cursortmp;

	printfv.allspecifiers = "gcsdiouxXfpbe%";
	printfv.allflags = "-+ #";
	init_gth_allgth(&printfv);
	printfv.printed = 0;
	printfv.cursor = ft_strdup(format);
	cursortmp = printfv.cursor;
	va_start(ap, format);
	printer(&printfv, ap);
	va_end(ap);
	free(printfv.alllengths);
	free(cursortmp);
	return (printfv.printed);
}
