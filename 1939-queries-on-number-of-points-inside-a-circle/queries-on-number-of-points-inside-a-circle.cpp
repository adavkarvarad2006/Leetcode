class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++){
            int count = 0;
            int xC = queries[i][0];
            int yC = queries[i][1];
            int rC = queries[i][2];

            for(int j=0; j<points.size(); j++){
                int x = points[j][0];
                int y = points[j][1];

                int a = xC-x;
                int b = yC-y;

                if(a*a+b*b <= rC*rC){
                    count++;
                }
            }

            ans[i] = count;
        }

        return ans;
    }
};