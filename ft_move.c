/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:31:52 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/11 17:33:25 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	px(t_list **stack_out, t_list **stack_in, char move, int toprint)
{
	t_list	*first;

	if (!stack_out || !*stack_out)
		return ;
	first = *stack_out;
	*stack_out = (*stack_out)->next;
	first->next = NULL;
	ft_lstadd_front(stack_in, first);
	if (move == 'a' && toprint)
		write(1, "pa\n", 3);
	if (move == 'b' && toprint)
		write(1, "pb\n", 3);
}

void	sx(t_list **stack_a, t_list **stack_b, char move, int toprint)
{
	if (move == 'a' || move == 's')
		swap(stack_a);
	if (move == 'b' || move == 's')
		swap(stack_b);
	if (move == 's' && toprint)
		write(1, "ss\n", 3);
	else if (move == 'a' && toprint)
		write(1, "sa\n", 3);
	else if (move == 'b' && toprint)
		write(1, "sb\n", 3);
}

void	rx(t_list **stack_a, t_list **stack_b, char move, int toprint)
{
	if (move == 'a' || move == 'r')
	{
		if (!stack_a || !*stack_a)
			return ;
		rotate(stack_a);
	}
	if (move == 'b' || move == 'r')
	{
		if (!stack_b || !*stack_b)
			return ;
		rotate(stack_b);
	}
	if (move == 'r' && toprint)
		write(1, "rr\n", 3);
	else if (move == 'a' && toprint)
		write(1, "ra\n", 3);
	else if (move == 'b' && toprint)
		write(1, "rb\n", 3);
}

void	rrx(t_list **stack_a, t_list **stack_b, char move, int toprint)
{
	if (move == 'a' || move == 'r')
	{
		if (!stack_a || !*stack_a)
			return ;
		r_rotate(stack_a);
	}
	if (move == 'b' || move == 'r')
	{
		if (!stack_b || !*stack_b)
			return ;
		r_rotate(stack_b);
	}
	if (move == 'r' && toprint)
		write(1, "rrr\n", 4);
	else if (move == 'a' && toprint)
		write(1, "rra\n", 4);
	else if (move == 'b' && toprint)
		write(1, "rrb\n", 4);
}
