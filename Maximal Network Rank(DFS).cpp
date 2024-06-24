
class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& visited) {
       visited[node] = 1;
       for(auto&newnode : adj[node]){
            if(!visited[newnode]){
                dfs(newnode, adj, visited);
            }
       }
    }

public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>adj[n];
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        int maxi = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            dfs(i, adj, visited); 
            for (int j = 0; j < n; j++){
                if (i != j){
                    int val = adj[i].size() + adj[j].size();
                    if (find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) {
                        val--;
                    }
                    maxi = max(maxi, val);
                }
            }
        }

        return maxi;
    }
};
