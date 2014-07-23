#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        vector<vector<vector<char>>> answer;
        processGrid(board, 0, answer);
        board = answer[0];
    }

    void processGrid(vector<vector<char> > &board, int grid, vector<vector<vector<char>>> &answer) {
        if (grid >= 81) {
            answer.push_back(board);
            return;
        }

        int row = grid / 9;
        int col = grid % 9;
        if (board[row][col] == '.') {
            for (int i=1; i<= 9; ++i)
            {
                board[row][col] = '0' + i;
                if (isValid(board, row, col)) {
                    processGrid(board, grid + 1, answer);
                }
            }
            board[row][col] = '.';
        }
        else {
            processGrid(board, grid + 1, answer);
        }
    }

    bool isValid(vector<vector<char> > &board, int row, int col) {
        for (int i=0; i<9; ++i)
        {
            if (i == row)
                continue;
            if (board[i][col] == board[row][col])
                return false;
        }

        for (int i=0; i<9; ++i)
        {
            if (i == col)
                continue;
            if (board[row][i] == board[row][col])
                return false;
        }

        int sub_board_x = col / 3 * 3;
        int sub_board_y = row / 3 * 3;
        for (int i=0; i<3; ++i)
        {
            for (int j=0; j<3; ++j)
            {
                if ((sub_board_y + j) == row && (sub_board_x + i) == col)
                    continue;
                if (board[sub_board_y + j][sub_board_x + i] == board[row][col])
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    int A[][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    vector<vector<char>> board(9);
    for (int i=0;i<9;++i)
    {
        for (int j=0;j<9;++j)
            board[i].push_back(A[i][j]);
    }
    Solution s;
    s.solveSudoku(board);
    return 0;
}
