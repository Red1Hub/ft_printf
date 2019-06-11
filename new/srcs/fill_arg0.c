/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:50:09 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 20:49:02 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	f_ll(t_printfv *printfv, va_list ap)
{
	char *stringa;
	char *stringb;

	stringa = "di";
	stringb = "ouxX";
	if (strchrchr(stringa, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, long long int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
	else if (strchrchr(stringb, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg =
			ft_itoa_base(va_arg(ap, unsigned long long),
					ltrtobs((printfv->percent).specifier),
					(printfv->percent).specifier, printfv);
	}
}

void	f_nonee(t_printfv *printfv, va_list ap)
{
	int tmpf;
	int	tmpf0;

	if (strchrchr("fe", "\0", (printfv->percent).specifier))
	{
		tmpf0 = (printfv->percent.specifier == 'e') ? 1 : 0;
		tmpf = printfv->percent.precision + printfv->percent.hash;
		(printfv->percent).charg = floaki(va_arg(ap, double),
				(printfv->percent).precision, tmpf, tmpf0);
	}
	else if (printfv->percent.specifier == 'g')
		f_nonee_l_g(printfv, ap);
	else if ((printfv->percent).specifier == 'c')
	{
		printfv->percent.charg = ft_memalloc(2);
		printfv->percent.charg[0] = va_arg(ap, int);
	}
	else if ((printfv->percent).specifier == 's')
	{
		(printfv->percent).charg = ft_strdup(va_arg(ap, char*));
		if (printfv->percent.charg == NULL)
			printfv->percent.charg = ft_strdup("(null)");
	}
}

void	f_none(t_printfv *printfv, va_list ap)
{
	if (strchrchr("di", "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
	else if (strchrchr("ouxX", "\0", (printfv->percent).specifier))
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, unsigned int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	else if (printfv->percent.specifier == '%')
	{
		printfv->percent.charg = ft_memalloc(2);
		printfv->percent.charg[0] = '%';
	}
	else if ((printfv->percent).specifier == 'p')
		(printfv->percent).charg =
			ft_itoa_base((long long int)va_arg(ap, void*), 16, 'x', printfv);
	else if (printfv->percent.specifier == 'b')
		printfv->percent.charg = grep_mem(va_arg(ap, double));
	else
		f_nonee(printfv, ap);
}

void	f_lll(t_printfv *printfv, va_list ap)
{
	int tmpf;
	int tmpf0;

	if (strchrchr("fe", "\0", (printfv->percent).specifier))
	{
		tmpf0 = (printfv->percent.specifier == 'e') ? 1 : 0;
		tmpf = printfv->percent.precision + printfv->percent.hash;
		(printfv->percent).charg =
			floaki(va_arg(ap, long double),
			(printfv->percent).precision, tmpf, tmpf0);
	}
	else if (printfv->percent.specifier == 'b')
		printfv->percent.charg = grep_mem(va_arg(ap, long double));
	else if (printfv->percent.specifier == 'g')
		f_lll_g(printfv, ap);
}

void	fill_arg(t_printfv *printfv, va_list ap)
{
	if ((printfv->percent).length == cantor(1000, 1000))
		f_none(printfv, ap);
	else if ((printfv->percent).length == cantor('h', 'h'))
		f_hh(printfv, ap);
	else if ((printfv->percent).length == cantor('h', 1))
		f_h(printfv, ap);
	else if ((printfv->percent).length == cantor('l', 1))
		f_l(printfv, ap);
	else if ((printfv->percent).length == cantor('l', 'l'))
		f_ll(printfv, ap);
	else if ((printfv->percent).length == cantor('L', 1))
		f_lll(printfv, ap);
}
