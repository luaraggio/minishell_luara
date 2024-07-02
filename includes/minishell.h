/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 20:58:53 by dherszen          #+#    #+#             */
/*   Updated: 2024/07/02 19:02:18 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include <stdlib.h>
# include <signal.h>
# include <unistd.h> //execv function
# include <sys/wait.h>

//Readline library
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_token
{
	enum e_token	type;
	char	*token;
	struct s_node	*next;
}	t_token;

typedef struct s_minishell
{
	char			*input;
	char			**args;
	//char			**envp;
	struct s_node	*token;
}	t_minishell;

enum	e_token
{
	CMD,
	ARG,
	PIPE,
	HEREDOC,
	I_RED,
	O_RED,
	I_RED_HD, //heredoc redirection
	I_RED_APP, //append redirection
};

enum	e_builtins
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT,
};

enum	e_errors
{
	GRAMMAR_ERROR = -1,	
};

void	setup_signal_handling(void);
void	signal_handle(int sig);
void	handle_sig_error(int sig);
#endif
