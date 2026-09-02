class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        if(matrix.empty() || matrix[0].empty()) return result;

        int top=0, bottom = matrix.size()-1;
        int left=0, right = matrix[0].size()-1;

        while(top <= bottom && left <= right){
            //traverse left to right along top row
            for(int col = left; col <= right; col++){
                result.push_back(matrix[top][col]);
            }
            top++;

            //traverse top to bottom along right col
            for(int row = top; row <= bottom; row++){
                result.push_back(matrix[row][right]);
            }
            right--;

            // traverse right to left along bottom row (if still valid)
            if(top <= bottom){
                for(int col = right; col >= left; col--){
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // traverse bottom to top along left column (if still valid)
            if(left <= right){
                for(int row = bottom; row >= top; row--){
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return result;
    }
};