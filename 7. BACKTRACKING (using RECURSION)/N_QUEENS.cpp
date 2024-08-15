#include <iostream>
#include <vector>
using namespace std;
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
    // check karna chahte hai ke kya mai current cell [row,col] pr queen rakh sakta hun ya nai

    int i = row;
    int j = col;

    // CHECK THE ROW
    while (j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        j--;
    }
    // CHECK UPPER LEFT DIAGONAL
    i = row;
    j = col;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i--;
        j--;
    }
    // CHECK LOWER LEFT DIAGONALS
    i = row;
    j = col;
    while (i < n && j >= 0)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
        i++;
        j--;
    }

    // kahi par bhi queen nahi mili iska matlab return kardo true yaani ye position safe hai
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

            // RECURSION SOLUTION LAAYEGA
            solve(board, col + 1, n);

            // BACKTRACKIG
            board[row][col] = '-';
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