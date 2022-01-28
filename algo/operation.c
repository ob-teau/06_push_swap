/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:55:01 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/14 13:43:53 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_suite(t_stk *dest, t_dll *now)
{
	if (!dest->head)
	{
		dest->head = now;
		dest->tail = now;
		now->next = dest->head;
		now->prev = dest->tail;
	}
	else
	{
		now->next = dest->head;
		now->prev = dest->tail;
		dest->tail->next = now;
		dest->head = now;
		now->next->prev = now;
	}
	return ;
}

void	ft_push(t_stk *src, t_stk *dest, char *s)
{
	t_dll	*now;

	if (!src->head)
		return ;
	now = src->head;
	if (src->head == src->tail)
	{
		src->head = NULL;
		src->tail = NULL;
	}
	else
	{
		src->head = now->next;
		src->tail->next = src->head;
		src->head->prev = src->tail;
	}
	push_suite(dest, now);
	if (s)
		write(1, &s[0], 3);
	return ;
}

void	ft_rotate(t_stk *stk, char *s)
{
	if (!stk->head)
		return ;
	stk->head = stk->head->next;
	stk->tail = stk->tail->next;
	if (s)
		write(1, &s[0], 3);
	return ;
}

void	ft_rev_rotate(t_stk *stk, char *s)
{
	if (!stk->head)
		return ;
	stk->head = stk->head->prev;
	stk->tail = stk->tail->prev;
	if (s)
		write(1, &s[0], 4);
	return ;
}

void	ft_swap(t_stk *stk, char *s)
{
	int		x;

	if (!stk->head)
		return ;
	x = stk->head->n;
	stk->head->n = stk->head->next->n;
	stk->head->next->n = x;
	x = stk->head->i;
	stk->head->i = stk->head->next->i;
	stk->head->next->i = x;
	if (s)
		write(1, &s[0], 3);
	return ;
}
