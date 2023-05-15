SRC = main.c
SRC_OBJ := obj_files
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
INCLUDE = -Iinclude -IMLX42/include/
MLX42 = MLX42
MLX42AR = $(MLX42)/build/libmlx42.a
LFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
LIBFT = libft
HEADER = ./include/fractol.h
LIBFTAR = $(LIBFT)/libft.a
CC = gcc 
EXEC_SRC = fractol
RED = \x1b[31;01m
GREEN = \x1b[32;01m
BLUE = \033[34;1m
BOLD = \033[1m
RESET = \x1b[0m
RM = /bin/rm -f
all: $(LIBFTAR) $(MLX42AR) $(EXEC_SRC)
$(LIBFTAR): 
	@make -C $(LIBFT)
$(MLX42AR):
	@cmake $(MLX42) -B $(MLX42)/build
	@make -C $(MLX42)/build -j4
$(EXEC_SRC): $(SRC) $(HEADER)
	@$(CC) $(INCLUDE) $(CFLAGS) $(SRC) $(LFLAGS) $(LIBFTAR) $(MLX42AR) -o $(EXEC_SRC)
	@printf "$(BOLD) $(BLUE) --- Executable named '$(EXEC_SRC)' ready ---$(RESET)\n"
clean:
	@make clean -C $(LIBFT)
	@make clean -C $(MLX42)/build -j4
	@rm -rf $(EXEC_SRC)
fclean: clean
	@make fclean -C $(LIBFT)
	@make clean/fast -C $(MLX42)/build -j4
	
re: fclean all

.PHONY: all clean fclean re