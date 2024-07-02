/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 21:06:27 by dherszen          #+#    #+#             */
/*   Updated: 2024/07/02 18:53:36 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*volatile unsigned int	g_status;*/

void	signal_handle(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
		return ;
}

int	main(void)//int argc, char **argv, char **envp)
{
	//t_minishell	*ms;
	char	*input;
	//inicializar structs e char **envp (o nosso env);
	//ft_memset();
	setup_signal_handling();
	while (42)
	{
		input = readline("$ ");
		if (input == NULL)
			break ;
		add_history(input);
		if (ft_strcmp(input, "exit") == 0)
			break ;
		//tokens();
		//if (!check_grammar())
		/*execute_command(ms);*/
		free(input);
	}
	clear_history();
	//free(ms);
	free(input);
	return (EXIT_SUCCESS);
}

void	setup_signal_handling(void)
{
	struct sigaction	sa;

	//ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signal_handle;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		handle_sig_error(SIGINT);
	sa.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sa, NULL) == -1)
		handle_sig_error(SIGQUIT);
}

void	handle_sig_error(int sig)
{
	if (sig == SIGINT)
	{
		perror(("Error setting up SIGINT handler\n"));
		exit(EXIT_FAILURE);
	}
	else if (sig == SIGQUIT)
	{
		perror(("Error setting up SIGQUIT handler\n"));
		exit(EXIT_FAILURE);
	}
	else
		return ;
}
