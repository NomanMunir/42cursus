/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:49:48 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/06 11:50:08 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minishell.h"

# define EXEC 1
# define REDIR 2
# define PIPE 3
# define HEREDOC 4

# define MAXARGS 1024
# define PROMPT "minishell>$ "
# define SPEC_CHAR_SPC " '\":/\\,~.@#%-+*^=$"
# define SPEC_CHAR ":/\\,~.@#%-+*^=$"

typedef struct s_cmd
{
	int				type;
}					t_cmd;

typedef struct s_heredoccmd
{
	int				type;
	char			*content;
	char			*delimiter;
	struct s_cmd	*cmd;
}					t_hdoc;

typedef struct s_execcmd
{
	int				type;
	char			*argv[MAXARGS];
	char			*eargv[MAXARGS];
}					t_execcmd;

typedef struct s_redircmd
{
	int				type;
	struct s_cmd	*cmd;
	char			*file;
	char			*efile;
	char			*end;
	int				mode;
	int				fd;
}					t_redircmd;

typedef struct s_pipecmd
{
	int				type;
	struct s_cmd	*left;
	struct s_cmd	*right;
}					t_pipecmd;

typedef struct s_parse_set
{
	char			*filename;
	int				mode;
	int				fd;
	char			*q;
	char			*eq;
	char			*content;
	int				tok;
	char			*t;
	int				argc;
	bool			error;
	t_cmd			*cmd;
	struct s_shell	*shell;
}					t_parse_set;

#endif