/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: TonLogin42 <ton.login@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:25:09 by TonLogin42        #+#    #+#             */
/*   Updated: 2025/11/13 02:09:20 by TonLogin42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

void ft_exec(t_data *data, int toprint) {
  (void)data->stack_a;
  (void)data->stack_b;
}

void quaternary_restrict(t_data *data, int pos, int min, int has_two) {
  static t_item *item = NULL;
  int i;
  int limit;
  int score;

  if (pos == data->depth) {
    data->str[pos] = '\0';
    ft_exec(data, 0);
    score = ft_scoring(data->stack_a, data->stack_b);
    if (!item || score > item->score) {
      item->score = score;
      item->order = data->str;
    }
    return;
  }
  if (has_two)
    limit = 3;
  else
    limit = 4;
  i = min - 1;
  while (++i < limit) {
    data->str[pos] = '0' + i;
    if (i == 2)
      quaternary_restrict(data, pos + 1, i, 1);
    else
      quaternary_restrict(data, pos + 1, i, 0);
  }
}

int main(int ac, char **av) {
  int i;
  char *order;
  int score;
  t_item *best;

  ac++;
  order = 0;
  i = 0;
  best = NULL;
  while (i < atoi(av[1])) {
    if (!best || score > best->score) {
      best->score = score;
      best->order = order;
    }
    i++;
  }
}
