class Solution{ // USING DFS 
private: 
    bool dfs(int current , int destination, vector<vector<int>>&adj, vector<int>&visited){
        if(current == destination){
            return true;
        }
        visited[current] = true;
        for(auto&neig : adj[current]){
            if(!visited[neig]){
                visited[neig]  = true;
                if(dfs(neig, destination, adj, visited)){
                    return true; 
                }
            }
        }
        return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        // creating adjcenty list
        for(auto&edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>visited(n, 0);

        return dfs(source, destination, adj, visited);
        
    }
};   // USING BFS 
class Solution {
private: 
    bool bfs(int source, int destination, vector<vector<int>>& adj, vector<int>& visited) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while(!q.empty()){
            int current = q.front();
            q.pop();
            if(current == destination){
                return true;
            }
            for(auto&neighbor : adj[current]){
                if(!visited[neighbor]){
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return false;
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int>visited(n, 0);
        return bfs(source, destination, adj, visited);
    }
};
