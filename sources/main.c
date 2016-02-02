/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:15:40 by bsouchet          #+#    #+#             */
/*   Updated: 2016/02/02 13:57:05 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_file	ft_init(t_file file)
{
	file.y = -1;
	file.x = 0;
	file.h = 0;
	file.c = 0;
	file.l = 0;
	file.m = 0;
	file.s = 0;
	file.i = 0;
	file.j = 0;
	file.t = 1;
	file.k = -1;
	file.a = 2;
	file.nshape = 0;
	return (file);
}

size_t			ft_ln(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char		*ft_open(char *file, int *fd, int ret)
{
	char	*buf;

	if ((*fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (!(buf = (char *)malloc(sizeof(buf) * BUFF_SIZE)))
		return (NULL);
	if ((ret = read(*fd, buf, BUFF_SIZE)) == -1 || ret == 0)
		return (NULL);
	buf[ret - 1] = '\0';
	return (buf);
}

static char		**ft_convert(char *buf, int *i, int j, int k)
{
	char	**tab;

	if (!buf)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * (ft_ln(buf) / 2))))
		return (NULL);
	if (!(tab[*i] = (char *)malloc(sizeof(char) * 5)))
		return (NULL);
	while (buf[k] != '\0')
	{
		if (buf[k] == '\n' && (j = 0) == 0 && ++k != 0)
		{
			if (!(tab[++(*i)] = (char *)malloc(sizeof(char) * 5)))
				return (NULL);
		}
		while (buf[k] != '\n' && buf[k] != '\0')
			tab[*i][j++] = buf[k++];
	}
	return (tab);
}

int				main(int ac, char **av)
{
	int		fd;
	t_file	file;
	char	**tab;

	fd = 0;
	file = ft_init(file);
	tab = NULL;
	if (ac == 2)
		tab = ft_convert(ft_open(av[1], &fd, 0), &file.m, 0, 0);
	if (tab != NULL && ft_check(tab, file) != -1 && close(fd) != -1)
		ft_resolve(tab, file, NULL);
	else
		write(1, "error\n", 6);
	return (0);
}
