class Solution {
private: 
    void dfs(int node, vector<int>&temp, vector<vector<int>>&ans,
    vector<int>&visited, vector<vector<int>>&graph, int n ){
        visited[node] = 1;
        temp.push_back(node);
        if(node == n - 1){
            ans.push_back(temp);
            return; 
        }
        
        for(auto&newnode : graph[node]){
            if(!visited[newnode]){
                dfs(newnode, temp, ans , visited , graph, n);
                visited[newnode] = 0;
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        int n = graph.size();
        vector<int>temp;
        vector<int>visited(n+1,0);
        dfs(0, temp ,ans, visited, graph, n );
        return ans;
    }
};
