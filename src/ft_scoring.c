/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:31:22 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/14 12:27:30 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"
#include "../header/push_swap.h"

int	ft_break_count(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp;
	int		nb_break_a;
	int		nb_break_b;
	int		score;

	tmp = stack_a;
	nb_break_a = 0;
	nb_break_b = 0;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			nb_break_a++;
		tmp = tmp->next;
	}
	tmp = stack_b;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			nb_break_b++;
		tmp = tmp->next;
	}
	score = nb_break_a + nb_break_b;
	return (score);
}

void	ft_scoring(char *order, t_item *best, t_list *stack_a, t_list *stack_b)
{
	int	score;

	score = ft_break_count(stack_a, stack_b);
	if (!best || best->score < score)
	{
		best->score = score;
		best->order = order;
	}
}
