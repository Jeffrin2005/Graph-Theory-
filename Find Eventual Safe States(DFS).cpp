class Solution {
public:
    void solve(vector<int>& vis, vector<vector<int>>& adj, int i) {
        vis[i] = 2; // Mark the node as currently being visited
        for (auto it : adj[i]) { // Iterate over all adjacent nodes
            if (!vis[it]) { // If the node has not been visited
                solve(vis, adj, it); // Recursively visit the node
            }
            if (vis[it] == 2) return; // Cycle detected, return immediately
        }
        vis[i] = 1; // Mark the node as safe after all adjacent nodes are processed
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0); // Visitation state for each node
        vector<int> safeNodes; // List to store safe nodes

        for (int i = 0; i < n; i++) {
            if (!vis[i]) { // If the node has not been visited
                solve(vis, graph, i); // Start DFS from this node
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) { // If the node is marked as safe
                safeNodes.push_back(i); // Add to the list of safe nodes
            }
        }

        return safeNodes; // Return the list of safe nodes
    }
};
