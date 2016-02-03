/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 10:10:20 by bsouchet          #+#    #+#             */
/*   Updated: 2016/02/02 14:17:12 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_file	ft_valid(char **s, t_file f)
{
	while (f.y <= f.m && s[f.y][0] != '\0')
	{
		f.x = 0;
		while (CRT != '\0')
		{
			if (CRT == '#')
			{
				if (XBFR == '#')
					f.c++;
				if (XAFR == '#')
					f.c++;
				if (f.y != 0 && YBFR == '#' && s[f.y - 1][0] != '\0')
					f.c++;
				if (f.y != f.m && s[f.y + 1][0] != '\0' && YAFR == '#')
					f.c++;
				f.h++;
			}
			if (CRT != '#' && CRT != '.')
				f.c = -10;
			f.x++;
		}
		f.y++;
		f.l++;
	}
	return (f);
}

int				ft_check(char **s, t_file f)
{
	while (f.y++ < f.m)
	{
		if (ft_ln(s[f.y]) != 4 && ft_ln(s[f.y]) != 0)
			return (-1);
	}
	f.y = -1;
	while (++f.y <= f.m + 1)
	{
		f.c = 0;
		f.h = 0;
		f.l = 0;
		f = ft_valid(s, f);
		if (f.c < 5 || f.h != 4 || f.l != 4 || f.y > 130)
			return (-1);
	}
	return (0);
}
