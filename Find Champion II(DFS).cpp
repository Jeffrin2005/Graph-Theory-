class Solution {
private:
    void dfs(int node, vector<vector<int>>&graph, vector<bool>&visited){
        visited[node] = 1;
        for(auto&newnode : graph[node]){
            if(!visited[newnode]){
                dfs(newnode, graph, visited);
            }
        }
    }
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto&edge : edges){
            graph[edge[0]].push_back(edge[1]);
        }
        int found = 0;
        int ans = -1;
        for(int i=0; i<n; i++){
            vector<bool>visited(n , 0);
            dfs(i, graph, visited);
            if(count(visited.begin(),visited.end(),1) == n){
                if(found) return -1;
                found = 1;
                ans = i;
            }
        }
        return ans; 
    }
};
