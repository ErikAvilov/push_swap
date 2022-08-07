/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:03:13 by eavilov           #+#    #+#             */
/*   Updated: 2022/05/09 11:45:23 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_initiate(t_push *vars, char **av)
{
	int	i;

	i = 0;
	if (!av[1])
		exit(0);
	vars->usage = 0;
	vars->count = 0;
	vars->half = vars->count / 2;
	vars->taba = ft_get_tab(av, &*vars);
	vars->tabb = malloc(sizeof(int) * vars->count);
	ft_tab_checker(vars->taba, &*vars);
	vars->tabc = ft_tabdup_s_to_b(vars->taba, &*vars);
	ft_index_remake(&*vars);
	free(vars->tabc);
	vars->tabc = ft_tabdup_s_to_b(vars->taba, &*vars);
}

void	ft_func_exit(char *s)
{
	if (!s)
		exit (0);
	write (2, s, ft_strlen(s));
	exit (EXIT_SUCCESS);
}

int	ft_smallest(t_push *vars, int *tab)
{
	int	i;
	int	index;

	i = tab[0];
	index = 0;
	while (index != vars->count - vars->usage)
	{
		if (i > tab[index])
			i = tab[index];
		index++;
	}
	return (i);
}

int	ft_index_find(int *tab, int nb, t_push *vars)
{
	int	i;

	i = 0;
	while (i != vars->count)
	{
		if (tab[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

void	ft_index_remake(t_push *vars)
{
	int	i;

	i = 0;
	while (i != vars->count)
	{
		vars->taba[i] = ft_index_find(vars->tabc, vars->taba[i], &*vars);
		i++;
	}
	return ;
}
