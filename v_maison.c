/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_maison.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tseche <tseche@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:25:09 by TonLogin42        #+#    #+#             */
/*   Updated: 2025/11/14 00:07:15 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft/libft.h"
#include "push_swap.h"
#include "lookup.h"

const	t_lookup call_table[];
call_table = {{"ra", &rx}, {"rb", &rx}, {"rr", &rrx}, {"rra", &rrx}, {"rrb", &rrx},{"rrr", &rrx}, {"pa", &px}, {"pb", &px},
};

void ft_exec(t_data *data, int toprint)
{
	t_call	fn;
	char	**split;

	split = ft_split(data->str, ' ');
	while (*split)
	{
		fn = call_table;
		if (!fn)
			ft_printf("ERROR: %s don't recognized", *split);
		fn(args);
	}
  (void)data->stack_a;
  (void)data->stack_b;
}

int main(int ac, char **av)
{
	t_data *data;

	ac++;
	data = malloc(sizeof(t_data));
	data->depth = atoi(av[1]);
	data->str = strdup("0123");
	free(data->str);
	free(data);
	return (0);
}
