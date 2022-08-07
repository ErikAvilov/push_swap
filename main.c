/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavilov <eavilov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 09:17:38 by eavilov           #+#    #+#             */
/*   Updated: 2022/05/05 12:11:44 by eavilov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push	vars;

	(void) ac;
	ft_initiate(&vars, av);
	if (ft_is_sorted(vars.taba, vars.count) == 1)
		ft_func_exit(NULL);
	ft_push_swap(&vars);
	free(vars.taba);
	free(vars.tabb);
	free(vars.tabc);
}
