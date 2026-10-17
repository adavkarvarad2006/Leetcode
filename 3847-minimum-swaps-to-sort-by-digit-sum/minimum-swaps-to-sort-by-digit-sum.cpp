class Solution {
public:
    int digitSum(int num){
        int ans = 0;

        while(num > 0){
            ans += num%10;
            num /= 10;
        }

        return ans;
    }

    int minSwaps(vector<int>& nums) {

        int n = nums.size();
        vector<pair<pair<int, int>, int>> arr;

        for(int i=0; i<n; i++){
            arr.push_back({{digitSum(nums[i]), nums[i]}, i});
        }

        sort(arr.begin(), arr.end());

        int swaps = 0;

        vector<bool> visited(n, false);

        for(int i=0; i<n; i++){
            if(visited[i] || arr[i].second == i)
                continue;

            int j = i;
            int cycleSize = 0;

            while(!visited[j]){
                visited[j] = true;
                j = arr[j].second;
                cycleSize++;
            }

            swaps += cycleSize-1;
        }

        return swaps;
    }
};