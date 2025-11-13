/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:04:59 by tseche            #+#    #+#             */
/*   Updated: 2025/11/13 14:19:00 by tseche           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOOKUP_H
# define LOOKUP_H
# include "push_swap.h"



typedef void (* t_call)(t_list **stack_out, t_list **stack_in, char move, int toprint);

typedef	struct s_lookup{
	char	*kind;
	t_call	callback;
} t_lookup;

#endif
