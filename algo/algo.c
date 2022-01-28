/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:03:20 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/17 17:37:48 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_pars(t_stk *sa, t_stk *sb)
{
	t_dll	*dll[3];
	int		i;

	i = count_nb(sa);
	if (i == 2)
		return (ft_swap(sa, "sa\n"));
	if (i == 3)
		return (algo_3(sa));
	if (i == 4)
		return (algo_4(sa, sb));
	if (i == 5)
		return (algo_5(sa, sb));
	ft_push(sa, sb, "pb\n");
	return (big_nb(sa, sb, dll, 0));
}

int	is_rotate(t_stk *sa)
{
	t_dll	*dll[2];
	int		i;

	dll[0] = sa->head;
	i = 0;
	while (dll[0]->i != 0 && i++ != -1)
		dll[0] = dll[0]->next;
	dll[1] = dll[0];
	while (dll[1] != dll[0]->prev)
	{
		if (dll[1]->i > dll[1]->next->i)
			return (0);
		dll[1] = dll[1]->next;
	}
	if (i > count_nb(sa) / 2)
		while (sa->head->i != 0)
			ft_rev_rotate(sa, "rra\n");
	else
		while (sa->head->i != 0)
			ft_rotate(sa, "ra\n");
	return (1);
}

void	ft_index(t_stk *sa)
{
	t_dll	*dll[2];
	int		i[2];

	dll[0] = sa->head;
	i[0] = 0;
	while (i[0]++ < count_nb(sa))
	{
		dll[1] = sa->head;
		i[1] = 0;
		while (i[1]++ < count_nb(sa))
		{
			if (dll[0]->n > dll[1]->n)
				dll[0]->i++;
			dll[1] = dll[1]->next;
		}
		dll[0] = dll[0]->next;
	}
	return ;
}

int	reverse_sort(t_stk *sa, t_stk *sb)
{
	ft_push(sa, sb, "pb\n");
	while (sa->head)
	{
		ft_push(sa, sb, "pb\n");
		ft_rotate(sb, "rb\n");
	}
	while (sb->head)
		ft_push(sb, sa, "pa\n");
	return (FAIL);
}

int	count_nb(t_stk *s)
{
	t_dll	*now;
	int		i;

	now = s->head;
	if (!now)
		return (0);
	i = 1;
	while (now != s->tail)
	{
		i++;
		now = now->next;
	}
	return (i);
}
