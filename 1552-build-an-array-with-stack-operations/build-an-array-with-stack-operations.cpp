class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        stack<int> s;

        int i=1;
        int j=0;

        while(s.size() != target.size()){
            s.push(i);
            ans.push_back("Push");

            bool flag = false;
            if(s.top() != target[j]){
                s.pop();
                ans.push_back("Pop");
                flag = true;
            }

            i++;

            if(!flag)
                j++;
        }

        return ans;
    }
};