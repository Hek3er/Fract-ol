CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAG = -lmlx -framework OpenGL -framework AppKit
NAME = fractol

SRCS = ./src/mandatory/fractol.c ./src/mandatory/julia.c ./src/mandatory/hooks.c ./src/mandatory/init.c ./src/mandatory/mandelbrot.c ./src/mandatory/math.c ./src/mandatory/parsing.c ./src/mandatory/parsing2.c
SRCS_B = ./src/bonus/fractol_bonus.c ./src/bonus/burning_ship.c ./src/bonus/hooks_bonus.c ./src/bonus/julia_bonus.c ./src/bonus/mandelbrot_bonus.c ./src/bonus/parsing2_bonus.c ./src/mandatory/math.c ./src/mandatory/parsing.c ./src/mandatory/init.c
O_FILES = $(SRCS:.c=.o)
O_BFILES = $(SRCS_B:.c=.o)

all: $(NAME)

fractol: $(O_FILES)
		$(CC) $(CFLAGS) $(MLXFLAG) $(O_FILES) -o $(NAME)

fractol_bonus: $(O_BFILES)
		$(CC) $(CFLAGS) $(MLXFLAG) $(O_BFILES) -o $@

%.o: %.c ./includes/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(O_FILES) $(O_BFILES)

fclean: clean
	rm -rf $(NAME) fractol_bonus
re: fclean all
