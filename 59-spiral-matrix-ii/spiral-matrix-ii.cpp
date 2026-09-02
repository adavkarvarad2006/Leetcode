class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n));

        int top = 0, bottom = n-1;
        int left = 0, right = n-1;

        int a=1;

        while(top <= bottom && left <= right){
            for(int col = left; col <= right; col++){
                ans[top][col] = a;
                a++;
            }
            top++;

            for(int row = top; row <= bottom; row++){
                ans[row][right] = a;
                a++;
            }
            right--;

            if(top <= bottom){
                for(int col = right; col >= left; col--){
                    ans[bottom][col] = a;
                    a++;
                }
                bottom--;
            }

            if(left <= right){
                for(int row = bottom; row >= top; row--){
                    ans[row][left] = a;
                    a++;
                }
                left++;
            }
        }

        return ans;
    }
};