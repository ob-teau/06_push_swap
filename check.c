/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:23:40 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/17 17:33:01 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort_invert(t_stk *sa)
{
	t_dll	*now;

	now = sa->tail;
	while (now->prev != sa->tail && now->n < now->prev->n)
		now = now->prev;
	if (now == sa->head)
		return (FAIL);
	return (SUCCESS);
}

int	check_sort(t_stk *sa)
{
	t_dll	*now;

	now = sa->head;
	while (now->next != sa->head && now->n < now->next->n)
		now = now->next;
	if (now == sa->tail)
		return (FAIL);
	return (SUCCESS);
}

int	check_double(t_stk *sa)
{
	t_dll	*now[2];
	int		nb;

	now[0] = sa->head;
	while (now[0] != sa->tail)
	{
		nb = now[0]->n;
		now[1] = sa->head;
		while (now[1] != sa->tail)
		{
			if (nb == now[1]->next->n && now[0] != now[1]->next)
				return (FAIL);
			now[1] = now[1]->next;
		}
		now[0] = now[0]->next;
	}
	return (SUCCESS);
}

int	check_all(char *s)
{
	int	i;

	i = 0;
	if (!s || s[0] == '\0')
		return (FAIL);
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == ' ')
			i++;
		else if (s[i] == '-' || s[i] == '+')
		{
			if (s[i + 1] < '0' && s[i + 1] > '9')
				return (FAIL);
			i++;
		}
		else
			return (FAIL);
	}
	return (SUCCESS);
}

int	check_before(char **av)
{
	int		x;
	int		y;
	int		z;

	x = -1;
	while (av[++x])
		if (av[x][0] == '\0')
			return (FAIL);
	x = 0;
	while (av[++x])
	{
		y = -1;
		z = 0;
		while (av[x][++y])
			if (av[x][y] >= '0' && av[x][y] <= '9')
				z++;
		if (!z)
			return (FAIL);
	}
	return (SUCCESS);
}
