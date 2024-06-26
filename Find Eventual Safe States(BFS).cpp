class Solution {
private:
    void bfs(vector<vector<int>>&adj, vector<int>&indegree, queue<int>&q;vector<int>&safenode, vector<int>&visited){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenode.push_back(node);
            for(auto&newnode : adj[node]){
                indegree[newnode]--;
                if(indegree[newnode]==0 and !visited[newnode]){
                    visited[newnode] = 1;
                    q.push(newnode);
                }
            }
        }
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>adj(V);
        vector<int>indegree(V, 0);
        vector<int>visited(V, 0);
        for(int i=0; i<V; i++){
            for(auto&x : graph[i]){
                adj[x].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        vector<int>safenode;
        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
                visited[i] = 1; 
            }
        }
        bfs(adj, indegree,q, safenode,visited);
        sort(safenode.begin(),safenode.end());
        return safenode;

        
    }
};
