class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        //{value, listndex, elementIndex}
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;

        int maxi = INT_MIN;

        //Insert first element of every list
        for(int i=0; i < nums.size(); i++){
            pq.push({nums[i][0], i, 0});

            maxi = max(maxi, nums[i][0]);
        }

        int range = INT_MAX;
        int left = 0, right = 0;

        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();

            int mini = curr[0];
            int row = curr[1];
            int col = curr[2];

            //update answer
            if(maxi - mini < range){
                range = maxi - mini;
                left = mini;
                right = maxi;
            }

            //If this list is exhausted, stop
            if(col + 1 >= nums[row].size()){
                break;
            }

            //Insert next element from the same list
            int next = nums[row][col + 1];

            pq.push({next, row, col + 1});

            maxi = max(maxi, next);
        }

        return {left, right};
    }
};