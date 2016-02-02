/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 10:40:50 by bsouchet          #+#    #+#             */
/*   Updated: 2016/02/02 14:19:05 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		*ft_perm_next(int *n, int count, int i, int j)
{
	int		tail;

	if (count <= 1)
		return (NULL);
	i = count - 1;
	while (i > 0 && n[i - 1] >= n[i])
		i--;
	tail = i;
	if (tail > 0)
	{
		j = count - 1;
		while (j > tail && n[j] <= n[tail - 1])
			j--;
		ft_swap(n, tail - 1, j);
	}
	i = tail;
	j = count - 1;
	while (i < j)
		ft_swap(n, i++, j--);
	if (tail != 0)
		return (n);
	return (NULL);
}

static int		*ft_set_value(int *dest, int *source, int size, int i)
{
	while (i < size)
	{
		if (dest == source)
			dest[i] = i;
		else
			dest[i] = source[i];
		i++;
	}
	return (dest);
}

static int		*ft_compare(int *tmp, int *perm, int nshape, int max)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i == j && nshape < max)
	{
		while (tmp[i] != nshape && i < max)
			i++;
		while (perm[j] != nshape && j < max)
			j++;
		if (tmp[0] == -1)
			i = j + 1;
		if (i > j)
			return (ft_set_value(tmp, perm, max, 0));
		else if (i < j)
			return (tmp);
		nshape++;
	}
	return (tmp);
}

static char		**ft_perm(char **tab, char **dest, t_tetri *list, t_file f)
{
	int		*tmp;

	if (!(tmp = (int *)malloc(sizeof(int) * f.nshape)))
		return (NULL);
	if (!(f.perm = (int *)malloc(sizeof(int) * f.nshape)))
		return (NULL);
	tmp[0] = -1;
	f.perm = ft_set_value(f.perm, f.perm, f.nshape, 0);
	if ((dest = ft_exec(tab, list, f, ft_square(f.s, 0, 0))))
		return (dest);
	else
	{
		while ((f.perm = ft_perm_next(f.perm, f.nshape, 0, 0)) != NULL)
		{
			if ((dest = ft_exec(tab, list, f, ft_square(f.s, 0, 0))))
				tmp = ft_compare(tmp, f.perm, 0, f.nshape);
		}
		if (tmp[0] != -1)
		{
			f.perm = tmp;
			return (ft_exec(tab, list, f, ft_square(f.s, 0, 0)));
		}
	}
	return (NULL);
}

void			ft_resolve(char **tab, t_file f, char **dest)
{
	t_tetri	*list;

	while (f.s * f.s < ((((f.m + 1) / 5) + 1) * 4))
		f.s++;
	f.nshape = ((f.m + 1) / 5) + 1;
	f.y = 0;
	list = ft_stock(tab, f, 0);
	while (!(dest))
	{
		dest = ft_perm(ft_alpha(tab, f), ft_square(f.s, 0, 0), list, f);
		f.s++;
	}
	ft_print(dest, f);
}
