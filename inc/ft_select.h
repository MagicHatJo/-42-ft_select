/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jochang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 02:01:11 by jochang           #+#    #+#             */
/*   Updated: 2019/04/16 02:01:12 by jochang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <unistd.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <termcap.h>
# include <termios.h>
# include "libft.h"
# include "keys.h"
# include "colors.h"

/*
** Macros
*/

# define OPT_COUNT			8
# define CLEAR_SCREEN		ft_putstr_fd(tgetstr("cl", NULL), STDERR_FILENO)

/*
** Typedefs
*/

typedef struct termios	t_termios;
typedef struct winsize	t_winsize;

/*
** Structures
*/

typedef struct	s_node
{
	char			*name;
	uint8_t			selected;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef struct	s_cdll
{
	int			size;
	int			maxlen;
	t_node		*head;
	t_node		*tail;
	t_node		*list;
}				t_cdll;

typedef struct	s_win
{
	t_winsize	winsize;
	int			cpl;
	char		buf[1024];
}				t_win;

/*
** Globals
*/

t_termios		g_original;
t_cdll			*g_cdll;
t_win			g_win;

/*
** Functions
*/

t_cdll			*make_list(int ac, char **av);
int				ft_select(void);
void			signal_handler(void);
void			input_handler(uint64_t cmd);
void			get_winsize(void);
void			free_cdll(t_cdll *c);
void			printer(void);

/*
** Termcaps
*/

int				term_check(void);
void			term_init(void);
void			term_revert(void);

/*
** Dispatch
*/

void			d_delete(uint64_t cmd);
void			d_exit(uint64_t cmd);
void			d_move(uint64_t cmd);
void			d_select(uint64_t cmd);

typedef void	(*t_fun)(uint64_t);
typedef struct	s_dis
{
	uint64_t	op;
	t_fun		s;
}				t_dis;

#endif
