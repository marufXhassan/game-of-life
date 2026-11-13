
#include <stdio.h>

#define SIZE 10

void print_grid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int count_neighbours(int grid[SIZE][SIZE], int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int nx = x + i;
            int ny = y + j;

            if (nx >= 0 && nx < SIZE &&
                ny >= 0 && ny < SIZE) {
                count += grid[nx][ny];
            }
        }
    }

    return count;
}

void next_generation(int grid[SIZE][SIZE]) {
    int new_grid[SIZE][SIZE] = {0};

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int neighbours = count_neighbours(grid, i, j);

            if (grid[i][j] == 1) {
                new_grid[i][j] =
                    (neighbours == 2 || neighbours == 3);
            } else {
                new_grid[i][j] = (neighbours == 3);
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main(void) {
    int grid[SIZE][SIZE] = {0};

    // Initial pattern: a horizontal line of three cells.
    grid[4][3] = 1;
    grid[4][4] = 1;
    grid[4][5] = 1;

    for (int generation = 0; generation < 5; generation++) {
        printf("\nGeneration %d\n", generation);
        print_grid(grid);
        next_generation(grid);
    }

    return 0;
}



