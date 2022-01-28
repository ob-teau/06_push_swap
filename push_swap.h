/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alice <acoinus@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:43:32 by alice             #+#    #+#             */
/*   Updated: 2021/12/17 17:39:16 by acoinus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

# define SUCCESS 0
# define FAIL 1
# define COMP 

typedef struct s_dll
{
	int				n;
	int				i;
	int				opa;
	int				opb;
	int				opt;
	int				opr;
	int				rev;
	int				revb;
	struct s_dll	*next;
	struct s_dll	*prev;
}	t_dll;

typedef struct s_stk
{
	struct s_dll	*head;
	struct s_dll	*tail;
}	t_stk;

void	list_display(t_stk *adma, t_stk *admb);

/*
 * ******************* PUSH_SWAP fonctions principales *********************
 */

int		check_ag(char *s, t_stk *sa, t_stk *sb, t_dll *d);
int		check_before(char **av);
int		check_all(char *s);
t_stk	*list_inita(t_stk *a, t_dll *dll, int n);
t_stk	*list_initb(t_stk *b);
int		enter_list(t_stk *sa, char **s, int i);
int		check_double(t_stk *sa);
int		check_sort(t_stk *sa);
int		check_sort_invert(t_stk *sa);
int		count_nb(t_stk *s);//algo
int		reverse_sort(t_stk *sa, t_stk *sb);//algo

/*
 ********************************* LIBFT ***********************************
 * */

char	*ft_strjoin(int size, char **s, char *sep);
int		ft_strlen(char *str);
char	**ft_split(char *s, char c);
long	ft_atoi(char *s);

/*
 *********************************** FREE ***********************************
 */

int		free_all(t_stk *sa, t_stk *sb, char **s, int x);
int		delete_list(t_stk *s, int x);
int		free_strjoin(char *s, int x);

/*
 **************************************************************
 */
void	ft_swap(t_stk *stk, char *s);
void	ft_rev_rotate(t_stk *stk, char *s);
void	ft_rotate(t_stk *stk, char *s);
void	ft_push(t_stk *src, t_stk *dest, char *s);
void	ft_index(t_stk *sa);
void	ft_rr(t_stk *sa, t_stk *sb, char *s);
void	ft_rrr(t_stk *sa, t_stk *sb, char *s);
int		is_rotate(t_stk *sa);
void	algo_pars(t_stk *sa, t_stk *sb);
void	algo_3(t_stk *sa);
void	algo_4(t_stk *sa, t_stk *sb);
void	algo_5(t_stk *sa, t_stk *sb);
void	big_nb(t_stk *sa, t_stk *sb, t_dll **now, int x);

#endif
