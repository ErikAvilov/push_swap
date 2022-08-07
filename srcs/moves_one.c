/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:00:22 by eavilov           #+#    #+#             */
/*   Updated: 2022/04/27 02:20:21 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_push *vars)
{
	if (vars->usage < 0)
		vars->usage = 0;
	ft_swap(&vars->taba[vars->usage], &vars->taba[vars->usage + 1]);
	ft_putstr("sa\n");
}

void	ft_sb(t_push *vars)
{
	int	clc;

	clc = vars->count - vars->usage;
	ft_swap(&vars->tabb[clc], &vars->tabb[clc + 1]);
	ft_putstr("sb\n");
}

void	ft_pa(t_push *vars)
{
	int	clc;

	clc = vars->count - vars->usage;
	ft_swap(&vars->tabb[clc], &vars->taba[vars->usage - 1]);
	vars->usage--;
	vars->half = (vars->count - vars->usage) / 2;
	ft_putstr("pa\n");
}

void	ft_pb(t_push *vars)
{
	if (vars->usage < 0)
		vars->usage = 0;
	ft_swap(&vars->taba[vars->usage],
		&vars->tabb[vars->count - vars->usage - 1]);
	vars->usage++;
	vars->half = (vars->count - vars->usage) / 2;
	ft_putstr("pb\n");
}
