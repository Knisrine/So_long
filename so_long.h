#ifndef SO_LONG_H
#define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
#include "./MLX42/include/MLX42/MLX42.h"
typedef struct variables
{
	mlx_image_t*	put_floor;
	mlx_image_t*	put_plr;
	mlx_image_t*	put_wall ;
	mlx_image_t*	put_door;
	mlx_image_t*	put_col;
	mlx_image_t*	put_ennemi;
	mlx_texture_t*	f_texture;
	mlx_texture_t*	w_texture;
	mlx_texture_t*	col_texture;
	mlx_texture_t*	door_texture;
	mlx_texture_t*	ennemi_texture;
	mlx_texture_t* 	plr_texture;
	mlx_t* 			ptr;
	int				exit_door;
	int				player;
	int				collct;
    int				height;
    int				width;
	char			**map;
	int				x;
	int				y;
	int				i;
	int				j;
}   var;

typedef struct s_data
{
	void *player_img;
	void *collct_img;
	void *exitdr_img;
}	data;

#define	wall '1'
#define	floor '0'
#define	coll 'C'
#define	plr 'P'
#define	ex_dr 'E'
#define	ennemi 'e'

int		main(int ac, char **av);
char	**valid_map(char *s);
void	check_ext(char *s);
int		len_map(char *s, var v);
int		is_rectangl(char **map, int height, var *v);
void	free_maps(char **map, char **new_map);
void	player_pos(char **map, int height, int *x, int *y);
void	ex_door_pos(char **map, int height, int *x, int *y);

#endif