/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:04:53 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 17:38:18 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAK_H
# define FLOAK_H
# include "printf.h"

typedef union					u_floaki
{
	long double					f;
	struct
	{
		unsigned long long int	mantisa : 63;
		unsigned int			intgprt : 1;
		unsigned int			exponent : 15;
		unsigned int			sign : 1;
	}							parts;
}								t_floaki;

#endif
