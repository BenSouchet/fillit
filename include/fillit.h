/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 11:15:00 by bsouchet          #+#    #+#             */
/*   Updated: 2016/02/03 18:50:18 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUFF_SIZE 1024
# define CRT s[f.y][f.x]
# define XBFR s[f.y][f.x - 1]
# define XAFR s[f.y][f.x + 1]
# define YAFR s[f.y + 1][f.x]
# define YBFR s[f.y - 1][f.x]
# define COND1 (ft_slv(tab, dst, shp, f) == dst)
# define COND2 ((f.t = 1) == 1 && (f.a = 2) == 2)

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_file
{
	int				y;
	int				x;
	int				h;
	int				c;
	int				l;
	int				m;
	int				s;
	int				i;
	int				j;
	int				t;
	int				k;
	int				a;
	int				nshape;
	int				*perm;
}					t_file;

typedef struct		s_tetri
{
	int				idx;
	int				y;
	int				x;
	int				h;
	int				w;
	struct s_tetri	*nxt;
}					t_tetri;

size_t				ft_ln(const char *s);
int					ft_check(char **s, t_file f);
t_tetri				*ft_stock(char **s, t_file f, int i);
char				**ft_alpha(char **s, t_file f);
char				**ft_square(int size, int i, int j);
char				**ft_double_strdup(char **s, t_file f);
char				**ft_exec(char **tab, t_tetri *list, t_file f, char **dst);
void				ft_swap(int *nbr, int a, int b);
void				ft_print(char **tab, t_file f);
char				**ft_resolve(char **tab, t_file f, char **dest);

#endif
