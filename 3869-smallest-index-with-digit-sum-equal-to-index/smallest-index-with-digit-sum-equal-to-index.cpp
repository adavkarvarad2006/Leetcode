class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            int count = 0;

            while(nums[i] != 0){
                count += nums[i]%10;
                nums[i] /= 10;
            }

            if(count == i){
                return i;
            }
        }

        return -1;
    }
};