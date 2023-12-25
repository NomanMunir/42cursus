/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abashir <abashir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 09:49:48 by nmunir            #+#    #+#             */
/*   Updated: 2023/12/10 10:22:07 by abashir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libs/gnl/get_next_line.h"
# include "../libs/libft/libft.h"
# include "structs.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termcap.h>
# include <termios.h>
# include <unistd.h>

int						g_signum;

typedef struct s_iterators
{
	int					i;
	int					j;
	char				c;
	int					count;
	bool				flag;
	char				*tmp;
	char				*src;
	char				*dest;
	int					error;
}						t_iterators;

typedef struct s_env
{
	char				*key;
	char				*value;
	struct s_env		*next;
}						t_env;

typedef struct s_cmd_list
{
	t_cmd				*cmd;
	struct s_cmd_list	*next;
}						t_cmd_list;

typedef struct s_shell
{
	char				*input;
	char				**env;
	bool				is_forked;
	bool				is_one_command;
	bool				is_pipe;
	bool				is_builtins;
	long long			g_exit_code;
	struct s_env		*env_list;
	t_cmd				*cmd;
	t_cmd_list			*cmd_list;
}						t_shell;

char					*ft_strjoin_3(char const *s1, char const *s2,
							char const *s3);
void					set_g_exit(t_shell *shell);
void					close_fds(void);
void					is_one_cmd(char *input, t_shell *shell);
void					allocate_env(t_shell *shell, char **env);
void					set_shlvl(t_shell *shell);
bool					check_access(char *path_to_cmd);
int						ft_peek(char **ps, char *es, char *toks);
t_cmd					*parsecmd(char *s, t_shell *shell);
t_cmd					*parsepipe(char **ps, char *es, t_shell *shell);
t_cmd					*parseline(char **ps, char *es, t_shell *shell);
t_cmd					*parseexec(char **ps, char *es, t_shell *shell);
t_cmd					*parseredirs(t_cmd *cmd, char **ps, char *es,
							t_shell *shell);
t_cmd					*nulterminate(t_cmd *cmd);
t_cmd					*redircmd(t_cmd *subcmd, t_parse_set set);
t_cmd					*execcmd(void);
t_cmd					*pipecmd(t_cmd *left, t_cmd *right);
t_cmd					*heredoccmd(t_cmd *subcmd, char *content,
							char *delimiter);
void					runcmd(t_cmd *cmd, t_shell *shell);
void					handle_pipe(t_cmd *cmd, t_shell *shell);
void					handle_redir(t_cmd *cmd, t_shell *shell);
void					handle_heredoc(t_cmd *cmd, t_shell *shell);
void					handle_exec(t_cmd *cmd, t_shell *shell);
void					ft_exec(t_execcmd *ecmd, t_shell *shell);
int						ft_strcmp(const char *s1, const char *s2);
char					*get_cmd_path(t_shell *shell, char **cmds);
int						get_fork(void);
int						gettoken(char **ps, char *es, char **q, char **eq);
void					skip_char_token(char **str, char *es, char c);
void					skip_spaces(char **s, char *es);
void					ft_free_success(t_shell *shell, int e_code,
							bool is_exit);
void					ft_free(char **tab);
char					*expand_env(char *input, t_shell *shell);
int						count_expand(char *input, t_shell *shell);
bool					handle_quotes(char **input);
void					init_env(t_shell *shell);
int						handle_export(char **cmd, t_shell *shell);
void					ft_export(t_shell *shell, char *input);
t_env					*ft_sort_export(t_env *env_list);
void					ft_print_export(t_env *env_list);
void					ft_set_export(char *input, t_shell *shell, int i,
							int p);
void					addfrontlst(char *key, char *value, t_env **env_list);
int						print_env(char **input, t_shell *shell);
void					run_builtins(t_execcmd *ecmd, t_shell *shell);
bool					is_builtin(char *input);
int						ft_unset(t_shell *shell, char *key);
int						ft_pwd(t_execcmd *ecmd, t_shell *shell);
int						handle_cd(t_execcmd *ecmd, t_shell *shell);
t_env					*find_env(t_env *env_list, char *key);
int						ft_echo(t_execcmd *ecmd, t_shell *shell);
void					ft_exit(t_execcmd *ecmd, t_shell *shell);
long long				my_atoll(const char *str, int *error);
void					panic(t_shell *shell, int e_code, bool flag);
void					reset_env(t_shell *shell);
int						ft_lstsize(t_env *env);
void					ft_clean_env(t_env *env_list);
void					config_signals(void);
void					sigpipe_handler(int signum);
void					sigint_handler(int signum);
void					sig_handler_hdoc(int sig);
char					*check_input(char *input, t_shell *shell);
char					check_syntax(char *input);
void					syntax_error(char c);
int						is_quotes_closed(char *input, int *i);
void					ft_put_error(char *errmsg, char *errcmd, char *cmd);
void					ft_malloc_error(void);
int						ft_find_last_heredoc(char **ps, char *es,
							t_parse_set *set);
char					*parse_heredoc(char *delimiter, t_shell *shell,
							t_parse_set *set);
void					set_heredoc(bool *flag, char **content, char **tmp);
void					ft_free_tree(t_cmd *cmd, t_shell *shell);
void					free_argv(char **argv);
void					parse_panic(t_shell *shell, int e_code, bool flag,
							t_cmd *cmd);
void					clean_cmd(t_shell *shell, bool flag);
void					check_token(char **ps, char *es, t_parse_set *set,
							t_cmd *cmd);
void					add_cmd_list(t_shell *shell, t_cmd *cmd);
void					is_pipe_cmd(char *input, t_shell *shell);
void					rl_replace_line(const char *text, int clear_undo);
char					*split_expand(char *str, t_shell *shell);
int						count_split(char *str);
void					ft_find_next(char **ps, t_parse_set *set);
bool					my_strchr(char *str, char c);
int						iterm_change(bool echo_ctl_chr);
#endif
