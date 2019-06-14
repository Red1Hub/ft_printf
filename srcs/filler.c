/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:59:25 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 17:54:12 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	modify_precision_precision0(t_printfv *printfv)
{
	int i;

	i = 0;
	if (printfv->percent.precision > 2147483647 ||
			printfv->percent.precision < 0)
	{
		printfv->percent.precision = 0;
		if (printfv->percent.specifier == 'f')
			printfv->percent.precision = 6;
	}
	if (printfv->percent.width > 2147483647 || printfv->percent.width < 0)
		printfv->percent.width = 0;
	if (!printfv->percent.precision)
	{
		while (printfv->cursor[i] != printfv->percent.specifier)
			if (printfv->cursor[i++] == '.')
			{
				printfv->percent.precision0 = 1;
			}
		if (printfv->percent.specifier == 'f' && !printfv->percent.precision0)
			printfv->percent.precision = 6;
	}
}

int		fill_width_prec(t_printfv *printfv, va_list ap, int i)
{
	if (printfv->cursor[i] == '*' && printfv->cursor[i - 1] != '.')
		printfv->percent.width = va_arg(ap, int);
	else if (printfv->cursor[i] == '*' && printfv->cursor[i - 1] == '.')
		printfv->percent.precision = va_arg(ap, int);
	return (1);
}

void	fill_width_precision(t_printfv *printfv, va_list ap)
{
	int i;

	i = 0;
	(printfv->percent).width = 0;
	(printfv->percent).precision = 0;
	printfv->percent.precision0 = 0;
	while (printfv->cursor[i] != printfv->percent.specifier)
	{
		if (ft_isdigit(printfv->cursor[i]) && printfv->cursor[i - 1] != '.')
		{
			(printfv->percent).width = ft_atoi(printfv->cursor + i);
			while (ft_isdigit(printfv->cursor[i]))
				i++;
		}
		else if (ft_isdigit(printfv->cursor[i]) &&
				printfv->cursor[i - 1] == '.')
		{
			(printfv->percent).precision = ft_atoi(printfv->cursor + i);
			while (ft_isdigit(printfv->cursor[i]))
				i++;
		}
		else if (fill_width_prec(printfv, ap, i))
			i++;
	}
	modify_precision_precision0(printfv);
}

void	fill_flag_zero(t_printfv *printf, int j)
{
	int i;

	i = 0;
	while (printf->cursor[i] != printf->percent.specifier)
	{
		if (ft_isdigit(printf->cursor[i]) && printf->cursor[i] != '0')
			break ;
		else if (printf->cursor[i] == '0')
		{
			if ((printf->percent).minus == 0 &&
					((!printf->percent.precision &&
					!printf->percent.precision0) ||
					(printf->percent.specifier == 'f')))
				(printf->percent).zero = 1;
		}
		i++;
	}
}

void	fill_flags_length(t_printfv *printfv)
{
	int i;
	int k;
	int l;
	int j;

	i = 0;
	j = 0;
	while (printfv->cursor[i] != (printfv->percent).specifier)
	{
		k = cantor(printfv->cursor[i - 1], printfv->cursor[i]);
		l = cantor(printfv->cursor[i], 1);
		if (printfv->cursor[i] == '-')
			(printfv->percent).minus = 1;
		if (printfv->cursor[i] == '+')
			(printfv->percent).plus = 1;
		if (printfv->cursor[i] == ' ')
			(printfv->percent).space = 1;
		if (printfv->cursor[i++] == '#')
			(printfv->percent).hash = 1;
		if (strtablechr(printfv->alllengths, l))
			(printfv->percent).length = l;
		if (strtablechr(printfv->alllengths, k))
			(printfv->percent).length = k;
	}
	fill_flag_zero(printfv, j);
}
