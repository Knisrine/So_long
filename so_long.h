#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
#include "./MLX42/include/MLX42/MLX42.h"

#define	WALL '1'
#define	FLOOR '0'
#define	COLL 'C'
#define	PLR 'P'
#define	EX_DR 'E'
#define TILE_SIZE 32

typedef struct variables
{
	mlx_image_t*	put_floor;
	mlx_image_t*	put_plr;
	mlx_image_t*	put_wall ;
	mlx_image_t*	put_door;
	mlx_image_t*	put_col;
	mlx_image_t*	put_dr2;
	mlx_texture_t*	dr2_texture;
	mlx_texture_t*	f_texture;
	mlx_texture_t*	w_texture;
	mlx_texture_t*	col_texture;
	mlx_texture_t*	door_texture;
	mlx_texture_t* 	plr_texture;
	mlx_t* 			ptr;
	int				exit_door;
	int				player;
	int				collct;
    int				height;
    int				width;
	char			**map;
	char			**new_map;
	int				count_move;
	int				x;
	int				y;
	int				i;
	int				j;
	int				fd;
}   var;

int		main(int ac, char **av);
char	**valid_map(char *s, var v);
void	check_ext(char *s);
int		len_map(char *s, var v);
int		is_rectangl(char **map, int height, var *v);
void	free_maps(char **map, char **new_map);
void	free_map(char **map);
void	texture_error(var *v);
void	image_error(var *v);
void	player_pos(char **map, int height, int *x, int *y);
void	ex_door_pos(char **map, int height, int *x, int *y);
void	my_hook(mlx_key_data_t keydata, void *param);
void	flood_fill(int x, int y, var *v);
void	ex_door_pos(char **map, int height, int *x, int *y);
void	player_pos(char **map, int height, int *x, int *y);
void    clean(var *v);
void	set_items(var *v);
void	press_w(var *v);
void	press_s(var *v);
void	press_a(var *v);
void	press_d(var *v);
void	exit_player(var *v);
void	count_items(var *v);
void	check_textures(var *v);
void	clean_textrs(var *v);
void	load_textures(var *v);
void    smll_putnbr(int nb);
void    ft_putchar(char c);

#endif