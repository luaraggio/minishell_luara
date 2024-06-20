#ifndef define MINISHELL_H
# define MINISHELL_H
# include <stdio.h>

# define MAX_SIZE_TOKEN 100
# define TOKEN_SIZE 64

typedef     struct s_node
{
    char    *content;
    char    *symbol;
    void    *next;
}       t_node;

typedef     struct s_token
{
    char    token_type;
    char    token_value[MAX_SIZE_TOKEN];

}       t_token;

enum    e_token
{
    CMD,
    PIPE,
    HEREDOC,
};


#endif
