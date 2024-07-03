class Solution {
public:
    void dfs(int start, int end, vector<bool> &visited, vector<pair<int,double>> adj[], double sum, double &ans, double &mn) {
        if (sum <= mn) return;

        if (start == end) {
            ans = max(ans, sum);
            return;
        }

        visited[start] = true;
        for (auto node : adj[start]) {
            int newNode = node.first;  
            double proba_of_newNode = node.second; 
            if (!visited[newNode]) {
                if (sum * proba_of_newNode >= ans) {
                    dfs(newNode, end, visited, adj, sum * proba_of_newNode, ans, mn);
                }
            }
        }
        visited[start] = false;  
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<bool> visited(n, false);  
        double ans = 0;
        double mn = 1e-5;
        dfs(start, end, visited, adj, 1.0, ans, mn);
        return ans;
    }
};
