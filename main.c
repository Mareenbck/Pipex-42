/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:49:34 by mbascuna          #+#    #+#             */
/*   Updated: 2022/01/13 14:58:45 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		i;
	t_files	fd;

	if (ac < 5)
		ft_error("Wrong number of arguments");
	fd.infile = open(av[1], O_RDONLY);
	fd.outfile = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (fd.infile < 0 || fd.outfile < 0)
		ft_error("File openned failed");
	i = 2;
	while (i < ac -2)
	{
		pipex(&fd, av[i], av[i + 1], envp);
		i++;
	}
	return (0);
}
