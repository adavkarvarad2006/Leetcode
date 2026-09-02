class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<int> ans;

        //count frequency
        for(int num : nums){
            freq[num]++;
        }

        //Min heap : {freq, element}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        //keep only k most frequent elements
        for(auto it : freq){
            pq.push({it.second, it.first});
            
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};