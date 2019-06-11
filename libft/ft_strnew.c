/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:56:42 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/12 22:37:03 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = (char*)ft_memalloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ptr = (char*)ft_memset(ptr, 0, size + 1);
	return (ptr);
}
