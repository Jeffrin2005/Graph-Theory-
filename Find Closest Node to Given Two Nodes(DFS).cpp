class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& dis, vector<bool>& visited) {
        visited[node] = true;
        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dis[neighbour] = dis[node] + 1;
                dfs(neighbour, adj, dis, visited);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) adj[i].push_back(edges[i]);
        }

        vector<int> dis1(n, INT_MAX), dis2(n, INT_MAX);
        vector<bool> v1(n, false), v2(n, false);

        // Perform DFS for node1 and node2
        dis1[node1] = 0;
        dfs(node1, adj, dis1, v1);
        dis2[node2] = 0;
        dfs(node2, adj, dis2, v2);

        int maxDis = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (dis1[i] != INT_MAX && dis2[i] != INT_MAX) {
                int currDis = max(dis1[i], dis2[i]);
                if (currDis < maxDis) {
                    maxDis = currDis;
                    ans = i;
                } else if (currDis == maxDis && ans > i) {
                    ans = i;
                }
            }
        }
        return ans;
    }
};
