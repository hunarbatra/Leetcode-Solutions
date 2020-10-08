class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        //calculating indegree for every pair
        for(int i=0; i<prerequisites.size(); i++) {
            indegree[prerequisites[i][0]]++;
        }
        
        stack<int> stack; //for DFS
        int count = 0;
        
        for(int i=0; i<indegree.size(); i++) {
            if(indegree[i]==0)
                stack.push(i);
        } //if none of them is 0, then there exists a cycle, therefore we will not enter ther while 
        //loop and instead in return count==numCourses, the result will be false
        
        while(!stack.empty()) {
            int current = stack.top(); stack.pop();
            count++;
            for(int i=0; i<prerequisites.size(); i++) {
                if(prerequisites[i][1] == current) {
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]] == 0)
                        stack.push(prerequisites[i][0]);
                }
            }
        }
        return count == numCourses;
    }
};