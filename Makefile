CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
NAME = so_long
MFILES = so_long.c check_ext.c check_map.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OFILES = $(MFILES:.c=.o)

all : $(NAME)

$(NAME): $(OFILES)
	@$(CC) $(CFLAGS) $(OFILES) MLX42/build/libmlx42.a -I"include/MLX42/MLX42.h" -lglfw -L"/Users/nikhtib/.brew/opt/glfw/lib/" -o $(NAME)

%.o: %.c so_long.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(OFILES) $(NAME)

re: fclean all

.PHONY: clean