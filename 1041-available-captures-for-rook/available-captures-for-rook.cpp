class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int dx[] = {0,-1,0,1};
        int dy[] = {-1,0,1,0};

        int x, y;

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == 'R'){
                    x = i;
                    y = j;
                }
            }
        }

        int count = 0;

        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];

            while(xx >= 0 && xx < 8 && yy >= 0 && yy < 8){
                if(board[xx][yy] == 'B')
                    break;
                else if(board[xx][yy] == '.'){
                    xx += dx[i];
                    yy += dy[i];
                    continue;
                }
                else{
                    //p
                    count++;
                    break;
                }
            }
        }

        return count;
    }
};