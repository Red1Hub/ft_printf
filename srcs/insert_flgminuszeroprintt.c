/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_flgminuszeroprintt.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:43:22 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 16:44:43 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	insert_minus(t_printfv *printfv, char *tmp)
{
	if ((printfv->percent).plus || (printfv->percent).charg[0] != '+' ||
			strchrchr("cs", "\0", printfv->percent.specifier))
		printf_putstr(printfv->percent.charg, &(printfv->printed));
	else
		printf_putstr(printfv->percent.charg + 1, &(printfv->printed));
	printf_putstr(tmp, &(printfv->printed));
}
