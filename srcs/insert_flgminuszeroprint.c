/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:29:42 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 14:47:56 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	prec_floatzero(t_printfv *printfv, char *tmp)
{
	printf_putstr(tmp, &(printfv->printed));
	if ((printfv->percent).plus ||
			(printfv->percent).charg[0] != '+' ||
			strchrchr("cs", "\0", printfv->percent.specifier))
		printf_putstr((const char*)(printfv->percent).charg,
				&(printfv->printed));
	else
		printf_putstr(printfv->percent.charg + 1, &(printfv->printed));
}

void	nprec_width_zero(t_printfv *printfv, char *tmp)
{
	char *tmp0;

	if (printfv->percent.zero && ((printfv->percent).plus ||
				(printfv->percent).charg[0] != '+'))
	{
		tmp0 = str_sub_digit(&printfv->percent.charg, printfv);
		printf_putstr(tmp0, &(printfv->printed));
		if (tmp0)
			ft_memdel((void**)&tmp0);
		printf_putstr(tmp, &(printfv->printed));
		printf_putstr((const char*)(printfv->percent).charg,
				&(printfv->printed));
	}
	else
	{
		printf_putstr(tmp, &(printfv->printed));
		if (printfv->percent.charg[0] == '+' &&
				!printfv->percent.plus &&
				!strchrchr("cs", "\0", printfv->percent.specifier))
			printf_putstr((const char*)(printfv->percent).charg + 1,
					&(printfv->printed));
		else
			printf_putstr((const char*)(printfv->percent).charg,
					&(printfv->printed));
	}
}

char	*width(t_printfv *printfv, int j, char c)
{
	char	*tmp;
	int		k;

	if (!printfv->percent.plus && printfv->percent.charg[0] == '+' &&
			!strchrchr("cs", "\0", printfv->percent.specifier))
		j++;
	k = j;
	if (j > 0)
	{
		tmp = (char*)malloc(sizeof(char) * (k + 1));
		tmp[k] = '\0';
		while (k > 0)
			tmp[--k] = c;
	}
	else
		tmp = ft_memalloc(1);
	return (tmp);
}

void	spcl_c_case(t_printfv *printfv, char *tmp)
{
	if (printfv->percent.minus)
	{
		printf_putchar(0, &printfv->printed);
		printf_putstr(tmp + 1, &printfv->printed);
	}
	else
	{
		printf_putstr(tmp + 1, &printfv->printed);
		printf_putchar(0, &printfv->printed);
	}
	return ;
}

void	insert_flgminuszeroprint(t_printfv *printfv)
{
	char	c;
	char	*tmp;
	int		j;

	c = cond((printfv->percent.zero), '0', ' ');
	j = (printfv->percent).width -
		ft_strlen((const char*)(printfv->percent).charg);
	tmp = width(printfv, j, c);
	if (printfv->percent.specifier == 'c' && printfv->percent.charg[0] == '\0')
	{
		spcl_c_case(printfv, tmp);
		return ;
	}
	if ((printfv->percent).minus)
		insert_minus(printfv, tmp);
	else
	{
		if ((printfv->percent.precision || printfv->percent.precision0) &&
				!(printfv->percent.zero && printfv->percent.specifier == 'f'))
			prec_floatzero(printfv, tmp);
		else
			nprec_width_zero(printfv, tmp);
	}
	ft_memdel((void**)&tmp);
}
