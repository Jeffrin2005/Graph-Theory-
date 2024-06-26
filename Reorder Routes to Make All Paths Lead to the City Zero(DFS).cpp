class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<vector<pair<int,int>>>& adj, int n, int &changes){
        visited[node] = 1;
        for(auto& newnode : adj[node]){
            int neighbour = newnode.first;
            int outgoing = newnode.second;
            if(!visited[neighbour]){
                if(outgoing){
                    changes++;
                }
                dfs(neighbour, visited, adj, n, changes);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> visited(n, 0);
        int changes = 0;
        for(auto& edge : connections){
            adj[edge[0]].push_back({edge[1], 1}); // 1 means outgoing
            adj[edge[1]].push_back({edge[0], 0}); // 0 means incoming
        }
        dfs(0, visited, adj, n, changes);
        return changes; 
    }
};
