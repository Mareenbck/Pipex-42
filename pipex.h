/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:12:28 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/13 15:11:35 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libc.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_files
{
	int		outfile;
	int		infile;
}	t_files;	

void	pipex(t_files *fd, char *cmd1, char *cmd2, char **envp);
char	*search_envp(char **envp);
char	**ft_split_envp(char **envp);
char	*ft_join_envp(char **split_path, char *av);
void	**ft_free_tab(char **tab);
void	ft_error(char *msg);
void	ft_execute(char **envp, char *av);

#endif
