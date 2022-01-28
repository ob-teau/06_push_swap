/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_nb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:42:13 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/17 17:38:33 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_opti(t_stk *sa, t_stk *sb, t_dll *dll)
{
	while (dll->opr-- > 0)
	{
		if (dll->rev)
			ft_rrr(sa, sb, "rrr\n");
		else
			ft_rr(sa, sb, "rr\n");
	}
	while (dll->opa-- > 0)
	{
		if (dll->rev)
			ft_rev_rotate(sa, "rra\n");
		else
			ft_rotate(sa, "ra\n");
	}
	while (dll->opb-- > 0)
	{
		if (dll->revb)
			ft_rev_rotate(sb, "rrb\n");
		else
			ft_rotate(sb, "rb\n");
	}
	ft_push(sa, sb, "pb\n");
}

int	c_rotation(t_stk *s, int i)
{
	t_dll	*now;
	int		op;

	now = s->head;
	op = 0;
	while (now->i != i && op++ != -1)
		now = now->next;
	now->rev = 0;
	if (op > count_nb(s) / 2)
	{
		now = s->head;
		op = 0;
		while (now->i != i && op++ != -1)
			now = now->prev;
		now->rev = 1;
	}
	return (op);
}

t_dll	*place_b(t_dll *now, t_stk *sb)
{
	t_dll	*p;
	int		x[2];

	p = sb->head;
	x[0] = 0;
	x[1] = 0;
	if (sb->head == sb->tail)
		return (p);
	while (x[0]++ < count_nb(sb))
	{
		if (p->i > x[1])
			x[1] = p->i;
		if (now->i > p->i && now->i < p->prev->i)
			return (p);
		p = p->next;
	}
	while (p->i != x[1])
		p = p->next;
	return (p);
}

void	ft_fin(t_stk *sa, t_stk *sb)
{
	t_dll	*now;
	int		x;

	while (sb->head)
		ft_push(sb, sa, "pa\n");
	now = sa->head;
	x = c_rotation(sa, 0);
	while (now->i != 0)
		now = now->next;
	while (x-- > 0)
	{
		if (now->rev)
			ft_rev_rotate(sa, "rra\n");
		else
			ft_rotate(sa, "ra\n");
	}
}

void	big_nb(t_stk *sa, t_stk *sb, t_dll **now, int x)
{
	while (sa->head)
	{
		x = 0;
		now[0] = sa->head;
		now[2] = sa->head;
		while (x++ < count_nb(sa))
		{
			now[1] = place_b(now[0], sb);
			now[0]->opa = c_rotation(sa, now[0]->i);
			now[0]->opb = c_rotation(sb, now[1]->i);
			now[0]->revb = now[1]->rev;
			now[0]->opr = 0;
			if (now[0]->rev == now[1]->rev)
				while (now[0]->opa > 0 && now[0]->opb > 0
					&& now[0]->opa-- != -1 && now[0]->opb-- != -1)
					now[0]->opr++;
			now[0]->opt = now[0]->opa + now[0]->opb + now[0]->opr;
			if (now[0]->opt < now[2]->opt)
				now[2] = now[0];
			now[0] = now[0]->next;
		}
		push_opti(sa, sb, now[2]);
	}
	ft_fin(sa, sb);
}
