class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> col(9, vector<bool>(9, false));
        vector<vector<bool>> row(9, vector<bool>(9, false));
        vector<vector<bool>> block(9, vector<bool>(9, false));

        for (int i = 0 ; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); j++){
                if (board[i][j] == '.') continue;
                int v = board[i][j] - 49;
                if (row[j][v]) return false;
                else row[j][v] = true;
                if (col[i][v]) return false;
                else col[i][v] = true;
                if (block[(i/3)*3+j/3][v]) return false;
                else block[(i/3)*3+j/3][v] = true;
            }
        }
        return true;
    }
};
