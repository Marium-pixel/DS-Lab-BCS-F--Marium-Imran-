/*Create a program that solves the N-Queens problem for any given N using backtracking. The
program should print all possible solutions for placing N queens on an N x N chessboard so
that no two queens threaten each other. This task requires you to use a recursive function to
place queens row by row , and a validation function to check if a queen can be placed in a
specific cell. If a placement leads to a conflict, the algorithm should backtrack to the previous
row and try a different column.

 */
#include <iostream>
#include <vector>
using namespace std;

void printSolution(const vector<int>& board, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << (board[i] == j ? 'Q' : '.') << " ";
        cout << '\n';
    }
    cout << '\n';
}

bool isSafe(const vector<int>& board, int row, int col) {
    for (int i = 0; i < row; ++i) {
        int placedCol = board[i];
        if (placedCol == col) return false;                     
        if (abs(placedCol - col) == abs(i - row)) return false; 
    }
    return true;
}

void solveNQueensUtil(vector<int>& board, int row, int N, long long &count) {
    if (row == N) {
        printSolution(board, N);
        ++count;
        return;
    }
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueensUtil(board, row + 1, N, count);
            board[row] = -1; 
        }
    }
}

int main() {
    int N;
    cout << "Enter value of N: ";//enter 4
    if (!(cin >> N)) return 0;
    if (N <= 0) {
        cout << "N must be a positive integer.\n";
        return 0;
    }

    vector<int> board(N, -1);
    long long solutions = 0;

    cout << "All possible solutions for " << N << "-Queens:\n\n";
    solveNQueensUtil(board, 0, N, solutions);

    if (solutions == 0)
        cout << "No solutions found for N = " << N << '\n';
    else
        cout << "Total solutions: " << solutions << '\n';

    return 0;
}

