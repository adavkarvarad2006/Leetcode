class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        priority_queue<int> pq;

        int time = 0;

        sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });

        for(auto it:courses){
            time += it[0];
            pq.push(it[0]);

            if(time > it[1]){
                time -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};