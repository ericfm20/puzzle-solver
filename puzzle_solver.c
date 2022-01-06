#include <stdio.h>

#define NUM_COLUMNS 12
#define HEIGHT 5
#define MAX_RADIUS 4
#define TARGET_SUM 42

/**
 * Each row in the array represents one radial row on the puzzle.
 * Each column represents one puzzle column at one hight.
 */
int puzzle_array[HEIGHT*MAX_RADIUS][NUM_COLUMNS];

/**
 * Represents the rotation of each disk.
 */
int puzzle_rotations[HEIGHT]; 

/**
 * Gets the value at a particular point in the puzzle array.
 * r: the radial row
 * col: the puzzle column
 * height: the height from the top
 */
int value_in_puzzle(int r, int col, int height){
	// update column with the rotated column
	col = (puzzle_rotations[height] + col) % NUM_COLUMNS;

	// update r to account for the height
	r = height*MAX_RADIUS + r;
	return puzzle_array[r][col];
}

int main(int argc, char* argv[]){
	// input puzzle from file
	if (argc != 2){
		printf("Expected 1 argument; received %i", argc - 1);
		return 1;
	}

	FILE *f = fopen(argv[1], "r");

	int current;
	for (int r = 0; r < HEIGHT*MAX_RADIUS; r++){
		for (int col = 0; col < NUM_COLUMNS; col++){
			fscanf(f, "%d", &current);
			puzzle_array[r][col] = current;
		}
	}

	fclose(f);

	int sum;
	int level_to_rotate = 0;

	// initialize puzzle rotations to 0
	for(int i = 0; i < HEIGHT; i++)
		puzzle_rotations[i] = 0;

	// solve puzzle by iterating through each rotation
	while(level_to_rotate < HEIGHT - 1){
		// check if this rotation is the solution

		for (int col = 0; col < NUM_COLUMNS; col++){
			sum = 0;
			// sum all the values of a column
			for(int r = 0; r < MAX_RADIUS; r++){
				int height = 0;
				while (value_in_puzzle(r, col, height) == 0)
					height++;
				sum += value_in_puzzle(r, col, height);	
			}
			if(sum != TARGET_SUM)
				break;
		}

		if(sum == TARGET_SUM)
			break;

		// ---- rotate the puzzle ---- 

		// find which level to rotate (the first level that's not fully rotated)
		level_to_rotate = 0;
		while(level_to_rotate < HEIGHT - 1 && puzzle_rotations[level_to_rotate] == NUM_COLUMNS - 1)
			puzzle_rotations[level_to_rotate++] = 0; // reset any fully rotated level to 0

		for(int i = 0; i <= level_to_rotate; i++)
			puzzle_rotations[i]++;
	}

	// output puzzle rotations
	for (int i = 0; i < HEIGHT - 1; i++)
		printf("Rotation of disk %i: %i\n", i, puzzle_rotations[i]);
}
