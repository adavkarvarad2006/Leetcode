class Solution {
public:
    bool isValid(string &curr){
        int count = 0;

        for(char c:curr){
            if(c == '(')
                count++;
            else if(c == ')'){
                count--;

                if(count < 0)
                    return false;
            }
        }

        if(count == 0)
            return true;
        else
            return false;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
        
        q.push(s);
        visited.insert(s);

        bool found = false;

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            if(isValid(curr)){
                ans.push_back(curr);
                found = true;
            }

            //valid strings are found at this level, don't generate strings with more removals
            if(found)
                continue;

            for(int i=0; i<curr.size(); i++){
                if(curr[i] != '(' && curr[i] != ')'){
                    continue;
                }

                string next = curr.substr(0,i) + curr.substr(i+1);

                if(!visited.count(next)){
                    visited.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};