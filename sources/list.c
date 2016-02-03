/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:20:20 by bsouchet          #+#    #+#             */
/*   Updated: 2016/02/03 19:58:48 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_file		ft_sequence(char **s, t_file f, t_pos *pos, int height)
{
	while (f.y <= f.m && s[f.y][0] != 0)
	{
		f.x = 0;
		while (s[f.y][f.x] != 0)
		{
			if (s[f.y][f.x] == 35)
				f.h++;
			if (s[f.y][f.x] == 35 && f.x < pos->x)
				pos->x = f.x;
			if (s[f.y][f.x] == 35 && f.x > pos->y)
				pos->y = f.x;
			f.x++;
		}
		if (f.h > height && f.l++ > -1)
			height = f.h;
		if (f.h < 4)
			f.c++;
		f.y++;
	}
	return (f);
}

static t_tetri		*ft_add_next(t_tetri *list, t_tetri *shape)
{
	t_tetri *head;

	head = list;
	if (list == NULL)
		return (shape);
	while (list->nxt != NULL)
		list = list->nxt;
	list->nxt = shape;
	return (head);
}

t_tetri				*ft_stock(char **s, t_file f, int i)
{
	t_pos	pos;
	t_tetri	*list;
	t_tetri	*shape;

	list = NULL;
	while (f.y <= f.m)
	{
		if (!(shape = (t_tetri *)malloc(sizeof(t_tetri))))
			return (NULL);
		pos.x = 50;
		pos.y = 0;
		f.h = 0;
		f.l = 0;
		f.c = 1;
		f = ft_sequence(s, f, &pos, 0);
		shape->idx = i++;
		shape->y = (f.y + (f.c - f.l)) - 4;
		shape->x = pos.x;
		shape->h = f.l;
		shape->w = (pos.y + 1) - pos.x;
		shape->nxt = NULL;
		list = ft_add_next(list, shape);
		f.y++;
	}
	return (list);
}
