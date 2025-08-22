# -------------------- CONFIG --------------------
NAME      = fractol
CC        = gcc
CFLAGS    = -Wall -Wextra -Werror -Ofast -pthread
SRC       = main.c mandelbrot.c julia.c utils.c inputs.c
OBJ_DIR   = obj_files
INCLUDE   = -Iinclude -IMLX42/include/
LIBFT     = libft
LIBFT_AR  = $(LIBFT)/libft.a
HEADER    = include/fractol.h

MLX42     = MLX42
MLX42_AR  = $(MLX42)/build/libmlx42.a

SRC_OBJS  = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
RM        = /bin/rm -f

# -------------------- OS DETECTION --------------------
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	LFLAGS = -lglfw -ldl -lm
else
	LFLAGS = $(shell pkg-config --libs glfw3)
	INCLUDE = -Iinclude -IMLX42/include/ $(shell pkg-config --cflags glfw3)
endif

# -------------------- COLORS --------------------
RED    = \x1b[31;01m
GREEN  = \x1b[32;01m
BLUE   = \033[34;1m
BOLD   = \033[1m
RESET  = \x1b[0m

# -------------------- RULES --------------------
all: $(LIBFT_AR) $(MLX42_AR) $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_AR):
	@make -C $(LIBFT)

$(MLX42_AR):
	@cmake -S $(MLX42) -B $(MLX42)/build
	@make -C $(MLX42)/build -j4

$(NAME): $(SRC_OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(SRC) $(LIBFT_AR) $(MLX42_AR) $(LFLAGS) -o $(NAME)
	@printf "$(BOLD)$(BLUE)--- Executable named '$(NAME)' ready ---$(RESET)\n"

clean:
	@make clean -C $(LIBFT)
	@make clean -C $(MLX42)/build
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(NAME)

fclean: clean
	@make fclean -C $(LIBFT)
	@make clean -C $(MLX42)/build

re: fclean all

.PHONY: all clean fclean re
