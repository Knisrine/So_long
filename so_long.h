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
    int height;
    int width;
}   var;

#define	wall '1'
int		main(int ac, char **av);
void	check_ext(char *s);
void	valid_map(char *s);

#endif