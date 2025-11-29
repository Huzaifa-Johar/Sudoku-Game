# Sudoku-Game
# Sudoku Game, Checker, and Solver

## Project Information

**Course:** CS 110 - Fundamentals of Computer Programming  
**Assignment:** Assignment #2  
**Submission Date:** 23rd November 2025

### Team Members


| Huzaifa Johar |     553079    | IsValid() & printBoard() |
| Shahzaib Ali  |     576928    | solution() & hint()      |
| Talal tahir   |     551712    | Main loop & isComplete() |

---

## Overview

A console-based Sudoku game that lets you:
- Play on a 9×9 grid with pre-filled numbers
- Validate moves according to Sudoku rules
- Get hints when stuck (-10 points)
- Auto-solve the puzzle (-20 points)
- Track your score based on performance


## Design and Logic

### Core Functions

**1. IsValid(grid, row, col, num)**
- Checks if a number can be placed at given position
- Validates: row constraint, column constraint, 3×3 subgrid
- Returns `true` if valid, `false` otherwise

**2. printBoard(grid)**
- Displays the current Sudoku board
- Uses green color for filled numbers
- Formats with dividing lines for 3×3 boxes

**3. solution(grid)** 
- Backtracking Algorithm
- Finds empty cells (value = 0)
- Tries numbers 1-9
- Recursively solves remaining board
- Backtracks if stuck

**4. hint(grid)**
- Makes a copy of the board
- Finds first empty cell
- Fills it with valid number
- Tests if board is still solvable
- Returns the hint

**5. isComplete(grid)**
- Checks if all cells are filled
- Returns `true` when puzzle is complete

### Grid Handling
- **2D Array:** `int grid[9][9]`
- **Empty cells:** Represented as `0`
- **Initial board:** Partially filled (easy difficulty)

### Scoring System
- Correct move: +10 points
- Invalid move: -5 points
- Hint: -10 points
- Full solution: -20 points

---

## Execution Instructions

### Compilation and Running

To compile the program, navigate to the directory containing the source code file and use a C++ compiler. For g++ compiler, use the command `g++ sudoku.cpp -o sudoku`. This will create an executable file named sudoku. On Linux or Mac systems, run the program using `./sudoku`, while on Windows systems, execute it using `sudoku.exe`.

### How to Play

When you launch the program, the Sudoku board appears with some cells filled in and empty cells shown as blank spaces. The board uses a grid where rows and columns are numbered from 1 to 9. To make a move, the program first shows the current board state and then asks you to enter the row number (1-9). After you enter the row, you will be prompted to enter the column number (1-9), followed by the number you want to place in that cell (1-9).

If your move is valid according to Sudoku rules, the number will be added to the board and your score will increase by 10 points. If the move breaks any rule, an "Invalid move" message will appear and 5 points will be taken off your score. After each move attempt, the program asks if you want a hint by entering 'y' or 'n'. If you request a hint, one empty cell will be filled with the correct number, but this will cost you 10 points.

After the hint prompt, you will be asked if you want the complete solution. If you enter 'y', the program will solve the entire puzzle using the backtracking algorithm, but this will cost you 20 points. The game continues in this loop until all cells are correctly filled. At that point, a congratulations message will appear along with your final score.

### Sample Input and Output

When the program starts, you will see the board displayed with vertical and horizontal dividers separating the 3x3 subgrids. For example, if the board shows an empty cell at row 1, column 3, you would enter:
- Row number: 1
- Column number: 3  
- Number to add: 4

The program will validate this move. If valid, the number 4 will appear in green at position (1,3) on the board. The program then asks for hint preference (y/n) and solution preference (y/n) before allowing the next move. This process repeats until the puzzle is complete.

---

## AI Tool Usage

**Tool:** Claude AI  
**Purpose:** 
- Debugging backtracking logic
- Code structure suggestions

All core logic and implementation was developed by the team.

---

## Future Enhancements

- Add difficulty levels (Easy/Medium/Hard)
- Implement puzzle generator
- Add undo/redo functionality
- Create GUI version
- Add timer and leaderboard

---

