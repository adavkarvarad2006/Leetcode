class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int index, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(index == candidates.size())
            return;

        //include
        if(candidates[index] <= target){
            temp.push_back(candidates[index]);

            solve(candidates, target - candidates[index], index + 1, temp);

            //backtrack
            temp.pop_back();
        }

        // Exclude all duplicate occurrences
        int next = index + 1;

        while(next < candidates.size() && candidates[next] == candidates[index]){
            next++;
        }

        //exclude
        solve(candidates, target, next, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, temp);

        return ans;
    }
};