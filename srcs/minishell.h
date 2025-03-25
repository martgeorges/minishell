/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laichoun <laichoun@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:11:18 by laichoun          #+#    #+#             */
/*   Updated: 2024/10/24 09:17:45 by laichoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_export
{
	char			*name;
	char			*value;
	struct s_export	*next;
}					t_export;

typedef struct s_liste_export
{
	t_export		*first_node;
}					t_liste_export;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_liste_env
{
	t_env			*first_node;
}					t_liste_env;

typedef struct s_cmd
{
	char			**cmd_and_opt;
	char			*path;
	int				pipe_number;
	int				**pipe_fd;
	bool			is_pipe;
	int				exit_code;
	bool			double_first;
	bool			single_first;
	t_liste_env		*env;
	t_liste_export	*exp;

}					t_cmd;

typedef enum e_token_type
{
	TOKEN_INPUT,
	TOKEN_HERE_DOC,
	TOKEN_TRUNCT,
	TOKEN_APPEND,
	TOKEN_PIPE,
	TOKEN_WORD,
	TOKEN_CMD,
	TOKEN_ARG,
}					t_token_type;

typedef struct s_token
{
	t_token_type	type;
	struct s_token	*next;
	struct s_token	*previous;
	char			*str;
}					t_token;

typedef struct s_liste
{
	t_token			*first_node;
}					t_liste;

// creation de la stack
t_liste				*initialisation(void);
void				insertion(t_liste *liste, char *content, t_token_type type);
void				display_liste(t_liste *liste);

// free
void				free_split(char **result);
void				my_ft_lstclear(t_liste **lst);
void				free_liste(t_liste *pipe);
void				free_env_lst(t_liste_env **lst);
void				free_tab_pipe(t_cmd *cmd, int i);
void				free_tab_cmd(t_cmd *cmd);
void				free_all(t_liste *line, t_cmd *cmd);
void				free_exit(t_liste *line, t_cmd *cmd);

// parsing
int					parsing_input(char *input, t_liste *line);
char				*creation_str(int i, int j, char *input);
void				change_token_word(t_liste *line);
int					split_token_word(int i, char *input, t_liste *line);

int					only_is_redir(t_liste *line, t_cmd *cmd);
void				handle_only_redir(t_liste *line, t_cmd *cmd);
void				parent_process_redir_only(t_cmd *cmd, pid_t pid);
int					print_error_msg(void);
int					management_input(char *input, t_liste *line, int i);
void				help_change_token(t_token *current);
// void				open_fd_only_redir(int type, char *filename, t_cmd *cmd);
// void				error_on_fd(char *filename, int fd, t_cmd *cmd);

void				error_on_fd(char *filename, int fd, t_cmd *cmd,
						t_liste *line);
void				open_fd_only_redir(int type, char *filename, t_cmd *cmd,
						t_liste *line);

void				error_on_fork(pid_t pid);

// substitution
void				substitution(t_liste *line, t_cmd *cmd);
char				*get_value(char *name, t_cmd *cmd);
char				*management_sub(char *str, t_cmd *cmd);
int					jump_next_quote(int i, char *str);
void				free_var_sub(char *name, char *str, char *value);
int					len_tot(char *str, char *name, int k);
char				*set_new_str(char *str, t_cmd *cmd, int *i, int j);
char				*var_substitution(char *str, t_cmd *cmd, int *i,
						bool is_status);

// error handling
void				error_message_tok(t_liste *line, int i);
int					check_error_syntax(t_liste *line, t_cmd *cmd);
void				on_error(char *str);
void				put_error_export(t_cmd *cmd, char *str);
int					ret_error(t_liste *line, t_cmd *cmd, int i);

// path
char				*is_in_path(t_token *current, t_cmd *cmd);
char				*give_the_path(char *str, char **result, t_cmd *cmd);
char				*get_path_list(t_cmd *cmd);
void				display_tab(char **result);
char				**tab_cmd_opt(t_token *current);
int					nbre_opt(t_token *current);

// process_pipe
void				interpretation_pipes(t_liste *line, t_cmd *cmd);
char				**create_tab_cmd(t_cmd *cmd, t_token *current);
int					nbr_commands(t_liste *line);
int					nbr_pipe(t_liste *line);
int					**creation_tab_pipe(t_liste *line, t_cmd *cmd);
void				creation_pipe(t_cmd *cmd, t_liste *line);
void				creation_process(t_cmd *cmd, int i, t_token *current,
						t_liste *line);
void				close_fd_pipe(t_cmd *cmd);
void				parent_process(t_cmd *cmd);
void				handle_redirection_pipe(t_token *current, t_liste *line,
						t_cmd *cmd);

// builtins

int					is_builtins(t_token *current);
int					exec_builtins(t_token *current, t_cmd *cmd, t_liste *line);
int					exec_builtins_2(t_token *current, t_cmd *cmd);

void				exit_shell(t_token *current, t_liste *line, t_cmd *cmd);

int					get_pwd(void);

// void				management_cd(t_cmd *cmd, t_token *current);
int					management_cd(t_cmd *cmd, t_token *current);
int					change_directory(const char *path, t_liste_env *env);

int					ft_echo(t_token *current);

// unset
void				management_unset(t_cmd *cmd, t_token *current);
void				execution_unset(t_cmd *cmd, t_token *current);
t_env				*last_node(t_cmd *cmd);
void				free_unset(t_env *del);
void				remove_arg(t_env *prev, t_env *last, t_env *cur,
						t_cmd *cmd);

// export
void				management_export(t_token *current, t_liste *line,
						t_cmd *cmd);
void				execution_export(char *str, t_cmd *cmd);
t_env				*node_found(t_env *cur, char *name_str, char *new_value);
void				node_not_found(t_cmd *cmd, char *name_str, char *new_value,
						char *str);
void				is_node_null(t_cmd *cmd, char *val, char *s, t_env *cur);

// export list chainée
t_liste_export		*initialisation_export(void);
void				creation_export(char **env, t_liste_export *export);
void				insert_node_export(char *str, t_liste_export *export);
void				display_export_list(t_liste_export *export);
void				management_export_list(char **env, t_liste_export *export);

// binaries :
int					exec_1_cmd(t_token *current, t_cmd *cmd, t_liste *line);
void				command_access(t_liste *line, t_token *current, char *str,
						t_cmd *cmd);
void				interpretation(t_liste *line, t_cmd *cmd);

void				error_cmd_access(t_liste *line, char *str, t_cmd *cmd,
						int i);
void				handle_redir_cmd(t_token *redir, t_cmd *cmd, t_liste *line);
void				handle_binaries(t_token *current, t_cmd *cmd,
						t_liste *line);

// redirection
void				here_doc(t_token *current);
void				handle_input_redirection(char *filename, t_liste *line,
						t_cmd *cmd);
void				handle_output_redirection(char *filename, int flags,
						t_liste *line, t_cmd *cmd);
void				handle_append_redirection(char *filename, int flags,
						t_liste *line, t_cmd *cmd);
void				handle_here_do(t_liste *line);

// creation env
t_liste_env			*initialisation_env(void);
void				creation_env(char **env, t_liste_env *envp);
void				insert_node_env(char *str, t_liste_env *env);
int					display_env_list(t_liste_env *env, int flag);
void				management_env(char **env, t_liste_env *envp);
char				**creation_tab_env(t_liste_env *env);

// utils
int					liste_size(t_liste_env *env);
int					len_first(char *str);
int					len_end(int i, char *str);
int					is_empty(t_liste *line);
int					found_slash(t_token *current);

// main
void				initialization_cmd(t_cmd *cmd, t_liste_env *envp);
void				minishell_exec(char *input, t_cmd *cmd);
void				reset_cmd(t_cmd *cmd);
void				affichage_cmd_list_env(t_cmd *cmd);
void				main_execution(t_liste_env *envp, t_cmd *cmd);
int					validate_parsing(char *input, t_liste *line, t_cmd *cmd);

// signals
void				signal_ignore(int sig);
void				signal_before(void);
void				signal_after(void);

// remove the quotes
void				check_kind_quotes(char c, t_cmd *cmd);
void				handle_remove_quotes(t_liste *line, t_cmd *cmd);
char				*shift_inside_quotes(char *str, int *j, char q);
char				*shift_after_quotes(char *str, int *i);
char				*remove_quotes(char *str);

#endif
