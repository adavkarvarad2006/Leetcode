class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans;

        for(int i : nums){
            st.insert(i);
        }

        for(int i=1; i<=nums.size(); i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};