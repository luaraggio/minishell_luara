/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 19:36:27 by lraggio           #+#    #+#             */
/*   Updated: 2024/07/01 19:38:55 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h> //strtok function (I'll implement something like that)

int	execute_command(t_minishell *ms)
{
	pid_t   pid;
    int child_status;

    pid = fork();
    if (pid == 0) //child process
    {
        if (execve(ms->input, ms->args, ms->envp) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
    }
    else if (pid != 0) //father process
        waitpid(pid, &child_status, 0);
    return (0);
}