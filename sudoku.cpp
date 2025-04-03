class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> rows[9], cols[9], subgrids[9];

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;  s

                char num = board[i][j];
                string rowKey = "r" + to_string(i) + "-" + num;
                string colKey = "c" + to_string(j) + "-" + num;
                string subgridKey = "s" + to_string(i / 3 * 3 + j / 3) + "-" + num;

                
                if (rows[i].count(rowKey) || cols[j].count(colKey) || subgrids[i / 3 * 3 + j / 3].count(subgridKey)) {
                    return false;
                }

                rows[i].insert(rowKey);
                cols[j].insert(colKey);
                subgrids[i / 3 * 3 + j / 3].insert(subgridKey);
            }
        }

        return true; 
    }
};
