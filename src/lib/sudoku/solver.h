#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

// Laenge von Zeilen & Spalten
#define SUDOKU_GROESSE 9
#define SUDOKU_FIELD_COUNT_PER_ROW 3
#define SUDOKU_MAX_LOESUNGEN 5

//extern int iTest[SUDOKU_GROESSE][SUDOKU_GROESSE];

extern int iSudokuAnzahlLoesungen;
extern int iSudokuLoesungen[SUDOKU_MAX_LOESUNGEN]
                           [SUDOKU_GROESSE]
                           [SUDOKU_GROESSE];


void _sudokuCopy(int iIndex, int *iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]);
void _sudokuDebugPrint(int *iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]);


int sudokuSolve(int *iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]);


int _sudokuCheckRowForValue(int iRow, int iValue,
                              int *iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]);
int _sudokuCheckForNumber(int iColumn, int iRow, int iValue,
                           int *iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]);
int _sudokuCheckFieldForValue(int iColumn, int iRow, int iValue,
                              int *iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]);
int _sudokuCheckColumnForValue(int iColumn, int iValue,
                                 int *iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]);
int _sudokuSolveWithIndex(int iColumn, int iRow,
                           int *iSudoku[SUDOKU_GROESSE][SUDOKU_GROESSE]);



#endif // SUDOKU_SOLVER_H