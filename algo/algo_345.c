/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_345.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:14:40 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/17 17:38:10 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	algo_3(t_stk *sa)
{
	t_dll	*dll;

	dll = sa->head;
	if (dll->n < dll->next->n)
	{
		ft_rev_rotate(sa, "rra\n");
		dll = sa->head;
		if (dll->n > dll->next->n)
			ft_swap(sa, "sa\n");
		else
			return ;
	}
	if (dll->n > dll->next->n)
	{
		if (dll->n < dll->prev->n)
			ft_swap(sa, "sa\n");
		else
		{
			ft_rotate(sa, "ra\n");
			dll = sa->head;
			if (dll->n > dll->next->n)
				ft_swap(sa, "sa\n");
		}
		return ;
	}
}

void	algo_4(t_stk *sa, t_stk *sb)
{
	t_dll	*dll;

	dll = sa->head;
	if (dll->next->i == 0)
		ft_rotate(sa, "ra\n");
	else if (dll->next->next->i == 0)
	{
		ft_rotate(sa, "ra\n");
		ft_rotate(sa, "ra\n");
	}
	else if (dll->prev->i == 0)
		ft_rev_rotate(sa, "rra\n");
	ft_push(sa, sb, "pb\n");
	if (!check_sort(sa))
		algo_3(sa);
	ft_push(sb, sa, "pa\n");
	return ;
}

void	algo_5(t_stk *sa, t_stk *sb)
{
	t_dll	*dll;

	dll = sa->head;
	if (dll->next->i == 4)
		ft_rotate(sa, "ra\n");
	else if (dll->next->next->i == 4)
	{
		ft_rotate(sa, "ra\n");
		ft_rotate(sa, "ra\n");
	}
	else if (dll->prev->prev->i == 4)
	{
		ft_rev_rotate(sa, "rra\n");
		ft_rev_rotate(sa, "rra\n");
	}
	else if (dll->prev->i == 4)
		ft_rev_rotate(sa, "rra\n");
	ft_push(sa, sb, "pb\n");
	if (!check_sort(sa))
		algo_4(sa, sb);
	ft_push(sb, sa, "pa\n");
	ft_rotate(sa, "ra\n");
}
