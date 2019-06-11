#ifndef PRINTF_H
#define PRINTF_H
#include "./libft/libft.h"
#include "./float/floak.h"
#include <stdarg.h>
#define NBRLENGTH 8
#include <stdio.h> //to remove

char			*floaki(long double fl, int precision, int bolpoint, int e);
char			*e_floaki(long double fl, int precision, int bolpoint);
char			*e_floakii(char **result, int exponent, int precision);
char			*floaki(long double fl, int precision, int bolpoint, int e);
char			*infinity(int sign);
char			*nani(void);
void			minimize_error(char **str, int prec, int nintprtlen, int pminusten);
void			decimal_mantissa(char **result, long double fl, char *zerostr);
int				pf_bug(char *str, int i);
char			*addpoint(char *str, int pos, int bolpoint, int sign);
char			*charmultip(char *str0, char *str1);
char			*charsum(char *cnststr1, char *cnststr2);
void			rm_uzeros(char **str);
char			*power(char *str, int times);
void			s_strjoin(char **s1, char **s2, char **joinresult, int a);
char			*grep_mem(long double fl);

typedef union	s_arg
{
	int						di;
	signed char				hhdi;
	short int				hdi;
	long int				ldi;
	long long int			lldi;
	unsigned int			ouxX;
	unsigned char			hhouxX;
	unsigned short int		houxX;
	unsigned long int		louxX;
	unsigned long long int	llouxX;
	double					fl;
	long double				Lf;

}				t_arg;

typedef	struct	s_percent
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
	unsigned char 	specifier;
	t_arg			arg;
	char			*charg;
}				t_percent;

typedef struct	s_printfv
{
	char			*allspecifiers;
	char			*allflags;
	int				*alllengths;
	t_percent		percent;
	char			*cursor;
	int				printed;
}				t_printfv;

#endif
