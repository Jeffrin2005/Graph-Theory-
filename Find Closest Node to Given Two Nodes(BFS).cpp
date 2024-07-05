class Solution {
public:
    void bfs(int startNode, vector<int> adj[], vector<int>& dis, vector<bool>& visited) {
        queue<int> q;
        q.push(startNode);
        visited[startNode] = 1;
        dis[startNode] = 0;
        while (!q.empty()) {
            int curr = q.front();
             q.pop();
            for (auto neighbour : adj[curr]) {
                if (!visited[neighbour]) {
                    dis[neighbour] = dis[curr] + 1;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++){
            if(edges[i] != -1) adj[i].push_back(edges[i]);
        }

        vector<int> dis1(n, INT_MAX), dis2(n, INT_MAX);
        vector<bool> v1(n, false), v2(n, false);
        // Perform BFS for node1 and node2
        bfs(node1, adj, dis1, v1);
        bfs(node2, adj, dis2, v2);
        int maxDis = INT_MAX;
        int  ans = -1;
        for (int i = 0; i < n; i++){
            if (dis1[i] != INT_MAX && dis2[i] != INT_MAX) {
                int currDis = max(dis1[i], dis2[i]);
                if (currDis < maxDis) {
                    maxDis = currDis;
                    ans = i;
                }else if(currDis == maxDis && ans > i){ // returning  smallest index 
                    ans = i;
                }
            }
        }
        return ans;
    }
};
