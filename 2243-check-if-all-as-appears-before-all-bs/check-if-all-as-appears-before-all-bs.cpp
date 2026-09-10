class Solution {
public:
    bool checkString(string s) {
        bool flag = false;

        if(s.contains("ba")){
            return false;
        }
        
        return true;
    }
};