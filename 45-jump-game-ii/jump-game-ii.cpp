class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int curr_end = 0;
        int farthest = 0;

        for(int i=0; i < nums.size() - 1; i++){
            farthest = max(farthest, i + nums[i]);

            if(i == curr_end){
                jumps++;
                curr_end = farthest;

                if(curr_end >= nums.size() - 1)
                    break;
            }
        }

        return jumps;
    }
};