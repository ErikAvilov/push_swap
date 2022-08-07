/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:04:49 by eavilov           #+#    #+#             */
/*   Updated: 2022/05/09 11:51:57 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_is_correct(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_atoi(s) < -2147483648
			|| ft_atoi(s) > 2147483647)
			ft_func_exit("Error\n");
		else if (ft_strncmp(s, "-0", 2) == 0)
			break ;
		else if (s[i] < 48 || s[i] > 57)
		{
			if (ft_atoi(&s[i]) < 0)
				break ;
			ft_func_exit("Error\n");
		}
		i++;
	}
}

int	*ft_get_tab(char **av, t_push *vars)
{
	int		i;
	int		*tab;
	int		index;
	char	**array;

	tab = malloc(sizeof(int) * 999999);
	i = 0;
	index = -1;
	while (av[++i])
	{
		array = ft_split(av[i], ' ');
		if (!array[0])
			ft_func_exit("Error\n");
		while (array[++index])
		{
			ft_is_correct(array[index]);
			tab[vars->count] = ft_atoi(array[index]);
			vars->count++;
		}
		ft_freesbee(array);
		index = -1;
	}
	return (tab);
}

void	ft_tab_checker(int *tab, t_push *vars)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (j != vars->count)
	{
		i = j;
		while ((i + 1) < vars->count)
		{
			if (tab[j] == tab[i + 1])
			{
				free(tab);
				ft_func_exit("Error\n");
			}
			i++;
		}
		j++;
	}
}

int	ft_is_sorted(int *taba, int count)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i != count - 1)
	{
		if (taba[i] < taba[i + 1] && i + 1 != count)
			check++;
		i++;
	}
	if (check == count - 1)
		return (1);
	else
		return (0);
}
