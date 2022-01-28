/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:45:48 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/21 11:08:28 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	insert_list(t_stk *sa, int nb)
{
	t_dll	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
		return (FAIL);
	new->n = nb;
	new->i = 0;
	new->next = sa->head;
	new->prev = sa->tail;
	sa->head->prev = new;
	sa->tail->next = new;
	sa->tail = new;
	return (SUCCESS);
}

int	enter_list(t_stk *sa, char **s, int i)
{
	long	nb;

	while (s[i])
	{
		nb = ft_atoi(s[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (FAIL);
		if (insert_list(sa, nb))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

t_stk	*list_initb(t_stk *b)
{
	b = malloc(sizeof(*b));
	if (b == NULL)
		return (NULL);
	b->head = NULL;
	b->tail = NULL;
	return (b);
}

t_stk	*list_inita(t_stk *a, t_dll *dll, int n)
{
	dll = malloc(sizeof(*dll));
	a = malloc(sizeof(*a));
	if (!dll || !a)
	{
		if (dll)
			free(dll);
		if (a)
			free(a);
		return (NULL);
	}
	a->head = dll;
	a->tail = dll;
	dll->n = n;
	dll->i = 0;
	dll->next = dll;
	dll->prev = dll;
	return (a);
}
