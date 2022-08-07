/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:20:50 by eavilov           #+#    #+#             */
/*   Updated: 2022/04/27 02:18:24 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check_f_one(int *taba, t_push *vars)
{
	if (ft_is_sorted(&taba[1], 3) == 1)
		return ;
	if (taba[1] > taba[2] && taba[2] > taba[3])
	{
		ft_sa(&*vars);
		ft_rra(&*vars);
		return ;
	}
	if (taba[3] > taba[2] && taba[3] < taba[1])
		ft_ra(&*vars);
	if (taba[1] < taba[2] && taba[3] > taba[1])
	{
		ft_rra(&*vars);
		ft_sa(&*vars);
		return ;
	}
	if (taba[3] < taba[2] && taba[2] > taba[1])
		ft_rra(&*vars);
	if (taba[3] > taba[1] && taba[2] < taba[1])
		ft_sa(&*vars);
}

void	ft_check_f_two(int *taba, int *tabb, t_push *vars)
{
	if (taba[3] < tabb[3])
	{
		ft_pa(&*vars);
		ft_ra(&*vars);
	}
	if (taba[1] > tabb[3])
		ft_pa(&*vars);
	if (tabb[3] > taba[2] && tabb[3] < taba[3])
	{
		ft_rra(&*vars);
		ft_pa(&*vars);
		ft_rra(&*vars);
		ft_rra(&*vars);
	}
	if (tabb[3] > taba[1] && tabb[3] < taba[2])
	{
		ft_pa(&*vars);
		ft_sa(&*vars);
	}
}

void	ft_sort_four(t_push *vars)
{
	if (ft_is_sorted(&vars->taba[1], 3) == 1
		&& vars->taba[0] > vars->taba[3])
	{
		ft_ra(&*vars);
		return ;
	}
	if (ft_is_sorted(vars->taba, 3) == 1
		&& vars->taba[3] < vars->taba[0])
	{
		ft_rra(&*vars);
		return ;
	}
	ft_pb(&*vars);
	ft_check_f_one(vars->taba, &*vars);
	ft_check_f_two(vars->taba, vars->tabb, &*vars);
}
