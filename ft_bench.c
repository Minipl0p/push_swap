/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:20:27 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/13 23:03:26 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int ft_rules(const char *prev, const char *next)
{
	if (!ft_strncmp(prev,"ra", 4))
		return (!ft_strncmp(next,"ra", 4));
	if (!ft_strncmp(prev,"rb", 4))
		return (!ft_strncmp(next,"rb", 4));
	if (!ft_strncmp(prev,"rra", 4))
		return (!ft_strncmp(next,"rra", 4)||!ft_strncmp(next,"rb", 4));
	if (!ft_strncmp(prev,"rrb", 4))
		return (!ft_strncmp(next,"rrb", 4)||!ft_strncmp(next,"ra", 4));
	if (!ft_strncmp(prev,"rr", 4))
		return (!ft_strncmp(next,"rr", 4)||!ft_strncmp(next,"ra", 4)||!ft_strncmp(next,"rb", 4));
	if (!ft_strncmp(prev,"rrr", 4))
		return (!ft_strncmp(next,"rrr", 4)||!ft_strncmp(next,"rrb", 4)||!ft_strncmp(next,"rra", 4));
	return 0;
}

void ft_benchmark(char seq[][4], int depth, t_data init, int *count)
{
	int i;
	int	j;

	j = -1;
	while (++j < depth)
		// printf("%s ", seq[j]);
	// printf("\n");
	(*count)++;
	if (depth == init.max_depth)
		return;
	i = -1;
	while (++i < 6)
	{
		if (depth == 0 || ft_rules(seq[depth - 1], init.moves[i]))
		{
			ft_strcpy(seq[depth], init.moves[i]);
			ft_benchmark(seq, depth + 1, init, count);
		}
	}
}

int main(int ac, char **av)
{
	ac++;
	int max = atoi(av[1]); // profondeur max
	int count = 0;
	char seq[max + 1][4]; // tableau pour stocker la séquence
	t_data	init;
	init.moves = ft_split("ra rb rra rrb rr rrr", ' ');
	init.max_depth = max;
	ft_benchmark(seq, 0, init, &count);
	printf("Nombre total de combinaisons: %d\n", count);
	return 0;
}
