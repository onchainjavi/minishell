/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:05:41 by jmarinel          #+#    #+#             */
/*   Updated: 2024/01/08 17:40:52 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H

# include <signal.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <readline/readline.h>
# include "libft.h"
# include "minishell.h"

# define ERR_ARG	1
# define ERR_MC		2
# define ERR_CNF	3
# define ERR_PERM	4
# define ERR_NFD	5
# define ERR_PERR	10
# define INF		0
# define OUTF		1

# define ERROR	1
# define SUCCESS 0

typedef struct s_fdp
{
	int		pipe[2];
	t_io	*tmp_in;
	t_io	*tmp_out;
	int		fd_file[2];
	int		std_in_out[2];
	int		*pid;
	char	**paths;
	int		child_id;
	int		cmnd_cnt;
}			t_fdp;

/*### NEW PIPE ###*/
int		check_builtin(t_cmnd *cmnd_list);
void	close_fds(t_fdp *fdp);
int		dup_and_close(int fd_to, int fd_from);
int		executer(t_cmnd *cmnd_list, t_minishell *shell);
void	exec_builtin(t_minishell *shell, t_cmnd *cmnd_list);
int		execute_builtin(t_fdp *fdp, t_cmnd *list, t_minishell *shell);
int		execute_pipeline(t_cmnd *cmnd_list, t_fdp *fdp, t_minishell *shell);
char	**findpath(char **env);
void	free_fdp(t_fdp *fdp);
void	ft_free_array(char **arr);
int		init_data(t_fdp *fdp, t_cmnd *cmnd_list, char **_envp);
char	**init_path(t_fdp *fdp, t_cmnd *list, char **envp, int i);
int		manage_files(t_fdp	*fdp);
int		redirect(t_io *redir, t_fdp *fdp, t_minishell *shell);
int		restore_io(t_fdp *fdp);
char	*setpath(char **path, const char *argv, int *exit_code);
int		set_redir_in(t_fdp	*fdp);
int		set_redir_out(t_fdp	*fdp);
int		open_outfile(t_fdp *fdp);
int		is_directory(char *file);
int		open_infile(t_fdp *fdp);

/*### OLD PIPEX ###*/
int		ft_error(int err, int ext, char *cmd);

#endif