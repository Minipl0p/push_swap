/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bench.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 16:20:27 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/13 18:04:13 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data
{
	char **moves;
	int		max_depth;
}				t_data;

int ft_rules(const char *prev, const char *next)
{
	if (!strcmp(prev,"ra"))
		return (!strcmp(next,"ra"));
	if (!strcmp(prev,"rb"))
		return (!strcmp(next,"rb"));
	if (!strcmp(prev,"rra"))
		return (!strcmp(next,"rra")||!strcmp(next,"rb"));
	if (!strcmp(prev,"rrb"))
		return (!strcmp(next,"rrb")||!strcmp(next,"ra"));
	if (!strcmp(prev,"rr"))
		return (!strcmp(next,"rr")||!strcmp(next,"ra")||!strcmp(next,"rb"));
	if (!strcmp(prev,"rrr"))
		return (!strcmp(next,"rrr")||!strcmp(next,"rrb")||!strcmp(next,"rra"));
	return 0;
}

void ft_benchmark(char seq[][4], int depth, t_data init, int *count)
{
	int i;
	int	j;

	j = -1;
	while (++j < depth)
		printf("%s ", seq[j]);
	printf("\n");
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
