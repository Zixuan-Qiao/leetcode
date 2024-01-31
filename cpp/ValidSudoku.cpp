class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // check the rows
        for (auto r : board) {
            multiset<char> ms(r.cbegin(), r.cend());
            int n = ms.erase('.');
            set<char> s(ms.cbegin(), ms.cend());
            if (s.size() < 9 - n)
                return false;
        }

        // check the columns
        for (int i = 0; i < board[0].size(); i++) {
            multiset<char> ms;
            for (int j = 0; j < board.size(); j++) {
                ms.insert(board[j][i]);
            }
            int n = ms.erase('.');
            set<char> s(ms.cbegin(), ms.cend());
            if (s.size() < 9 - n)
                return false;
        }
        
        // check the sub-boxes
        for (int i = 0; i < board.size(); i += 3){
            for (int j = 0; j < board[0].size(); j += 3){
                multiset<char> ms{board[i][j], board[i][j+1], board[i][j+2], 
                                  board[i+1][j], board[i+1][j+1], board[i+1][j+2], 
                                  board[i+2][j], board[i+2][j+1], board[i+2][j+2]};
                int n = ms.erase('.');
                set<char> s(ms.cbegin(), ms.cend());
                if (s.size() < 9 - n)
                    return false;
            }
        }

        return true;
    }
};