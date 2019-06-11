/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:40:30 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 16:46:31 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	insert_precision_s(t_printfv *printfv)
{
	if (printfv->percent.precision && printfv->percent.charg)
		printfv->percent.charg =
			ft_strsub(printfv->percent.charg, 0, printfv->percent.precision);
}

void	insert_precisionn(t_printfv *printfv, char *c, int j, char *tmp)
{
	char *tamp;

	tmp = (char*)malloc(sizeof(char) * (j + 1));
	tmp[j] = '\0';
	while (j > 0)
		tmp[--j] = '0';
	tamp = ft_strjoin(tmp, (printfv->percent).charg);
	ft_memdel((void**)&((printfv->percent).charg));
	ft_memdel((void**)&tmp);
	(printfv->percent).charg = tamp;
	if (c)
	{
		tamp = ft_strjoin(c, (printfv->percent).charg);
		ft_memdel((void**)&((printfv->percent).charg));
		(printfv->percent).charg = tamp;
		ft_memdel((void**)&c);
	}
}

void	insert_precision(t_printfv *printfv)
{
	int		j;
	char	*tmp;
	char	*c;

	if (strchrchr("s", "\0", (printfv->percent).specifier))
		insert_precision_s(printfv);
	if (strchrchr("diouxX", "\0", (printfv->percent).specifier))
	{
		c = str_sub_digit(&printfv->percent.charg, printfv);
		j = (printfv->percent).precision - ft_strlen((printfv->percent).charg);
		if (j < 0)
		{
			if (c)
			{
				tmp = ft_strjoin(c, printfv->percent.charg);
				ft_memdel((void**)&printfv->percent.charg);
				printfv->percent.charg = tmp;
			}
			return ;
		}
		insert_precisionn(printfv, c, j, tmp);
	}
}
