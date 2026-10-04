class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;
        int high = 0;

        for(char c:s){
            if(c == '('){
                low++;
                high++;
            }
            else if(c == ')'){
                low--;
                high--;
            }
            else{
                //c is '*'
                low--;    //assume * as )
                high++;    //assume * as (
            }

            if(high < 0)
                return false;
            
            if(low < 0)
                low = 0;
        }

        if(low == 0)
            return true;
        
        return false;
    }
};