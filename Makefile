CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAG = -lmlx -framework OpenGL -framework AppKit
NAME = fractol

SRCS = fractol.c julia.c hooks.c init.c mandelbrot.c math.c parsing.c parsing2.c
O_FILES = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
		$(CC) $(CFLAGS) $(MLXFLAG) $(O_FILES) -o $(NAME)

%.o: %.c ./includes/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)
re: fclean all
