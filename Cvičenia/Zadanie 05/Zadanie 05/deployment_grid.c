/*
p	n				d
1	Lietadlov? lo?	5
2	Bitevn? lo?		4
3	Kr??nik			3
2	Torp?doborec	2
1	Ponorka			1
*/


#include "helpers.h"

int shipsTotal = 27;

int deployment_grid[GRID_SIZE][GRID_SIZE] = {
    { 5, 0, 0, 0, 4, 4, 4, 0, 0, 0},
    { 5, 0, 3, 0, 0, 0, 0, 0, 0, 0},
    { 5, 0, 3, 0, 1, 1, 1, 1, 1, 0},
    { 0, 0, 3, 0, 0, 0, 0, 0, 0, 0},
    { 7, 0, 3, 0, 0, 0, 0, 0, 0, 0},
    { 7, 0, 0, 0, 0, 0, 8, 8, 0, 0},
    { 0, 0, 0, 2, 0, 0, 0, 0, 0, 0},
    { 6, 0, 0, 2, 0, 0, 0, 0, 0, 0},
    { 6, 0, 0, 2, 0, 0, 0, 0, 0, 0},
    { 6, 0, 0, 2, 0, 0, 0, 0, 0, 9},
};