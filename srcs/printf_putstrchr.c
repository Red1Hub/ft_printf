/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putstrchr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:06:06 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 17:06:48 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	printf_putchar(char c, int *printed)
{
	*printed = *printed + 1;
	write(1, &c, 1);
}

void	printf_putstr(char const *s, int *printed)
{
	unsigned int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
		printf_putchar(s[i++], printed);
}
