/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipeline.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:23:25 by junghwle          #+#    #+#             */
/*   Updated: 2024/01/08 18:05:55 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	exec_childs(t_fdp *fdp, t_minishell *shell, t_cmnd *cmnds, int err);
static void	wait_childs(t_fdp *fdp, int *exit_code);

int	execute_pipeline(t_cmnd *cmnd_list, t_fdp *fdp, t_minishell *shell)
{
	int	err;

	err = 0;
	while (cmnd_list)
	{
		if (redirect(cmnd_list->redir, fdp, shell) == ERROR)
			err = 1;
		pipe(fdp->pipe);
		fdp->pid[fdp->child_id] = fork();
		if (fdp->pid[fdp->child_id] == -1)
			break ;
		else if (fdp->pid[fdp->child_id] == 0)
			exec_childs(fdp, shell, cmnd_list, err);
		dup_and_close(fdp->pipe[0], STDIN_FILENO);
		close (fdp->pipe[1]);
		cmnd_list = cmnd_list->next;
		fdp->child_id++;
		err = 0;
	}
	restore_io(fdp);
	wait_childs(fdp, &shell->exit_code);
	return (SUCCESS);
}

static void	exec_childs(t_fdp *fdp, t_minishell *shell, t_cmnd *cmnds, int err)
{
	char	*cmnd_path;

	if (err != 0)
		exit(shell->exit_code);
	if (fdp->tmp_in)
		if (set_redir_in(fdp) == ERROR)
			exit(0);
	if (cmnds->next != NULL)
	{
		dup_and_close(fdp->pipe[1], STDOUT_FILENO);
		close(fdp->pipe[0]);
	}
	if (fdp->tmp_out)
		if (set_redir_out(fdp) == ERROR)
			exit(0);
	if (check_builtin(cmnds))
		exec_builtin(shell, cmnds);
	else
	{
		cmnd_path = setpath(fdp->paths, cmnds->args[0], &shell->exit_code);
		if (cmnd_path != NULL)
			execve (cmnd_path, cmnds->args, shell->_envp);
		exit (shell->exit_code);
	}
	exit (0);
}

static void	wait_childs(t_fdp *fdp, int *exit_code)
{
	int	i;
	int	status;

	i = 0;
	while (i < fdp->cmnd_cnt)
	{
		waitpid(fdp->pid[i], &status, 0);
		i++;
	}
	if (WIFEXITED(status))
		*exit_code = (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			*exit_code = 130;
		else if (WTERMSIG(status) == SIGQUIT)
		{
			*exit_code = 131;
			ft_printf("Quit: 3\n");
		}
	}
}
