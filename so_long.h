#ifndef SO_LONG_H
#define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"
#include "./MLX42/include/MLX42/MLX42.h"
typedef struct variables
{
	int	exit_door;
	int	player;
	int	collct;
    int  height;
    int width;

}   var;

typedef struct s_data
{
	void *player_img;
	void *collct_img;
	void *exitdr_img;
}	data;

#define	wall '1'
int		main(int ac, char **av);
char	**valid_map(char *s);
void	check_ext(char *s);
int		len_map(char *s, var v);
int		is_rectangl(char **map, int height, var *v);
void	free_maps(char **map, char **new_map);

#endif