/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:52:28 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/17 17:35:11 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	delete_list(t_stk *s, int x)
{
	t_dll	*i;

	if (!s)
		return (x);
	i = s->head;
	while (i != s->tail)
	{
		i = i->next;
		free(i->prev);
	}
	free(i);
	free(s);
	return (x);
}

void	free_split(char **s)
{
	int	i;

	i = -1;
	if (s)
	{
		while (s[++i])
			free(s[i]);
		free(s);
	}
	return ;
}

int	free_all(t_stk *sa, t_stk *sb, char **s, int x)
{
	free_split(s);
	delete_list(sa, 0);
	delete_list(sb, 0);
	return (x);
}

int	free_strjoin(char *s, int x)
{
	if (s)
		free(s);
	return (x);
}
