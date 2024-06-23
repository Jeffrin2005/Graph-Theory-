class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int& edgesCount, int& verticesCount){
        visited[node] = 1;
        verticesCount++;
        for(int adjNode : adj[node]){
            edgesCount++;
            if(!visited[adjNode]){
                dfs(adjNode, adj, visited, edgesCount, verticesCount);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n); 
        vector<bool>visited(n,0); 
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                int edgesCount = 0;
                int verticesCount = 0;
                dfs(i, adj, visited, edgesCount, verticesCount);
                if (verticesCount * (verticesCount - 1) == edgesCount){
                    ans++;
                }
            }
        }
        return ans;
    }
};
