/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arg1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:50:58 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 16:18:53 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	f_nonee_l_g(t_printfv *printfv, va_list ap)
{
	int			tmpf;
	char		*s0;
	char		*s1;
	long double	f;

	tmpf = printfv->percent.precision + printfv->percent.hash;
	f = va_arg(ap, double);
	s0 = floaki(f, printfv->percent.precision, tmpf, 0);
	s1 = floaki(f, printfv->percent.precision, tmpf, 1);
	rm_uzeros_spec_g(&s0, tmpf);
	rm_uzeros_spec_g(&s1, tmpf);
	if (ft_strlen(s1) > ft_strlen(s0) && spec_g_cond(s0))
	{
		printfv->percent.charg = s0;
		free(s1);
	}
	else
	{
		printfv->percent.charg = s1;
		free(s0);
	}
}

void	f_lll_g(t_printfv *printfv, va_list ap)
{
	int			tmpf;
	char		*s0;
	char		*s1;
	long double	f;

	tmpf = printfv->percent.precision + printfv->percent.hash;
	f = va_arg(ap, long double);
	s0 = floaki(f, printfv->percent.precision, tmpf, 0);
	s1 = floaki(f, printfv->percent.precision, tmpf, 1);
	rm_uzeros_spec_g(&s0, tmpf);
	rm_uzeros_spec_g(&s1, tmpf);
	if (ft_strlen(s1) > ft_strlen(s0) && spec_g_cond(s0))
	{
		printfv->percent.charg = s0;
		free(s1);
	}
	else
	{
		printfv->percent.charg = s1;
		free(s0);
	}
}

void	f_hh(t_printfv *printfv, va_list ap)
{
	char *stringa;
	char *stringb;

	stringa = "di";
	stringb = "ouxX";
	if (strchrchr(stringa, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base((signed char)va_arg(ap, int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
	else if (strchrchr(stringb, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base((unsigned char)va_arg(ap, int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
}

void	f_h(t_printfv *printfv, va_list ap)
{
	char *stringa;
	char *stringb;

	stringa = "di";
	stringb = "ouxX";
	if (strchrchr(stringa, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base((short int)va_arg(ap, int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
	else if (strchrchr(stringb, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg =
			ft_itoa_base((unsigned short)va_arg(ap, int),
					ltrtobs((printfv->percent).specifier),
					(printfv->percent).specifier, printfv);
	}
}

void	f_l(t_printfv *printfv, va_list ap)
{
	int		tmpf;
	int		tmpf0;

	if (strchrchr("di", "\0", (printfv->percent).specifier))
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, long int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	else if (strchrchr("ouxX", "\0", (printfv->percent).specifier))
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, unsigned long int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	else if (strchrchr("fe", "\0", printfv->percent.specifier))
	{
		tmpf0 = 0;
		if (printfv->percent.specifier == 'e')
			tmpf0 = 1;
		tmpf = printfv->percent.precision + printfv->percent.hash;
		(printfv->percent).charg =
			floaki(va_arg(ap, double), (printfv->percent).precision,
					tmpf, tmpf0);
	}
	else if (printfv->percent.specifier == 'g')
		f_nonee_l_g(printfv, ap);
	else if (printfv->percent.specifier == 'b')
		printfv->percent.charg = grep_mem(va_arg(ap, double));
}
