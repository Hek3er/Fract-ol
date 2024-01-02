CC = cc
CFLAGS = -Wall -Werror -Wextra
MLXFLAG = -lmlx -framework OpenGL -framework AppKit
NAME = fractol

SRCS = ./src/mandatory/fractol.c ./src/mandatory/julia.c ./src/mandatory/hooks.c ./src/mandatory/init.c ./src/mandatory/mandelbrot.c ./src/mandatory/math.c ./src/mandatory/parsing.c ./src/mandatory/parsing2.c
SRCS_B = ./src/bonus/fractol_bonus.c ./src/bonus/zoom.c ./src/bonus/burning_ship.c ./src/bonus/hooks_bonus.c ./src/bonus/julia_bonus.c ./src/bonus/mandelbrot_bonus.c ./src/bonus/parsing2_bonus.c ./src/mandatory/math.c ./src/mandatory/parsing.c ./src/mandatory/init.c
O_FILES = $(SRCS:.c=.o)
O_BFILES = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(O_FILES)
		@echo "Compiling mandatory."
		@$(CC) $(CFLAGS) $(MLXFLAG) $(O_FILES) -o $(NAME)

bonus: $(O_BFILES)
		@echo "Compiling Bonus."
		@$(CC) $(CFLAGS) $(MLXFLAG) $(O_BFILES) -o fractol_bonus

%.o: %.c ./includes/fractol.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Deleting Object Files."
	@rm -rf $(O_FILES) $(O_BFILES)

fclean:
	@echo "Deleting All."
	@rm -rf $(NAME) $(O_FILES) $(O_BFILES) fractol_bonus
re: fclean all
