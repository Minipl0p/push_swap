/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:11:17 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/13 18:09:24 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_lstprint(void *content)
{
	if (!content)
		return ;
	ft_printf("%d\n", ((t_content *)content)->value);
}

t_list	*ft_do_lst(int ac, char **av)
{
	char	*str;
	t_list	*lst;

	str = ft_pars(ac, av);
	if (!str)
		return (NULL);
	lst = ft_init_lst(str);
	if (!ft_check_double(lst))
		return (NULL);
	return (lst);
}

int	main(int ac, char **av)
{
	t_list		*stack_a;

	if (ac < 2)
		return (1);
	stack_a = ft_do_lst(ac, av);
	if (!stack_a)
	{
		ft_puterror();
		return (1);
	}
	t_list	*stack_b;
	stack_b = NULL;
	char *order;
	order = malloc(10000);
	ft_bench(order, &stack_a, &stack_b, 4, 0);
	free(order);
	/*
	*while (stack_a is ordered){ 
	* simuler tous les moves possible avec une profondeur de X
	* calculer le score de chaque sequence
	* executer la sequence}
	*/  
/*	px(&stack_a, &stack_b, 'b', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	px(&stack_a, &stack_b, 'b', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	px(&stack_a, &stack_b, 'b', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	px(&stack_a, &stack_b, 'b', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	rx(&stack_a, &stack_b, 'a', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	rx(&stack_a, &stack_b, 'b', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	rx(&stack_a, &stack_b, 'r', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	px(&stack_b, &stack_a, 'a', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	rrx(&stack_a, &stack_b, 'a', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	rrx(&stack_a, &stack_b, 'b', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
	
	rrx(&stack_a, &stack_b, 'r', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);

	sx(&stack_a, &stack_b, 'a', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);

	sx(&stack_a, &stack_b, 'b', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);

	sx(&stack_a, &stack_b, 's', 1);
	write(1, "stack_a :\n", 10);
	ft_lstiter(stack_a, ft_lstprint);
	write(1, "stack_b :\n", 10);
	ft_lstiter(stack_b, ft_lstprint);
*/
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
