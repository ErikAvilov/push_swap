/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 03:41:38 by eavilov           #+#    #+#             */
/*   Updated: 2022/05/02 10:21:07 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_one(int *taba, t_push *vars)
{
	if (taba[2] > taba[3] && taba[3] > taba[4])
	{
		ft_sa(&*vars);
		ft_rra(&*vars);
		return ;
	}
	if (taba[4] > taba[3] && taba[4] < taba[2])
		ft_ra(&*vars);
	if (taba[2] < taba[3] && taba[4] > taba[2]
		&& ft_is_sorted(&taba[2], 3) != 1)
	{
		ft_rra(&*vars);
		ft_sa(&*vars);
		return ;
	}
	if (taba[4] < taba[3] && taba[3] > taba[2])
		ft_rra(&*vars);
	if (taba[4] > taba[2] && taba[3] < taba[2])
		ft_sa(&*vars);
}

void	ft_check_two(int *taba, int *tabb, t_push *vars)
{
	if (tabb[3] > tabb[4])
		ft_sb(&*vars);
	if ((taba[3] < tabb[3] && taba[4] > tabb[4])
		|| (tabb[3] > taba[3] && tabb[3] < taba[4]))
	{
		ft_rra(&*vars);
		ft_pa(&*vars);
		ft_ra(&*vars);
		ft_ra(&*vars);
		return ;
	}
	if (tabb[3] > taba[2] && tabb[3] > taba[4])
	{
		ft_pa(&*vars);
		ft_ra(&*vars);
	}
	if (tabb[3] < taba[2])
		ft_pa(&*vars);
	if (tabb[3] > taba[2] && tabb[3] < taba[3])
	{
		ft_pa(&*vars);
		ft_sa(&*vars);
	}
}

void	ft_check_last(int *taba, t_push *vars)
{
	if (taba[4] > vars->tabb[3] && taba[4] > vars->tabb[4]
		&& vars->tabb[3] > vars->tabb[4] && taba[3] < vars->tabb[4])
	{
		ft_rra(&*vars);
		ft_pa(&*vars);
		ft_pa(&*vars);
		ft_rra(&*vars);
		ft_rra(&*vars);
		return ;
	}
}

void	ft_check_four(int *taba, int *tabb, t_push *vars)
{
	if (tabb[4] > taba[1] && tabb[4] < taba[2])
	{
		ft_pa(&*vars);
		ft_sa(&*vars);
	}
	if (tabb[4] > taba[4])
	{
		ft_pa(&*vars);
		ft_ra(&*vars);
	}
	if (tabb[4] > taba[2] && tabb[4] < taba[3])
	{
		ft_rra(&*vars);
		ft_rra(&*vars);
		ft_pa(&*vars);
		ft_rra(&*vars);
		ft_rra(&*vars);
	}
	if (tabb[4] > taba[3] && tabb[4] < taba[4])
	{
		ft_rra(&*vars);
		ft_pa(&*vars);
		ft_ra(&*vars);
		ft_ra(&*vars);
	}
}

void	ft_sort_five(t_push *vars)
{
	if (ft_is_sorted(vars->taba, 4) == 1
		&& vars->taba[4] < vars->taba[0])
	{
		ft_rra(&*vars);
		return ;
	}
	ft_pb(&*vars);
	ft_pb(&*vars);
	ft_check_one(vars->taba, &*vars);
	ft_check_last(vars->taba, &*vars);
	ft_check_two(vars->taba, vars->tabb, &*vars);
	ft_check_four(vars->taba, vars->tabb, &*vars);
	if (vars->taba[0] > vars->taba[4])
		ft_ra(&*vars);
	return ;
}
