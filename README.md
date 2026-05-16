# Backtracking Sudoku Solver in C

A **Sudoku Solver** written in C that utilizes a deterministic **Backtracking algorithm** to solve any valid $9 \times 9$ Sudoku puzzle. 

The project is structured modularly, separating the core solving logic and definitions into a header file (`utility.h`) and the execution/grid manipulation into the main source file (`sudoku.c`).

## How the Algorithm Works

The solver approaches the puzzle using a brute-force depth-first search enhanced by pruning (backtracking):

1. **Find an unassigned cell:** The program searches the grid for an empty slot (represented by `0`).
2. **Formulate hypotheses:** It attempts to assign a digit from `1` to `9` to that cell.
3. **Validate constraints:** It checks if the digit is valid according to standard Sudoku rules:
   * Unique in the current **Row**.
   * Unique in the current **Column**.
   * Unique in the local **$3 \times 3$ Box**.
4. **Recurse or Backtrack:** 
   * If the assignment is valid, it recursively moves to the next empty cell.
   * If a dead-end is reached (no numbers from 1-9 fit), it triggers **backtracking** by resetting the cell to `0` and returning to the previous step to try the next available number.

---

## Complexity Analysis

| Metric | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Worst-Case** | $O(9^{m})$ | $O(m)$ |

*Where $m$ represents the number of empty cells in the grid.* 
* **Time:** In the worst-case scenario, the algorithm could explore a massive search space, though standard puzzles are solved in a fraction of a millisecond due to immediate constraint pruning.
* **Space:** The space complexity is determined by the recursion stack, which is bounded by the maximum number of empty cells ($m \le 81$).

---

## Compilation and Execution

Since the project is divided into multiple files, you need to compile them together using `gcc`:

```bash
gcc sudoku.c -o sudoku
./sudoku