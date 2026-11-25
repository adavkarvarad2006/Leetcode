class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        
        //stack stores {type, color, count}
        vector<array<int, 3>> st;

        for(int i=0; i < types.size(); i++){

            int t = types[i];
            int c = colors[i];

            //same type and same color as stack top
            if(!st.empty() && st.back()[0] == t && st.back()[1] == c){

                st.back()[2]++;

                //Required group size reached
                if(st.back()[2] == groupSize[t])
                    st.pop_back();
            }
            else{
                //start a new group
                st.push_back({t, c, 1});

                // Handle group size = 1
                if (groupSize[t] == 1) {
                    st.pop_back();
                }
            }
        }

        //all elements must be removed
        return st.empty();
    }
};