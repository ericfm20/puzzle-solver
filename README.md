# Puzzle Solver

Solves the [True Genius](https://www.projectgeniusinc.com/true-genius-collection) Grecian Computer puzzle.

![Puzzle Image](https://images.squarespace-cdn.com/content/v1/589b3ae2414fb58b9ed55a9f/1572981113694-LR43RZRO0VKY84RB8VXH/GreekComputer.TG406.OB.Solved.png?format=300w)

## Usage

Note: using `make` requires `gcc`.

- Run `make run` to automatically run the solver after it compiles.
	- This requires `puzzle.txt` to be in the same directory.

- Or, compile `puzzle_solver.c` yourself or with `make`. Then run the program with the `puzzle.txt` file as its only argument.

## Modifications

You can modify `puzzle.txt` to contain any set of numbers for any similar puzzle.
However, there are specific requirements:

- Each row must be a single circle on the puzzle.
- There must be spaces between each number
- Numbers start with the top disk and go down with each set of rows.
- 0 represents an empty space and a row of 0's means it is an empty circle.

The headers in the `puzzle_solver.c` file can also be easily modified for similar puzzles.

