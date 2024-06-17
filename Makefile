NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 

all: $(NAME)

$(NAME):	$(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
