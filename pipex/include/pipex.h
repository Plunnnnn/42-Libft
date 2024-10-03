/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenfir <bdenfir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:55:58 by bdenfir           #+#    #+#             */
/*   Updated: 2024/10/03 22:47:07 by bdenfir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_pipex {
	int pipe_fd[2];

} t_pipex;

void parse_commande(char **argv);
pid_t	fork_child(t_pipex *data, int pipe_fd[2], char **argv, char **envp);
void create_pipe(t_pipex *data);
void	error_exit(char *str);


#endif


