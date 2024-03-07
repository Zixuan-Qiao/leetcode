class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(m * n < word.size()) {
            return false;
        }

        vector<vector<int>> used(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == word[0]) {
                    used[i][j] = 1;
                    if(backtrack_dfs(used,i, j, 1, board, word)) {
                        return true;
                    }
                    used[i][j] = 0;
                }
            }
        }
        return false;
    }

    bool backtrack_dfs(vector<vector<int>>& used, int i, int j, int count, vector<vector<char>>& board, string word) {
        if(count == word.size()) {
            return true;
        }

        if(i - 1 >= 0 && board[i - 1][j] == word[count] && used[i - 1][j] == 0) {
            used[i - 1][j] = 1;
            if(backtrack_dfs(used, i - 1, j, count + 1, board, word)) {
                return true;
            }
            used[i - 1][j] = 0;
        }

        if(j + 1 <board[0].size() && board[i][j + 1] == word[count] && used[i][j + 1] == 0) {
            used[i][j + 1] = 1;
            if(backtrack_dfs(used, i, j + 1, count + 1, board, word)) {
                return true;
            }
            used[i][j + 1] = 0;
        }

        if(i + 1 < board.size() && board[i + 1][j] == word[count] && used[i + 1][j] == 0) {
            used[i + 1][j] = 1;
            if(backtrack_dfs(used, i + 1, j, count + 1, board, word)) {
                return true;
            }
            used[i + 1][j] = 0;
        }

        if(j - 1 >= 0 && board[i][j - 1] == word[count] && used[i][j - 1] == 0) {
            used[i][j - 1] = 1;
            if(backtrack_dfs(used, i, j - 1, count + 1, board, word)) {
                return true;
            }
            used[i][j - 1] = 0;
        }
        return false;
    }
};