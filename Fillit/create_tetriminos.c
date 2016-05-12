/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetriminos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 15:17:02 by maxpetit          #+#    #+#             */
/*   Updated: 2016/03/15 14:49:53 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int		ft_tetri_size(t_list *list)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((i < 4))
	{
		if (list->shape[i] != 0)
			j++;
		i++;
	}
	return (j);
}

t_list	*ft_create_elem(t_list *list, int *nb, char letter)
{
	t_list	*elem;
	int		i;

	i = 0;
	elem = list;
	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (0);
	while (i < 4)
	{
		elem->shape[i] = nb[i];
		i++;
	}
	elem->ordonnee = 0;
	elem->pos = letter;
	elem->size = ft_tetri_size(elem);
	elem->option = PASPLACE;
	elem->next = NULL;
	return (elem);
}

void	ft_list_pushback(t_list **list, int *nb, char letter)
{
	t_list *tmp;

	if (list && *list)
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(tmp, nb, letter);
	}
	else
	{
		tmp = *list;
		*list = ft_create_elem(tmp, nb, letter);
	}
}

void	ft_get_tetri(char *buf, t_list **tetri)
{
	int			i;
	int			j;
	int			nb[4];
	static int	letter = 0;

	i = 0;
	j = 0;
	while (i < 20)
	{
		nb[j] = 0;
		while (((i + 1) % 5) != 0)
		{
			if (buf[i] == '#')
			{
				nb[j] = nb[j] + (1 << (4 - (i + 1) % 5));
			}
			i++;
		}
		i++;
		j++;
	}
	letter++;
	ft_list_pushback(tetri, nb, letter);
}
