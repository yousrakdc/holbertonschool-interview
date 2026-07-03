#!/usr/bin/python3
"""N Queens puzzle solver.

Solves the N queens problem using backtracking and prints every
possible solution, one per line, in the form of a list of
[row, column] pairs.
"""
import sys


def is_safe(cols, row, col):
    """Check if a queen can be placed at (row, col).

    cols is a list where cols[i] is the column of the queen placed
    in row i, for rows already filled (0 to row - 1).
    """
    for r in range(row):
        c = cols[r]
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve(n):
    """Find all solutions to the N queens problem for a board of size n."""
    solutions = []
    cols = [-1] * n

    def backtrack(row):
        if row == n:
            solutions.append([[r, cols[r]] for r in range(n)])
            return
        for col in range(n):
            if is_safe(cols, row, col):
                cols[row] = col
                backtrack(row + 1)
                cols[row] = -1

    backtrack(0)
    return solutions


def main():
    """Parse arguments and run the N queens solver."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    for solution in solve(n):
        print(solution)


if __name__ == "__main__":
    main()
