

class Solution {
private:
    void bfs(int startNode, vector<vector<int>>& graph, set<int>& s, int &ans, vector<bool>& visited) {
        queue<int> q;
        q.push(startNode);
        visited[startNode] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& neighbor : graph[node]) {
                if(!visited[neighbor]){
                     if(s.find(neighbor) == s.end()){
                    visited[neighbor] = 1;
                    q.push(neighbor);
                    ans++;
                } 
                }
            }
        }
    }
    
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        set<int> s(restricted.begin(), restricted.end());
        int ans = 1; 
        bfs(0, graph, s, ans, visited);
        return ans;
    }
};
