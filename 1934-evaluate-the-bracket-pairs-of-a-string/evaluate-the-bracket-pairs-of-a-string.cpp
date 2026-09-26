class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for(auto it:knowledge){
            mp[it[0]] = it[1];
        }

        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                int start = i+1;

                //closing bracket
                int j = start;
                while(s[j] != ')')
                    j++;

                //Extract key
                string key = s.substr(start, j - start);

                //Find value
                string value = "?";
                if(mp.count(key))
                    value = mp[key];

                //Replace (key) with value
                s.replace(i, j-i+1, value);

                //Move i
                i += value.length()-1;
            }
        }

        return s;
    }
};