#include "helpers.h"

int shipsTotal = 27;

int deployment_grid[GRID_SIZE][GRID_SIZE] = {
    { 1, 0, 0, 0, 1, 1, 1, 0, 0, 0},
    { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 0},
    { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    { 1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    { 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
};
