class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        //change two smallest elements
        int a = abs(nums[2] - nums[n-1]);

        //change two largest elements
        int b = abs(nums[0] - nums[n-3]);

        //change smallest and largest element (nums[0] and nums[n-1])
        int c = abs(nums[1] - nums[n-2]);

        //in all above 3 cases, we are changing the two elements to same value to get low score as 0
        //we only need to calculate the high score

        return min({a, b, c});
    }
};