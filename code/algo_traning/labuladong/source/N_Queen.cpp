#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> solutions;

    bool isValid(const vector<string>& board, int row, int col) {
        int n = board.size();
        
        // 检查列
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // 检查左上对角线
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        
        // 检查右上对角线
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }

    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            solutions.push_back(board);
            return;
        }
        
        for (int col = 0; col < board.size(); col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                printBoard(board);
                cout << " back " << endl;
                backtrack(board, row + 1);
                board[row][col] = '.';  // 回溯
                printBoard(board);
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return solutions;
    }

    void printSolutions() {
        for (int i = 0; i < solutions.size(); i++) {
            cout << "Solution " << i + 1 << ":\n";
            for (const string& row : solutions[i]) {
                cout << row << "\n";
            }
            cout << "\n";
        }
        cout << "Total solutions: " << solutions.size() << "\n";
    }
    void printBoard(vector<string>& board){
        for (const string& row : board) {
            cout << row << "\n";
        }
    }
};

int main() {
    Solution solver;
    solver.solveNQueens(4);
    solver.printSolutions();
    return 0;
}