#ifndef SO_LONG_H
#define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"

typedef struct variables
{
    int n_player;
    int n_collct;
    int n_exit_dr;
}   var;

#define	wall '1'
int		main(int ac, char **av);
void	check_ext(char *s);
void	valid_map(char *s);

#endif