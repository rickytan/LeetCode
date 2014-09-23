#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<char> > board;
    map<char, vector<pair<int, int> > > reverseIndex;
    string word;
    int row;
    int col;

    bool exist(vector<vector<char> > &board, string word) {
        this->board = board;
        this->word = word;

        row = board.size();
        if (row == 0)
            return false;
        col = board[0].size();
        if (col == 0)
            return false;
        for (int i=0; i<row; ++i)
        {
            for (int j=0; j<col; ++j)
            {
                reverseIndex[board[i][j]].push_back(make_pair(i, j));
            }
        }
        
        return dfs(-1, -1, 0);
    }

    bool inside(int r, int c) {
        return (0 <= r && r < row && 0 <= c && c < col);
    }

    bool dfs(int r, int c, int charIdx) {
        if (charIdx == word.length())
            return true;
        char ch = word[charIdx];

        if (r == -1 && c == -1) {
            vector<pair<int, int> > indexes = reverseIndex[ch];
            for (int i=0; i<indexes.size(); ++i)
            {
                int m = indexes[i].first;
                int n = indexes[i].second;
                board[m][n] = 0;
                if (dfs(m, n, charIdx+1))
                    return true;
                board[m][n] = ch;
            }
            return false;
        }
        else {
            bool rtnval = false;
            if (inside(r-1, c) && board[r-1][c] == ch) {
                board[r-1][c] = 0;
                if (dfs(r-1, c, charIdx+1))
                    return true;
                board[r-1][c] = ch;
            }
            if (inside(r+1, c) && board[r+1][c] == ch) {
                board[r+1][c] = 0;
                if (dfs(r+1, c, charIdx+1))
                    return true;
                board[r+1][c] = ch;
            }
            if (inside(r, c-1) && board[r][c-1] == ch) {
                board[r][c-1] = 0;
                if (dfs(r, c-1, charIdx+1))
                    return true;
                board[r][c-1] = ch;
            }
            if (inside(r, c+1) && board[r][c+1] == ch) {
                board[r][c+1] = 0;
                if (dfs(r, c+1, charIdx+1))
                    return true;
                board[r][c+1] = ch;
            }
            return false;
        }
    }
};

int main()
{
    vector<vector<char> > board(3);
    board[0].push_back('A');
    board[0].push_back('A');
    board[0].push_back('A');
    board[0].push_back('A');

    board[1].push_back('A');
    board[1].push_back('A');
    board[1].push_back('A');
    board[1].push_back('A');

    board[2].push_back('A');
    board[2].push_back('A');
    board[2].push_back('A');
    board[2].push_back('A');
    Solution s;
    cout << s.exist(board, "AAAAAAAAAAAA");

    return 0;
}