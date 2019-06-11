/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 17:02:03 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/10 20:57:14 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int		strchrchr(char *stringa, char *stringb, char c)
{
	int i;
	int j;

	i = 0;
	while (stringa[i] != '\0')
	{
		if (stringa[i] == c)
		{
			j = 0;
			while (stringb[j] != '\0')
				if (stringb[j++] == c)
					return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_itoa_base_ll(long long int x)
{
	long long int	tmp;
	int				base;
	int				i;
	char			*str;

	i = 0;
	base = 10;
	x = -x;
	tmp = x;
	while (tmp > 0 && ++i)
		tmp = tmp / base;
	str = (char*)malloc(sizeof(char) * (i + 2));
	str[i + 1] = '\0';
	str[0] = '-';
	while (i > 0)
	{
		if (x % base < 10)
			str[--i + 1] = x % base + '0';
		x = x / base;
	}
	return (str);
}

char	*itoa_shandler(long long x, int condition, int precision0)
{
	char *str;

	if (x == -9223372036854775807 - 1 && condition)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	if (x == 0)
	{
		if (precision0)
		{
			str = ft_memalloc(2);
			str[0] = '+';
			return (str);
		}
		str = ft_strdup("+0");
		return (str);
	}
	return (NULL);
}

char	*ft_itoa_base(unsigned long long x, int b, char c, t_printfv *printfv)
{
	int					i;
	int					sign;
	unsigned long long	tmp;
	char				*str;

	if ((str = itoa_shandler((long long)x,
					(c != 'c' && b == 10), printfv->percent.precision0)))
		return (str);
	i = 0;
	sign = 0;
	if ((long long int)x < 0 && b == 10 && c != 'u' && (sign = 1))
		return (ft_itoa_base_ll((long long int)x));
	tmp = x;
	while (tmp > 0 && ++i)
		tmp = tmp / b;
	str = (char*)malloc(sizeof(char) * (i + 2));
	str[i + 1] = '\0';
	str[0] = (sign) ? '-' : '+';
	while (i > 0)
	{
		if (x % b < 10)
			str[--i + 1] = x % b + '0';
		else if (c < 'a')
			str[--i + 1] = 'A' + x % b - 10;
		else
			str[--i + 1] = 'a' + x % b - 10;
		x = x / b;
	}
	return (str);
}

char	*str_sub_digit(char **str, t_printfv *printfv)
{
	int		i;
	char	*tmp;
	char	*tmp0;

	i = 0;
	while (str[0][i] != '\0' && (str[0][i] == ' ' ||
			str[0][i] == 'X' || str[0][i] == 'x' ||
			str[0][i] == '+' || str[0][i] == '-' ||
			(str[0][i] == '0' && i == 0 && (str[0][1] == 'x' ||
												str[0][1] == 'X')
			&& printfv->percent.hash
			&& strchrchr("oxXp", "\0", printfv->percent.specifier))))
		i++;
	if (i)
		tmp0 = ft_strsub(*str, 0, i);
	else
		tmp0 = NULL;
	tmp = ft_strsub(*str, i, ft_strlen(*str) - i);
	ft_memdel((void**)str);
	*str = tmp;
	return (tmp0);
}

int		cantor(int a, int b)
{
	return ((a + b) * (a + b + 1) + b);
}

void	init_gth_allgth(t_printfv *printfv)
{
	int	i;

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

int		check_fill_specif(t_printfv *printfv)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (printfv->cursor[i] != '\0' && count == 0)
	{
		j = 0;
		while (printfv->allspecifiers[j] != '\0')
			if (printfv->cursor[i] == printfv->allspecifiers[j++])
			{
				count++;
				printfv->percent.specifier = printfv->allspecifiers[j - 1];
				break ;
			}
		if (!count)
			i++;
	}
	if (count == 0)
	{
		printfv->cursor += i;
		return (0);
	}
	return (1);
}

int		strtablechr(int *taba, int x)
{
	int i;
	int j;

	i = 0;
	while (taba[i] != cantor('0', '0'))
	{
		if (taba[i] == x)
			return (1);
		i++;
	}
	return (0);
}

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
		else if (printfv->cursor[i] == '*' && printfv->cursor[i - 1] != '.' && ++i)
			printfv->percent.width = va_arg(ap, int);
		else if (printfv->cursor[i] == '*' && printfv->cursor[i - 1] == '.' && ++i)
			printfv->percent.precision = va_arg(ap, int);
		else
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

int		checknfill(t_printfv *printfv, va_list ap)
{
	if (check_fill_specif(printfv))
	{
		fill_width_precision(printfv, ap);
		fill_flags_length(printfv);
		return (1);
	}
	return (0);
}

int		ltrtobs(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'u' || c == 'd' || c == 'i')
		return (10);
	if (c == 'o')
		return (8);
	return (0);
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
	printfv->percent.charg = (ft_strlen(s1) > ft_strlen(s0)) ? s0 : s1 ;
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
	printfv->percent.charg = (ft_strlen(s1) > ft_strlen(s0)) ? s0 : s1 ;
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
	char	*stringa;
	char	*stringb;
	int		tmpf;
	int		tmpf0;

	stringa = "di";
	stringb = "ouxX";
	if (strchrchr(stringa, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, long int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
	else if (strchrchr(stringb, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, unsigned long int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
	else if (strchrchr("fe", "\0", printfv->percent.specifier))
	{
		tmpf0 = (printfv->percent.specifier == 'e') ? 1 : 0 ;
		tmpf = printfv->percent.precision + printfv->percent.hash;
		(printfv->percent).charg =
			floaki(va_arg(ap, double), (printfv->percent).precision, tmpf, tmpf0);
	}
	else if (printfv->percent.precision == 'g')
		f_nonee_l_g(printfv, ap);
	else if (printfv->percent.specifier == 'b')
		printfv->percent.charg = grep_mem(va_arg(ap, double));
}

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
		tmpf0 = (printfv->percent.specifier == 'e') ? 1 : 0 ;
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
	else if ((printfv->percent).specifier == 'p')
		(printfv->percent).charg =
			ft_itoa_base((long long int)va_arg(ap, void*), 16, 'x', printfv);
}

void	f_none(t_printfv *printfv, va_list ap)
{
	char	*stringa;
	char	*stringb;
	char	*stringc;

	stringa = "di";
	stringb = "ouxX";
	stringc = "csp";
	if (strchrchr(stringa, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
	else if (strchrchr(stringb, "\0", (printfv->percent).specifier))
	{
		(printfv->percent).charg = ft_itoa_base(va_arg(ap, unsigned int),
				ltrtobs((printfv->percent).specifier),
				(printfv->percent).specifier, printfv);
	}
	else if (printfv->percent.specifier == '%')
	{
		printfv->percent.charg = ft_memalloc(2);
		printfv->percent.charg[0] = '%';
	}
	else if (printfv->percent.specifier == 'b')
		printfv->percent.charg = grep_mem(va_arg(ap, double));
	f_nonee(printfv, ap);
}

void	f_lll(t_printfv *printfv, va_list ap)
{
	int tmpf;
	int tmpf0;

	if (strchrchr("fe", "\0", (printfv->percent).specifier))
	{
		tmpf0 = (printfv->percent.specifier == 'e') ? 1 : 0 ;
		tmpf = printfv->percent.precision + printfv->percent.hash;
		(printfv->percent).charg =
			floaki(va_arg(ap, long double), (printfv->percent).precision, tmpf, tmpf0);
	}
	else if (printfv->percent.specifier == 'b')
		printfv->percent.charg = grep_mem(va_arg(ap, long double));
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

int		condition_flghash(t_printfv *printfv)
{
	if ((printfv->percent.charg[0] == '0' &&
				printfv->percent.charg[1] == '\0' &&
				printfv->percent.specifier != 'p') ||
				(printfv->percent.charg[0] == '\0'
				&& printfv->percent.specifier != 'o'))
		return (1);
	return (0);
}

void	insert_flghash(t_printfv *printfv)
{
	char *tmp;

	if (condition_flghash(printfv))
		return ;
	if ((printfv->percent).hash || printfv->percent.specifier == 'p')
	{
		if ((printfv->percent).specifier == 'o')
		{
			tmp = ft_strjoin("0", (const char*)(printfv->percent).charg);
			ft_memdel((void**)&((printfv->percent).charg));
			(printfv->percent).charg = tmp;
		}
		else if ((printfv->percent).specifier == 'x' ||
				printfv->percent.specifier == 'p')
		{
			tmp = ft_strjoin("0x", (const char*)(printfv->percent).charg);
			ft_memdel((void**)&((printfv->percent).charg));
			(printfv->percent).charg = tmp;
		}
		else if ((printfv->percent).specifier == 'X')
		{
			tmp = ft_strjoin("0X", (const char*)(printfv->percent).charg);
			ft_memdel((void**)&((printfv->percent).charg));
			(printfv->percent).charg = tmp;
		}
	}
}

void	insert_flgplusspace(t_printfv *printfv)
{
	char *tmp;

	if ((printfv->percent).plus)
		return ;
	if ((printfv->percent).space &&
			strchrchr("dif", "\0", (printfv->percent).specifier))
	{
		if ((printfv->percent).charg[0] != '-')
		{
			tmp = ft_strjoin(" ", (const char*)((printfv->percent).charg + 1));
			ft_memdel((void**)&((printfv->percent).charg));
			(printfv->percent).charg = tmp;
		}
	}
}

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

void	insert_minus(t_printfv *printfv, char *tmp)
{
	if ((printfv->percent).plus || (printfv->percent).charg[0] != '+' ||
			strchrchr("cs", "\0", printfv->percent.specifier))
		printf_putstr(printfv->percent.charg, &(printfv->printed));
	else
		printf_putstr(printfv->percent.charg + 1, &(printfv->printed));
	printf_putstr(tmp, &(printfv->printed));
}

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

	c = ' ';
	if ((printfv->percent).zero)
		c = '0';
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
	if (j > 0)
		ft_memdel((void**)&tmp);
}

void	modify_flagzerospace(t_printfv *printfv)
{
	if (!ft_strcmp(printfv->percent.charg + 1, "inf"))
		printfv->percent.zero = 0;
	if (!ft_strcmp(printfv->percent.charg, "nan"))
		printfv->percent.zero = 0;
	if (!ft_strcmp(printfv->percent.charg, "nan"))
		printfv->percent.space = 0;
}

void	special_printerr(t_printfv *printfv)
{
	if (strchrchr("efg", "\0", printfv->percent.specifier))
	{
		modify_flagzerospace(printfv);
		insert_flgplusspace(printfv);
		insert_flgminuszeroprint(printfv);
	}
	else if (printfv->percent.specifier == 's')
	{
		insert_precision(printfv);
		insert_flgminuszeroprint(printfv);
	}
	else if (strchrchr("c%", "\0", printfv->percent.specifier))
		insert_flgminuszeroprint(printfv);
	else if (printfv->percent.specifier == 'b')
	{
		printfv->percent.plus = 0;
		insert_flgminuszeroprint(printfv);
	}
	else
	{
		insert_flghash(printfv);
		insert_flgminuszeroprint(printfv);
	}
}

void	special_printer(t_printfv *printfv)
{
	char *str;

	if (strchrchr("uoxXp", "\0", printfv->percent.specifier))
	{
		if (printfv->percent.charg[0] == '+' ||
			printfv->percent.charg[0] == '-')
			printfv->percent.charg = ft_strdup(printfv->percent.charg + 1);
	}
	if (!strchrchr("cspfb%", "\0", printfv->percent.specifier))
	{
		insert_flghash(printfv);
		insert_precision(printfv);
		insert_flgplusspace(printfv);
		insert_flgminuszeroprint(printfv);
	}
	else
		special_printerr(printfv);
	while (printfv->cursor[0] != printfv->percent.specifier)
		printfv->cursor++;
	printfv->cursor++;
}

void	init_percent_flag(t_printfv *printfv)
{
	(printfv->percent).minus = 0;
	(printfv->percent).plus = 0;
	(printfv->percent).space = 0;
	(printfv->percent).hash = 0;
	(printfv->percent).zero = 0;
}

void	printer(t_printfv *printfv, va_list ap)
{
	int			i;

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

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_printfv	printfv;

	printfv.allspecifiers = "gcsdiouxXfpbe%";
	printfv.allflags = "-+ #";
	init_gth_allgth(&printfv);
	printfv.printed = 0;
	printfv.cursor = ft_strdup(format);
	va_start(ap, format);
	printer(&printfv, ap);
	va_end(ap);
	return (printfv.printed);
}
