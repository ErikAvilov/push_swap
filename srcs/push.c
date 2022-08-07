/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 09:07:43 by eavilov           #+#    #+#             */
/*   Updated: 2022/05/09 15:20:39 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_printbit(int nb)
{
	int		i;
	int		checker;
	char	*str;

	i = 8192;
	checker = 0;
	if (nb == 0)
		return ("000");
	str = malloc(sizeof(char) * 32);
	while (i)
	{
		if (i <= nb)
		{
			nb = nb % i;
			str[checker] = '1';
			checker++;
		}
		else if (checker > 0)
			str[checker++] = '0';
		i = i / 2;
	}
	str[checker] = '\0';
	return (str);
}

void	ft_sort_vsmall(t_push *vars)
{
	if (vars->taba[0] > vars->taba[1] && vars->taba[0] < vars->taba[2])
		ft_sa(&*vars);
	if (vars->taba[0] > vars->taba[1] && vars->taba[1] > vars->taba[2])
	{
		ft_sa(&*vars);
		ft_rra(&*vars);
		return ;
	}
	if (vars->taba[0] > vars->taba[1] && vars->taba[1] < vars->taba[2])
		ft_ra(&*vars);
	if (vars->taba[2] < vars->taba[1] && vars->taba[2] < vars->taba[0])
		ft_rra(&*vars);
	if (vars->taba[0] < vars->taba[1] && vars->taba[1] > vars->taba[2])
	{
		ft_sa(&*vars);
		ft_ra(&*vars);
		return ;
	}
}

int	ft_max_bit(t_push *vars)
{
	char	*biggest;
	int		i;

	i = 0;
	biggest = NULL;
	biggest = (ft_printbit(vars->tabc[vars->count - 1]));
	i = ft_strlen(biggest);
	free(biggest);
	return (i);
}

void	ft_radix(t_push *vars)
{
	int	k;
	int	i;
	int	limit;
	int	count;

	i = 0;
	count = 0;
	limit = ft_max_bit(&*vars);
	while (count < limit)
	{
		while (i != vars->count)
		{
			k = (vars->taba[vars->usage] >> count) & 1;
			if (k == 0)
				ft_pb(&*vars);
			else
				ft_ra(&*vars);
			i++;
		}
		while (vars->usage)
			ft_pa(&*vars);
	i = 0;
	count++;
	}
}

void	ft_push_swap(t_push *vars)
{
	if (ft_is_sorted(vars->taba, vars->count) == 1)
		return ;
	if (vars->count == 2 && vars->taba[0] > vars->taba[1])
	{
		ft_sa(&*vars);
		return ;
	}
	if (vars->count == 3)
		ft_sort_vsmall(&*vars);
	if (vars->count == 4)
		ft_sort_four(&*vars);
	if (vars->count == 5)
		ft_sort_five(&*vars);
	if (vars->count > 5 && vars->count <= 500)
		ft_radix(&*vars);
	return ;
}
