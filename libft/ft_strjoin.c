/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:45:42 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/14 11:44:44 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

static int	count(int size, char **strs, char *sep)
{
	int	dest_size;
	int	sep_int;
	int	s;

	dest_size = 1;
	s = 0;
	while (s < size)
	{
		dest_size += ft_strlen(strs[s]);
		s++;
	}
	sep_int = ft_strlen(sep);
	dest_size += sep_int * (size - 1);
	return (dest_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;

	if (size == 0)
	{
		dest = malloc(sizeof(char) * 1);
		if (dest == NULL)
			return (NULL);
		dest[0] = 0;
		return (dest);
	}
	dest = (char *)malloc(sizeof(char) * count(size, strs, sep));
	if (dest == NULL)
		return (NULL);
	dest[0] = 0;
	i = 0;
	while (i < size)
	{
		dest = ft_strcat(dest, strs[i]);
		if (i < (size - 1))
			dest = ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}
