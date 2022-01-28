/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoinus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:44:19 by acoinus           #+#    #+#             */
/*   Updated: 2021/12/14 13:49:13 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrr(t_stk *sa, t_stk *sb, char *s)
{
	ft_rev_rotate(sa, NULL);
	ft_rev_rotate(sb, NULL);
	if (s)
		write(1, &s[0], 4);
	return ;
}

void	ft_rr(t_stk *sa, t_stk *sb, char *s)
{
	ft_rotate(sa, NULL);
	ft_rotate(sb, NULL);
	if (s)
		write(1, &s[0], 3);
	return ;
}
