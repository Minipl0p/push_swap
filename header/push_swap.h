/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 19:29:36 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/14 12:28:39 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"


typedef struct s_item {
	char *order;
	int score;
} t_item;

typedef struct s_data {
	int depth;
	char *str;
	t_list *stack_a;
	t_list *stack_b;
} t_data;

typedef struct s_recursive
{
	char **moves;
	int		max_depth;
}				t_recursive;

typedef struct s_content
{
	int	value;
}				t_content;

//Pars utils
char	*ft_join_wish(int ac, char **av);
t_list	*ft_init_lst(char *str);
int		ft_check_double(t_list *lst);
void	ft_skip_space(char *join, int *i);
char	*ft_skip_char(char *str, char c, int in_out);
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

//Bench utils
void	ft_bench(char *order, t_list **stack_a, t_list **stack_b, int deep, int pos);

#endif // !PUSH_SWAP_H
