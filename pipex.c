/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:05:20 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/14 10:04:05 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	ft_child1_process(t_files *fd, int *fd_pipe, char *av, char **envp)
{
	if ((dup2(fd->infile, STDIN_FILENO)) == -1)
		ft_error("Error");
	if (dup2(fd_pipe[1], STDOUT_FILENO) == -1)
		ft_error("Error");
	close(fd_pipe[0]);
	close(fd->infile);
	ft_execute(envp, av);
}

void	ft_child2_process(t_files *fd, int *fd_pipe, char *av, char **envp)
{
	if (dup2(fd->outfile, STDOUT_FILENO) == -1)
		ft_error("Error");
	if (dup2(fd_pipe[0], STDIN_FILENO) == -1)
		ft_error("Error");
	close(fd_pipe[1]);
	close(fd->outfile);
	ft_execute(envp, av);
}

void	ft_parent_process(int *fd_pipe)
{
	close(fd_pipe[0]);
	close(fd_pipe[1]);
	if (wait(NULL) == -1)
		ft_error("Error waitpid");
}

void	pipex(t_files *fd, char *cmd1, char *cmd2, char **envp)
{
	int	fd_pipe[2];
	int	child1;
	int	child2;

	if (pipe(fd_pipe) == -1)
		ft_error("Pipe failed");
	child1 = fork();
	if (child1 == -1)
		exit(EXIT_FAILURE);
	if (child1 == 0)
		ft_child1_process(fd, fd_pipe, cmd1, envp);
	child2 = fork();
	if (child2 == -1)
		exit(EXIT_FAILURE);
	if (child2 == 0)
		ft_child2_process(fd, fd_pipe, cmd2, envp);
	ft_parent_process(fd_pipe);
}
