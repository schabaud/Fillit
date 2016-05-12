/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxpetit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 14:48:53 by maxpetit          #+#    #+#             */
/*   Updated: 2016/03/16 20:00:31 by maxpetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"

int		g_tetriminos;

int		ft_checklen(char *buf, int *i)
{
	if (*i == 19)
	{
		*i = 0;
		return (buf[19] == '\n') ? 0 : 1;
	}
	if (buf[*i] == '\n')
	{
		*i += 5;
		return (ft_checklen(buf, i));
	}
	else
		return (1);
}

int		ft_checkblock(char *buf, int i)
{
	static int count = 0;
	static int touch = 0;

	if (i == 19)
	{
		if (count == 4 && touch >= 6)
		{
			count = 0;
			touch = 0;
			return (0);
		}
		else
			return (1);
	}
	if (buf[i] == '#')
	{
		touch = touch + ft_checkcontact(buf, i);
		count++;
	}
	i++;
	return (ft_checkblock(buf, i));
}

int		ft_checkpattern(char *buf, int i)
{
	if (i == 20)
		return (0);
	if (buf[i] == '.' || buf[i] == '#' || buf[i] == '\n')
	{
		i++;
		return (ft_checkpattern(buf, i));
	}
	else
		return (1);
}

int		ft_checkcontact(char *buf, char c)
{
	int touch;

	touch = 0;
	if (buf[c + 1] == '#')
		touch++;
	if (buf[c + 5] == '#')
		touch++;
	if (buf[c - 1] == '#')
		touch++;
	if (buf[c - 5] == '#')
		touch++;
	return (touch);
}

int		ft_checkfile(char *file, t_list **list)
{
	int		fd;
	int		i;
	char	buf;
	char	square[20];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	while (read(fd, square, 20) == 20 && g_tetriminos < 26)
	{
		i = 4;
		if (ft_checklen(square, &i) || (ft_checkpattern(square, i))
		|| (ft_checkblock(square, i)))
			return (1);
		i = read(fd, &buf, 1);
		if (i == 1 && buf != '\n')
			return (1);
		ft_get_tetri(square, list);
		if (i == 0)
			return (0);
		g_tetriminos += 1;
	}
	close(fd);
	return (1);
}
