CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
NAME = so_long
MFILES = so_long.c free_maps.c check_ext.c len_map.c check_map.c is_rectangl.c print_error.c flood_fill.c load_textures.c press_w.c press_d.c count_items.c exit_player.c press_s.c press_a.c set_items.c my_hook.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
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