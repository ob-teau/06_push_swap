/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:28:16 by alice             #+#    #+#             */
/*   Updated: 2021/12/17 17:34:32 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pre_algo(t_stk *sa, t_stk *sb, char **str)
{
	int	i;

	i = 0;
	if (count_nb(sa) == 1)
		return (free_all(sa, sb, str, 0));
	if (check_sort_invert(sa) && count_nb(sa) > 5)
		i += reverse_sort(sa, sb);
	ft_index(sa);
	i += is_rotate(sa);
	if (!i)
		algo_pars(sa, sb);
	return (free_all(sa, sb, str, 0));
}

int	check_long(char **s)
{
	int	i;

	i = -1;
	if (!s || !s[0])
		return (FAIL);
	while (s[++i])
		if (ft_strlen(s[i]) > 11)
			return (FAIL);
	return (SUCCESS);
}

int	check_ag(char *s, t_stk *sa, t_stk *sb, t_dll *d)
{
	char	**str;
	long	nb;

	if (check_all(s))
		return (FAIL);
	str = ft_split(s, ' ');
	if (check_long(str))
		return (free_all(sa, sb, str, 1));
	nb = ft_atoi(str[0]);
	if (nb > INT_MAX || nb < INT_MIN)
		return (free_all(sa, sb, str, 1));
	sa = list_inita(sa, d, nb);
	sb = list_initb(sb);
	if (sa == NULL || sb == NULL || enter_list(sa, str, 1) || check_double(sa))
		return (free_all(sa, sb, str, 1));
	if (check_sort(sa))
		return (free_all(sa, sb, str, 0));
	return (pre_algo(sa, sb, str));
}

int	main(int ac, char **av)
{
	t_dll	*d;
	t_stk	*stk[2];
	char	*s;
	int		e;

	d = NULL;
	stk[0] = NULL;
	stk[1] = NULL;
	e = 0;
	if (ac < 2)
		return (SUCCESS);
	s = ft_strjoin(ac - 1, &av[1], " ");
	if (s == NULL || check_before(av))
		e = free_strjoin(s, 1);
	if (!e)
	{
		e = check_ag(s, stk[0], stk[1], d);
		free_strjoin(s, 0);
	}
	if (e)
	{
		write(2, "Error\n", 6);
		return (FAIL);
	}
	return (SUCCESS);
}
