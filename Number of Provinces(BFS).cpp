class Solution {// USING DFS 
private: 
    void dfs(int node, vector<vector<int>>&adjLs,vector<int>&vis){
        vis[node] = 1;
        for(auto&x : adjLs[node]){
            if(!vis[x]){
                dfs(x,adjLs,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>&adj) {
        int V = adj.size();
        vector<vector<int>>adjLs(V); 
        for(int i = 0; i < V; i++){//  Iterates through each city i.
            for(int j = 0; j < V; j++){ //  Iterates through each city j to check if it's directly connected to city i.
                if(adj[i][j] == 1 and i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        vector<int>vis(V, 0); 
        int cnt = 0; 
        for(int i = 0; i < V; i++){
            if(!vis[i]){ 
                cnt++;
                dfs(i,adjLs,vis); 
            }
        }
        return cnt; 
    }       
};          // USING BFS
class Solution {
private: 
    void bfs(int start, vector<vector<int>>& adjLs, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto& x : adjLs[node]) {
                if (!vis[x]) {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<vector<int>> adjLs(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }
        vector<int> vis(V, 0);
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                bfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};
