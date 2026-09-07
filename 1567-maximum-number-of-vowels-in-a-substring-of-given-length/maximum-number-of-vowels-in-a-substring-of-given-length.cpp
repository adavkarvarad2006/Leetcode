class Solution {
public:
    int maxVowels(string s, int k) {
        int count = 0;

        //first window
        for(int i=0; i<k; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count++;
            }
        }

        int ans = count;

        //slide the window
        for(int i=k; i<s.length(); i++){
            //remove the character leaving the window
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i' || s[i-k] == 'o' || s[i-k] == 'u'){
                count--;
            }

            //add the new character entering the window
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};