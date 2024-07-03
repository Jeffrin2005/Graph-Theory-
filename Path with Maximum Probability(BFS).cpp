class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq; // max_heap
        pq.push({1.0, start_node});
        vector<double> ans(n, INT_MIN);
        vector<bool> visited(n, false); 
        ans[start_node] = 1.0;
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int node = curr.second;
            visited[node] = true; 
            for (auto& newnode : adj[node]) {
                int adj_newnode = newnode.first;
                double proba_adj_newnode = newnode.second;
                 if(!visited[adj_newnode]){
                    if(ans[adj_newnode] < proba_adj_newnode * ans[node]){
                         ans[adj_newnode] = proba_adj_newnode * ans[node];
                    pq.push({ans[adj_newnode], adj_newnode});
                    }
                }
            }
        }
        return ans[end_node] != INT_MIN ? ans[end_node] : 0.00000;
    }
};
