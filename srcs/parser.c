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

char    *find_command_path(const char *command) 
{
    char    *path_env;
    char    *cmd_path;
    char    *path;
    char    *dir;

    path_env = getenv("PATH");
    if (!path_env) 
        return NULL;

    path = strdup(path_env); // Duplicar PATH para não modificar o original
    dir = strtok(path, ":");
    while (dir) 
    {
        cmd_path = malloc(ft_strlen(dir) + ft_strlen(command) + 2); // +2 para '/' e '\0'
        if (!cmd_path) 
        {
            perror("malloc");
            free(path);
            return NULL;
        }
        sprintf(cmd_path, "%s/%s", dir, command);
        if (access(cmd_path, X_OK) == 0) { // Verificar se o comando é executável
            free(path);
            return cmd_path;
        }
        free(cmd_path);
        dir = strtok(NULL, ":");
    }
    free(path);
    return NULL;
}

struct s_minishell *parse_command(char *input)
{
	t_minishell *ms;
	char	*token;
	char	*cmd_path;
	int	i;
	
	i = 0;
	ms = malloc(sizeof(t_minishell));
    if (ms)
	{
		perror("malloc");
		free(ms);
		return NULL;
	}
	ms->args = malloc(10 * sizeof(char *));
    if (!ms->args) {
        perror("malloc");
        free(ms);
        return NULL;
    }
	ms->input = strtok(input, " ");
    while ((token = strtok(NULL, " ")) != NULL)
        ms->args[i++] = token;
    ms->args[i] = NULL;
	cmd_path = find_command_path(ms->input);
	if (cmd_path)
		ms->input = cmd_path;
    ms->envp = NULL;
    return (ms);
}