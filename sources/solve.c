/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:00:00 by bsouchet          #+#    #+#             */
/*   Updated: 2016/02/02 14:21:02 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		**ft_place(char **tab, char **dst, t_tetri *list, t_file f)
{
	t_tetri shape;

	f.l = 0;
	f.y = f.j;
	shape = *list;
	f.c = shape.x;
	while (f.y < f.s && f.l < (shape.w * shape.h) && (shape.x = f.c) < 10)
	{
		f.h = 0;
		f.x = f.i;
		while (dst[f.y][f.x] != '\0' && f.h < shape.w)
		{
			if (tab[shape.y][shape.x] != 46)
				dst[f.y][f.x] = tab[shape.y][shape.x];
			if ((f.l++ + f.h++ + shape.x++) < 100)
				f.x++;
		}
		f.y++;
		shape.y++;
	}
	return (dst);
}

static int		ft_shape(char **tab, char **dest, t_tetri *list, t_file f)
{
	t_tetri	shape;

	f.l = 0;
	f.y = f.j;
	shape = *list;
	f.c = shape.x;
	while (f.y < f.s && f.l < (shape.w * shape.h) && (f.h = 0) > -1)
	{
		f.x = f.i;
		shape.x = f.c;
		while (dest[f.y][f.x] != '\0' && f.h < shape.w)
		{
			if (dest[f.y][f.x] != 46 && tab[shape.y][shape.x] != 46)
				return (0);
			if ((f.l++ + f.h++ + shape.x++) > -1)
				f.x++;
		}
		if (f.h < shape.w)
			return (0);
		f.y++;
		shape.y++;
	}
	if (f.l == (shape.w * shape.h))
		return (1);
	return (0);
}

static char		**ft_slv(char **tab, char **dst, t_tetri *list, t_file f)
{
	f.c = 0;
	f.j = 0;
	while (f.j < f.s)
	{
		f.i = 0;
		while (dst[f.j][f.i] != '\0')
		{
			if (dst[f.j][f.i] != 46 && tab[list->y][list->x] != 46)
				;
			else if ((f.c = f.c + ft_shape(tab, dst, list, f)) == f.t)
				return (ft_place(tab, ft_double_strdup(dst, f), list, f));
			f.i++;
		}
		f.j++;
	}
	return (dst);
}

static char		**ft_del(char **tab, t_file f)
{
	f.y = 0;
	f.c = 0;
	while (f.y < f.s && f.c < 4)
	{
		f.x = 0;
		while (tab[f.y][f.x] != '\0' && f.c < 4)
		{
			if (tab[f.y][f.x] == 65 + f.perm[f.k] && f.c++ > -1)
				tab[f.y][f.x] = 46;
			f.x++;
		}
		f.y++;
	}
	return (tab);
}

char			**ft_exec(char **tab, t_tetri *list, t_file f, char **dst)
{
	t_tetri	*shp;

	while (++f.k < f.nshape)
	{
		shp = list;
		while (shp->idx < f.perm[f.k])
			shp = shp->nxt;
		if (f.t != 1 && (dst = ft_del(dst, f)) != NULL)
		{
			while (ft_slv(tab, dst, shp, f) == dst && f.t < f.s)
				f.t++;
			if (f.t == f.s)
				return (NULL);
			dst = ft_slv(tab, dst, shp, f);
			f.t = 1;
		}
		else if (COND1 && f.t == 1 && (f.k -= 2) > -5 && (f.t = f.a++) > -10)
		{
			if (f.k == -2)
				return (NULL);
		}
		else if (COND2)
			dst = ft_slv(tab, dst, shp, f);
	}
	return (dst);
}
