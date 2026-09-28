class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for (int it : s) {
            mp[it]++;
        }

        priority_queue<pair<int, char>> mh;

        for (auto it : mp)
            mh.push({it.second, it.first});

        string res;

        while (mh.size() > 1) {
            auto [frq1, char1] = mh.top();
            mh.pop();
            auto [frq2, char2] = mh.top();
            mh.pop();

            res += char1;
            res += char2;

            if (frq1 > 1)
                mh.push({--frq1, char1});
            if (frq2 > 1)
                mh.push({--frq2, char2});
        }

        if(!mh.empty()){
            auto [frq, char1] = mh.top();
            if(frq > 1)
                return "";

            res += char1;
        }

        return res;
    }
};