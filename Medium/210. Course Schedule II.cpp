class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> order;
        queue<int> dfs;
        int count = 0;
        vector<int> indegree(numCourses,0);
        for(int i=0; i<prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
        }
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i]==0)
                dfs.push(i);
        }
        while(!dfs.empty()) {
            int current = dfs.front(); dfs.pop();
            order.push_back(current);
            count++;
            for(int i=0; i<prerequisites.size(); i++) {
                if(prerequisites[i][1]==current) {
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]]==0)
                        dfs.push(prerequisites[i][0]);
                }
            }
        }
        if(count != numCourses) order.clear();
        return order;
    }
};