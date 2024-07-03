/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dherszen <dherszen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:31:39 by dherszen          #+#    #+#             */
/*   Updated: 2024/07/03 20:08:56 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	is_space_or(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char	**ms_split(char *str)
{
	char	**result;
	int	i;

	i = 0;
}

int     main(void)
{
        int     i = 0;
        int     j = 1;
        char    *str = "echo \"Hell\"o > teste.txt | cat -e";
        char    **result = ft_split(str, '\"');

                i = 0;
                while (result[i])
                {
                        printf("%s",result[i++]);
                }
	/*char	**result2 = ft_split(result, ' ');
	i = 0;
                while (result2[i])
                {
                        printf("%s",result2[i++]);
                }
	*/
}
