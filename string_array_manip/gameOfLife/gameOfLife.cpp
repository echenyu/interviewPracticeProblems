class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() == 0) {
            return; 
        }
        
        vector<int> columns(board[0].size(), 0); 
        vector<vector<int>> nextState(board.size(), columns); 
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                findNextState(board, nextState, i, j); 
            }
        }
        
        board = nextState; 
    }
    
    void findNextState(vector<vector<int>> &board, vector<vector<int>> &nextState, int row, int col) {
        bool alive = board[row][col]; 
        int liveNeighbors = 0; 
        
        //Handle all cases where we're looking at one row greater than current row
        for(int i = max(row - 1, 0); i <= min(row+1, (int)board.size()-1); i++) {
            for(int j = max(col-1, 0); j <= min(col+1, (int)board[0].size()-1); j++) {
                if(i == row && j == col) continue; 
                if(board[i][j]) liveNeighbors++; 
            }
        }

        if(alive) {
            if(!(liveNeighbors < 2 || liveNeighbors > 3)) {
                nextState[row][col] = 1; 
            } 
        } else {
            if(liveNeighbors == 3) {
                nextState[row][col] = 1; 
            }
        }
    }
};