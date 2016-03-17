/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoly <djoly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:43:49 by djoly             #+#    #+#             */
/*   Updated: 2016/03/16 16:46:01 by djoly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/push_swap.h"

int		chr_forward(int data, t_node *node)
{
	int	i;
	t_node	*tmp;

	tmp = node;
	i = 0;
	while (tmp->data < data && data > tmp->next->data && tmp->data < tmp->next->data)
	{
		tmp = tmp->next;
		i++:
	}
	return (i);
}

int		chr_back(int data, t_node *node)
{
	int	i;
	t_node	*tmp;

	tmp = node;
	i = 0;
	while (tmp->prev->data < data && data > tmp->data && tmp->prev->data < tmp->data)
	{
		tmp = tmp->prev;
		i++:
	}
	return (i);
}

int		which_behavior(int f[])
{
	if (f[0] < f[1] && f[0] < f[2] && f[0] < f[3])
		return (0);
	if (f[0] > f[1] && f[1] < f[2] && f[1] < f[3])
		return (1);
	if (f[2] < f[1] && f[0] > f[2] && f[2] < f[3])
		return (2);
	if (f[3] < f[1] && f[3] < f[2] && f[0] > f[3])
		return (3);
}

int		solve(t_pile *pile_a, t_pile *pile_b)
{
	int	f[4];

	f[0] = chr_forward(pile_a->beg->data, pile_b->beg);
	f[1] = chr_back(pile_a->beg->data, pile_b->last);
	if (pile_a->beg->next != NULL)
	{
		f[2] = chr_forward(pile_a->beg->next->data, pile_b->beg);
		f[3] = chr_back(pile_a->beg->next->data, pile_b->last);
	}
	push(pile_a, pile_b, which_behavior(f[]));
}
