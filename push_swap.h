/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:16:45 by eavilov           #+#    #+#             */
/*   Updated: 2022/05/05 13:15:02 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*	 🐄 pouin-ach 🐄 	*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include "libft/libft.h"

/*	---- 🐄 Strcgfrutretures 🐄 ---- */

typedef struct s_push {
	int		*taba;
	int		*tabb;
	int		*tabc;
	int		count;
	int		usage;
	int		half;
	int		chunksize;
}			t_push;

/*	---- 🐄 Functions 🐄 ---- */

/*	push_swap moves (located in moves_one/two.c)	*/

void			ft_sa(t_push *vars); // swaps first two of a
void			ft_sb(t_push *vars);
void			ft_pa(t_push *vars); // pushes first from b to a
void			ft_pb(t_push *vars); // pushes first from a to b
void			ft_ra(t_push *vars); // rotates from top to bottom (a)
void			ft_rb(t_push *vars);
void			ft_rra(t_push *vars); // rotates from bottom to top (b)
void			ft_rrb(t_push *vars);

/*	some useful functions (located in misc.c)	*/

int				ft_index_find(int *tab, int nb, t_push *vars);
int				ft_smallest(t_push *vars, int *tab);
void			ft_initiate(t_push *vars, char **av);
void			ft_func_exit(char *str);
void			ft_index_remake(t_push *vars);
char			*ft_printbit(int nb); // located in push.c

/*	main function	*/

void			ft_push_swap(t_push *vars);

/*	sorter for 3 values	*/

void			ft_sort_vsmall(t_push *vars);

/*	sorter for 4 values (located in sort_four.c)	*/

void			ft_sort_four(t_push *vars);
void			ft_check_f_one(int *taba, t_push *vars);
void			ft_check_f_two(int *taba, int *tabb, t_push *vars);

/*	sorter for 5 values (located in sort_five.c)	*/

void			ft_check_one(int *taba, t_push *vars);
void			ft_check_two(int *taba, int *tabb, t_push *vars);
void			ft_check_four(int *taba, int *tabb, t_push *vars);
void			ft_check_last(int *taba, t_push *vars);
void			ft_sort_five(t_push *vars);

/* tab checker (located in checker.c)	*/

int				ft_is_sorted(int *taba, int count);
int				*ft_get_tab(char **av, t_push *vars);
void			ft_tab_checker(int *tab, t_push *vars);
void			ft_is_correct(char *s);

/* tab duplicators (located in tabdups.c)	*/

int				*ft_tabdup_ra(int *tab, t_push *vars);
int				*ft_tabdup_rra(int *tab, t_push *vars);
int				*ft_tabdup_rb(int *tab, t_push *vars);
int				*ft_tabdup_rrb(int *tab, t_push *vars);
int				*ft_tabdup_s_to_b(int *tab, t_push *vars);

#endif