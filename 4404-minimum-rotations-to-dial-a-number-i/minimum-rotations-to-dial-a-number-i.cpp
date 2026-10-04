class Solution {
public:
    int minRotations(string s) {
        int ans = 0;
        int curr = 0;

        for(char c:s){
            int temp = c - '0';
            
            int rot = abs(temp - curr);

            if(rot > 5)
                rot = 10 - rot;

            ans += rot;

            curr = temp;
        }

        return ans;
    }
};