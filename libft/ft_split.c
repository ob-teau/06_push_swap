/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <acoinus@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:28:10 by user42            #+#    #+#             */
/*   Updated: 2021/12/13 14:42:22 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_nb_str(char *s1, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (s1[0] == '\0')
		return (0);
	while (s1[i] != '\0')
	{
		while (s1[i] == c)
			i++;
		if (!s1[i])
			break ;
		n++;
		while (s1[i] && s1[i] != c)
			i++;
	}
	return (n);
}

static int	ft_nb_char(char *s2, char c, int i)
{
	int	len;

	len = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free(char **tab, int j)
{
	while (j > 0)
	{
		j--;
		free((void *)tab[j]);
	}
	free(tab);
	return (NULL);
}

static char	**ft_rempli(char *s, char **tab, char c, int n_str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < n_str)
	{
		k = 0;
		while (s[i] == c)
			i++;
		tab[j] = (char *)malloc(sizeof(char) * ft_nb_char(s, c, i) + 1);
		if (tab[j] == NULL)
			return (ft_free(tab, j));
		while (s[i] != '\0' && s[i] != c)
			tab[j][k++] = s[i++];
		tab[j][k] = '\0';
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char			**tab;
	unsigned int	n_str;

	if (s == NULL)
		return (NULL);
	n_str = ft_nb_str(s, c);
	tab = (char **)malloc(sizeof(char *) * (n_str + 1));
	if (!tab)
		return (NULL);
	return (ft_rempli(s, tab, c, n_str));
}
