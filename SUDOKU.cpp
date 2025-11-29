#include<iostream>

using namespace std;

bool IsValid(int A[9][9], int r, int c, int num);
void printBoard(int A[9][9]);
bool solution(int A[9][9]);
bool hint(int A[9][9]);
bool isComplete(int A[9][9]);   


int main(){

    int score = 0;
    int SudokuBoard[9][9] ={{5 ,3 ,0 ,0 ,7 ,0 ,0 ,0 ,0},
                            {6 ,0 ,0 ,1 ,9 ,5 ,0 ,0 ,0},
                            {0 ,9 ,8 ,0 ,0 ,0 ,0 ,6 ,0},
                            {8 ,0 ,0 ,0 ,6 ,0 ,0 ,0 ,3},
                            {4 ,0 ,0 ,8 ,0 ,3 ,0 ,0 ,1},
                            {7 ,0 ,0 ,0 ,2 ,0 ,0 ,0 ,6},
                            {0 ,6 ,0 ,0 ,0 ,0 ,2 ,8 ,0},
                            {0 ,0 ,0 ,4 ,1 ,9 ,0 ,0 ,5},
                            {0 ,0 ,0 ,0 ,8 ,0 ,0 ,7 ,9}};
                        
    cout << "\n     ======Welcome to Sudoku=====\n";
    cout << "Think smart. Move carefully. Solve the grid\n";

   while(true){

        // Display Sudoku Board
        printBoard(SudokuBoard);

        int row;
        cout << "\nEnter the Row number: ";
        cin >> row;
        row--;

        int column;
        cout << "Enter the column number: ";
        cin >> column;
        column--;

        int num;
        cout << "Enter the number you wanna add: ";
        cin >> num;

        if(IsValid(SudokuBoard, row, column, num)){
            SudokuBoard[row][column] = num;
            score += 10;
        if(isComplete(SudokuBoard)) {
            cout << "\nCongratulations! Sudoku is complete.\n";
            printBoard(SudokuBoard);
            cout << "\nYour final score: \n" << score << endl;
            break;  // exit the while loop
            }
        }
        else{
            cout << "Invalid move\n";
            score -= 5;
        }

        char choice_hint;
        cout << "Do you want a HINT? (y/n): ";
        cin >> choice_hint;

        if(choice_hint == 'y' || choice_hint == 'Y'){
            if(hint(SudokuBoard)){
            cout << "\nHere is a HINT\n";
            printBoard(SudokuBoard);
            score -= 10;
            }
            else{
            cout << "\nNo HINT available\n";
            }
            if(isComplete(SudokuBoard)) {
            cout << "\nCongratulations! Sudoku is complete.\n";
            printBoard(SudokuBoard);
            cout << "Your final score: " << score << endl;
            break;  // exit the while loop
            }
        }
        else{
            cout << "\nContinue solving manually\n";
        }

        char choice_solution;
        cout << "\nDo you want the solved SUDOKU BOARD? (y/n): ";
        cin >> choice_solution;

        if(choice_solution == 'y' || choice_solution == 'Y'){
            if(solution(SudokuBoard)){
            cout << "\nHere is your solved SUDOKU BOARD\n";
            printBoard(SudokuBoard);
            score -= 20;
            }
            else{
            cout << "\nNo solution exists for this SUDOKU BAORD\n";
            }
            if(isComplete(SudokuBoard)) {
            cout << "\nCongratulations! Sudoku is complete.\n";
            printBoard(SudokuBoard);
            cout << "Your final score: " << score << endl;
            break;  // exit the while loop
            }
        }
    }
    return 0;
}

bool IsValid(int A[9][9], int r, int c, int num){

        if(r < 0 || r > 8 || c < 0 || c > 8 ){
            return false;
        }
        if(num < 1 || num > 9){
            return false;
        }
        // Row check
    for(int i = 0; i < 9; i++){
        if(A[r][i] == num){
            return false;
        }
    }
    // Column check
    for(int i = 0; i < 9; i++){ 
        if(A[i][c] == num){
            return false;
        }
    }

    int x = r - r % 3; //top left row of the box
        int y = c - c % 3; //top left column of the box
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(A[x + i][y + j] == num){ // checking each box inside 3x3 grid
                return false;
                }
            }
    }
    return true;
}

void printBoard(int A[9][9]){
    cout << "\n=========== S U D O K U ===========\n\n";

    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i != 0)
            cout << " +----------+----------+----------+\n";
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0)
                cout << " |";

            if (A[i][j] == 0)
                cout << "   ";
            else
               cout << "\033[32m" << " " << A[i][j] << "\033[0m ";
        }
        cout << " |\n";
    }
}

bool solution(int A[9][9]){

    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if(A[r][c] == 0){
                for(int num = 1; num <= 9; num++){
                    if(IsValid(A, r, c, num)){
                        A[r][c] = num;
                        if(solution(A)){ // It'll solve the remaining board recursively
                            return true;
                        }
                            A[r][c] = 0; // for backtracking                        
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool hint(int A[9][9]){
    int temp[9][9];
    // Copy the board
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
            temp[i][j] = A[i][j];

    for(int r = 0; r < 9; r++){
        for(int c = 0; c < 9; c++){
            if(A[r][c] == 0){
                for(int num = 1; num <= 9; num++){
                    if(IsValid(A, r, c, num)){
                        A[r][c] = num;
                        if(solution(A)) { // test if board is solvable
                            A[r][c] = num; // keep this as hint
                            return true;
                        }
                        A[r][c] = 0; // backtrack
                    }
                }
                // No number works, restore board
                for(int i=0;i<9;i++)
                    for(int j=0;j<9;j++)
                        A[i][j] = temp[i][j];
                return false;
            }
        }
    }
    return false;
}

bool isComplete(int A[9][9]) {
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            if(A[r][c] == 0)  // check if there is any empty cell
                return false;
        }
    }
    return true; // if there is no empty cell
}
