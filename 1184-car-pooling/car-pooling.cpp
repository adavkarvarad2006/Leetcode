class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        vector<long long> count(1001, 0);
        
        for(auto it:trips){
            int num = it[0];
            int from = it[1];
            int to = it[2];

            for(int j=from; j<to; j++){
                count[j] += num;
            }
        }

        for(int i=0; i<count.size(); i++){
            if(count[i] > capacity){
                return false;
            }
        }

        return true;
    }
};