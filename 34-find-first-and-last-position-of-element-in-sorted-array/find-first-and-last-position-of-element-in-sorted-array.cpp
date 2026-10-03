class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        while(left < right){
            int mid = left + (right - left)/2;

            if(nums[mid] < target)
                left = mid+1;
            else
                right = mid;
        }

        int first = left;

        // Target not present
        if(first == nums.size() || nums[first] != target)
            return {-1, -1};

        // Find position after last occurrence
        left = 0;
        right = nums.size();

        while(left < right) {
            int mid = left + (right - left) / 2;

            if(nums[mid] <= target)
                left = mid + 1;
            else
                right = mid;
        }

        int last = left - 1;

        return {first, last};
    }
};