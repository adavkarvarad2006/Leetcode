class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int ans = 1;
        int count = 1;
        int maxL = 0;
        for(int i = 1; i<word.length(); i++){
            if(word[i] < word[i-1]){
                ans = 1;
                count = 1;
            }
            else if(word[i] > word[i-1]){
                count++;
                ans++;
            }
            else{
                ans++;
            }
            if(count == 5){
                maxL = max(ans, maxL);
            }
        }

        return maxL;
    }

    
};