#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagonalCheck;
unordered_map<int,bool> bottomLeftDiagonalCheck;

void printSolution(vector<vector<char>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool isSafe(int row, int col, vector<vector<char>> &board, int n)
{
   if (rowCheck[row] == true)
    return false;
   if(upperLeftDiagonalCheck[n-1+col-row] == true)
   return false;
   if(bottomLeftDiagonalCheck[row+col] == true)
   return false;
   return true;
}

void solve(vector<vector<char>> board, int col, int n)
{
    // BASE CASE
    if (col >= n)
    {
        printSolution(board, n);
        return;
    }

    // EK CASE SOLVE KARNA HAI , BAAKI RECURSION SAMBHAL LEGA
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // RAKHDO
            board[row][col] = 'Q';
            rowCheck[row] = true;
            upperLeftDiagonalCheck[n-1+col-row] = true;
            bottomLeftDiagonalCheck[row+col] = true;

            // RECURSION SOLUTION LAAYEGA
            solve(board, col + 1, n);

            // BACKTRACKIG
            board[row][col] = '-';
                        rowCheck[row] = false;
            upperLeftDiagonalCheck[n-1+col-row] = false;
            bottomLeftDiagonalCheck[row+col] = false;
        }
    }
}

int main()
{
// YAHA HUM 5 Queens ko place krr rhe hai 5*5 matrix me , tumhe kisi aur number of queens ko place karna hai to n ki value change karlo;
    int n = 5;
    vector<vector<char>> board(n, vector<char>(n, '-'));
    int col = 0;
    // 0 ka matlab --> empty cell
    // 1 ka matlab --> Queen at the cell , i.e non empty cell

    solve(board, col, n);
    return 0;
}