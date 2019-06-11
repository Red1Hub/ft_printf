/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 05:14:50 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/13 10:24:25 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdupc(char const *s, char c)
{
	unsigned char	i;
	unsigned char	l;
	char			*dup;
	int				j;

	i = 0;
	j = 0;
	l = ft_strlen(s);
	dup = (char*)malloc(sizeof(char) * (l + 1));
	if (dup == NULL)
		return (NULL);
	while (i < l)
	{
		while ((s[i] == c) && j == 0)
			i++;
		while ((s[l - 1] == c) && s[i] != '\0')
			l--;
		dup[j++] = s[i++];
	}
	dup[j] = '\0';
	return (dup);
}

static char	**words_count(char *str, char c)
{
	int		words;
	int		i;
	char	**split;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			words++;
		i++;
	}
	split = (char**)malloc(sizeof(char*) * (words + 1 + 1));
	if (split == NULL)
		return (NULL);
	split[words + 1] = NULL;
	return (split);
}

static char	**ft_ctable(char **split, char *newstr, char c)
{
	int tab[2];
	int words;
	int	i;

	tab[0] = 0;
	tab[1] = 0;
	i = 0;
	words = 0;
	while (1)
	{
		if (newstr[i] == c || newstr[i] == '\0')
		{
			while (newstr[i] == c)
				i++;
			split[words++] = ft_strsub(newstr, tab[0], tab[1]);
			tab[1] = 0;
			tab[0] = i;
		}
		tab[1]++;
		if (newstr[i] == '\0')
			break ;
		i++;
	}
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	*newstr;
	char	**split;
	char	**splitc;

	if (s == NULL)
		return (NULL);
	newstr = ft_strdupc(s, c);
	if (newstr == NULL)
		return (NULL);
	if (newstr[1] == '\0')
	{
		newstr = NULL;
		splitc = &newstr;
		return (splitc);
	}
	split = words_count(newstr, c);
	if (split == NULL)
		return (NULL);
	splitc = ft_ctable(split, newstr, c);
	if (newstr == NULL || split == NULL)
		return (NULL);
	return (splitc);
}
