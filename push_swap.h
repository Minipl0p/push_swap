/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:29:36 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/11 17:33:54 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_content
{
	int	value;
}				t_content;

//Pars utils
char	*ft_join_wish(int ac, char **av);
t_list	*ft_init_lst(char *str);
int		ft_check_double(t_list *lst);
void	ft_skip_space(char *join, int *i);
void	ft_free_clear(t_list *lst, t_content *content);
char	*ft_pars(int ac, char **av);

//Move utils
void	swap(t_list **stack);
void	rotate(t_list **stack);
void	r_rotate(t_list **stack);
void	rrx(t_list **stack_a, t_list **stack_b, char move, int toprint);
void	rx(t_list **stack_a, t_list **stack_b, char move, int toprint);
void	sx(t_list **stack_a, t_list **stack_b, char move, int toprint);
void	px(t_list **stack_out, t_list **stack_in, char move, int toprint);

#endif // !PUSH_SWAP_H
