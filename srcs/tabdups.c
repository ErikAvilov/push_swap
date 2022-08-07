/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tabdups.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:01:03 by eavilov           #+#    #+#             */
/*   Updated: 2022/05/02 12:42:12 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ft_tabdup_ra(int *tab, t_push *vars)
{
	int		*res;
	int		i;

	i = 0;
	res = malloc(sizeof(int) * vars->count);
	if (!res)
		ft_func_exit("malloc failed\n");
	while (i != vars->usage)
	{
		res[i] = -42;
		i++;
	}
	while (i != vars->count)
	{
		res[i] = tab[i + 1];
		i++;
		if ((i + 1) == vars->count)
		{
			res[i] = tab[vars->usage];
			break ;
		}
	}
	free(tab);
	return (res);
}

int	*ft_tabdup_rra(int *tab, t_push *vars)
{
	int		*res;
	int		i;

	i = 0;
	res = malloc(sizeof(int) * vars->count);
	if (!res)
		ft_func_exit("malloc failed\n");
	while (i != vars->usage)
	{
		res[i] = -42;
		i++;
	}
	res[i++] = tab[vars->count - 1];
	while (i != vars->count)
	{
		res[i] = tab[i - 1];
		i++;
	}
	free(tab);
	return (res);
}

int	*ft_tabdup_rb(int *tab, t_push *vars)
{
	int		*res;
	int		i;
	int		calc;

	i = 0;
	calc = vars->count - vars->usage;
	res = malloc(sizeof(int) * vars->count);
	if (!res)
		ft_func_exit("malloc failed\n");
	while (i != calc)
	{
		res[i] = -42;
		i++;
	}
	while (i != vars->count - 1)
	{
		res[i] = tab[i + 1];
		i++;
	}
	free(tab);
	return (res);
}

int	*ft_tabdup_rrb(int *tab, t_push *vars)
{
	int		*res;
	int		i;
	int		clc;

	i = 0;
	clc = vars->count - vars->usage;
	res = malloc(sizeof(int) * vars->count);
	if (!res)
		ft_func_exit("malloc failed\n");
	while (i != clc)
	{
		res[i] = -42;
		i++;
	}
	res[i++] = tab[vars->count - 1];
	while (i != vars->count)
	{
		res[i] = tab[i - 1];
		i++;
	}
	free(tab);
	return (res);
}

int	*ft_tabdup_s_to_b(int *tab, t_push *vars)
{
	int		*res;
	int		i;
	int		h;

	i = -1;
	h = -1;
	res = malloc(sizeof(int) * vars->count);
	while (i != vars->count)
		res[++h] = tab[++i];
	i = 0;
	while (ft_is_sorted(res, vars->count) != 1)
	{
		i = 0;
		while (i != vars->count - 1)
		{
			if (res[i] > res[i + 1])
				ft_swap(&res[i], &res[i + 1]);
			i++;
		}
	}
	return (res);
}
