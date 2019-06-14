/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:41:38 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 17:48:00 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
# include "../includes/floak.h"
# include <stdarg.h>
# define NBRLENGTH 8

typedef	struct		s_percent
{
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				zero;
	int				width;
	int				precision;
	int				precision0;
	int				length;
	unsigned char	specifier;
	char			*charg;
}					t_percent;

typedef struct		s_printfv
{
	char			*allspecifiers;
	char			*allflags;
	int				*alllengths;
	t_percent		percent;
	char			*cursor;
	int				printed;
}					t_printfv;

int					ft_printf(const char *format, ...);
void				rm_uzeros_charsum(char **str, char **str1, char **str2);
int					cond(int condition, int tru, int flse);
int					spec_g_cond(char *str);
void				rm_uzeros_spec_g(char **str, int tmpf);
void				printer(t_printfv *printfv, va_list ap);
void				init_percent_flag(t_printfv *printfv);
void				special_printer(t_printfv *printfv);
void				special_printerr(t_printfv *printfv);
void				modify_flagzerospace(t_printfv *printfv);
void				insert_flgminuszeroprint(t_printfv *printfv);
void				spcl_c_case(t_printfv *printfv, char *tmp);
char				*width(t_printfv *printfv, int j, char c);
void				nprec_width_zero(t_printfv *printfv, char *tmp);
void				prec_floatzero(t_printfv *printfv, char *tmp);
void				insert_minus(t_printfv *printfv, char *tmp);
void				insert_precision(t_printfv *printfv);
void				insert_precisionn(t_printfv *printfv,\
					char *c, int j, char *tmp);
void				insert_precision_s(t_printfv *printfv);
void				insert_flgplusspace(t_printfv *printfv);
void				insert_flghash(t_printfv *printfv);
int					condition_flghash(t_printfv *printfv);
void				fill_arg(t_printfv *printfv, va_list ap);
void				f_lll(t_printfv *printfv, va_list ap);
void				f_none(t_printfv *printfv, va_list ap);
void				f_nonee(t_printfv *printfv, va_list ap);
void				f_ll(t_printfv *printfv, va_list ap);
void				f_l(t_printfv *printfv, va_list ap);
void				f_h(t_printfv *printfv, va_list ap);
void				f_lll_g(t_printfv *printfv, va_list ap);
void				f_nonee_l_g(t_printfv *printfv, va_list ap);
void				f_hh(t_printfv *printfv, va_list ap);
int					ltrtobs(char c);
int					checknfill(t_printfv *printfv, va_list ap);
void				fill_flags_length(t_printfv *printfv);
void				fill_flag_zero(t_printfv *printf, int j);
void				fill_width_precision(t_printfv *printfv, va_list ap);
void				modify_precision_precision0(t_printfv *printfv);
int					strtablechr(int *taba, int x);
int					check_fill_specif(t_printfv *printfv);
void				init_gth_allgth(t_printfv *printfv);
int					cantor(int a, int b);
char				*str_sub_digit(char **str, t_printfv *printfv);
char				*ft_itoa_base\
					(unsigned long long x, int b, char c, t_printfv *printfv);
char				*itoa_shandler(long long x, int condition, int precision0);
char				*ft_itoa_base_ll(long long int x);
int					strchrchr(char *stringa, char *stringb, char c);
void				printf_putstr(char const *s, int *printed);
void				printf_putchar(char c, int *printed);
char				*floaki(long double fl, int precision, int bolpoint, int e);
char				*e_floaki(long double fl, int precision, int bolpoint);
char				*e_floakii(char **result, int exponent, int precision);
char				*floaki(long double fl, int precision, int bolpoint, int e);
char				*infinity(int sign);
char				*nani(void);
void				minimize_error\
					(char **str, int prec, int nintprtlen, int pminusten);
void				decimal_mantissa\
					(char **result, long double fl, char *zerostr);
int					pf_bug(char *str, int i);
char				*addpoint(char *str, int pos, int bolpoint, int sign);
char				*charmultip(char *str0, char *str1);
char				*charsum(char *cnststr1, char *cnststr2);
void				rm_uzeros(char **str);
char				*power(char *str, int times);
void				s_strjoin(char **s1, char **s2, char **joinresult, int a);
char				*grep_mem(long double fl);

#endif
