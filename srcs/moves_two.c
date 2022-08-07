/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:00:20 by eavilov           #+#    #+#             */
/*   Updated: 2022/05/02 07:01:31 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_push *vars)
{
	vars->taba = ft_tabdup_ra(vars->taba, &*vars);
	ft_putstr("ra\n");
}

void	ft_rb(t_push *vars)
{
	vars->tabb = ft_tabdup_rb(vars->tabb, &*vars);
	ft_putstr("rb\n");
}

void	ft_rra(t_push *vars)
{
	vars->taba = ft_tabdup_rra(vars->taba, &*vars);
	ft_putstr("rra\n");
}

void	ft_rrb(t_push *vars)
{
	vars->tabb = ft_tabdup_rrb(vars->tabb, &*vars);
	ft_putstr("rrb\n");
}
