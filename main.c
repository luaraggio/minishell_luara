#include "minishell.h"

/*int     main(int argc, char **argv)
{
    Entradas possíveis:

}*/

#include <stdio.h>

int     main(int argc, char **argv)
{
    struct s_token tokens[MAX_TOKENS];
    int numTokens, i;

    lexer(input, tokens, &numTokens);

    printf("Tokens:\n");
    for (i = 0; i < numTokens; i++) {
        printf("Tipo: %c, Valor: %s\n", tokens[i].type, tokens[i].value);
    }
    return (0);
}