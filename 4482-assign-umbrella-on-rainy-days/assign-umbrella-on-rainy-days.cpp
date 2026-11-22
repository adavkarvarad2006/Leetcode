class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int n = rain.size();
        vector<string> ans;

        int Alice = 0;
        int Bob = 0;

        for(int i=0; i<n; i++){
            if(rain[i] == 0){
                ans.push_back("None");
            }
            else if(i < n-1 && rain[i] == 1 && rain[i+1] == 1 && Alice <= Bob){
                ans.push_back("Alice");
                Alice++;
            }
            else{
                //nums[i] == 1
                ans.push_back("Bob");
                Bob++;
            }
        }

        return ans;
    }
};