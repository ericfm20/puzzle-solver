CC=gcc
CFLAGS=-O2
TARGET=solver

puzzle-solver:
	$(CC) $(CFLAGS) puzzle_solver.c -o $(TARGET)

run: 
	@make puzzle-solver
	@./$(TARGET) puzzle.txt
