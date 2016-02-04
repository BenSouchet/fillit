/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:20:30 by bsouchet          #+#    #+#             */
/*   Updated: 2016/02/04 13:45:59 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_double_strdup(char **s, t_file f)
{
	char	**dest;

	f.y = 0;
	while (!(dest = (char **)malloc(sizeof(char *) * f.s)))
		;
	while (f.y < f.s)
	{
		f.x = 0;
		if (!(dest[f.y] = (char *)malloc(sizeof(char) * 64)))
			return (NULL);
		while (s[f.x] != 0)
		{
			dest[f.y][f.x] = s[f.y][f.x];
			f.x++;
		}
		dest[f.y][f.x] = 0;
		f.y++;
	}
	return (dest);
}

char	**ft_alpha(char **s, t_file f)
{
	f.l = 65;
	f.c = 0;
	f.y = 0;
	f.x = 0;
	while (f.y <= f.m)
	{
		if (s[f.y][f.x] == 35 && ++f.c != 0)
			s[f.y][f.x] = (char)f.l;
		f.x++;
		if (s[f.y][f.x] == 0 && ++f.y != 0)
			f.x = 0;
		if (f.c == 4 && (f.c = 0) == 0)
			f.l++;
	}
	return (s);
}

void	ft_print(char **tab, t_file f)
{
	f.y = 0;
	while (f.y < f.s - 1)
	{
		f.x = 0;
		while (tab[f.y][f.x] != 0)
			write(1, &tab[f.y][f.x++], 1);
		write(1, "\n", 1);
		f.y++;
	}
}

char	**ft_square(int size, int i, int j)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * size)))
		return (NULL);
	while (i < size)
	{
		j = 0;
		if (!(tab[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		while (j < size)
			tab[i][j++] = 46;
		i++;
	}
	return (tab);
}

void	ft_swap(int *nbr, int a, int b)
{
	int		tmp;

	tmp = nbr[a];
	nbr[a] = nbr[b];
	nbr[b] = tmp;
}
