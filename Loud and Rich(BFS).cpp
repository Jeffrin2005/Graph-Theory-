

class Solution {
public:
    void bfs(vector<int>* adj, vector<int>& q, vector<int>& ans, vector<int>& ind, vector<bool>& visited, queue<int>& qu) {
        while (!qu.empty()) {
            int node = qu.front();
            qu.pop();
            for (auto it : adj[node]) {
                if (q[node] < q[it]) {
                    q[it] = q[node];
                    ans[it] = ans[node];
                }
                ind[it]--;
                if (ind[it] == 0 && !visited[it]) {
                    qu.push(it);
                    visited[it] = true;  
                }
            }
        }
    }

    vector<int> loudAndRich(vector<vector<int>>& r, vector<int>& q) {
        int n = q.size();
        vector<int> adj[n];
        vector<int> ind(n, 0);
        vector<int> ans(n);
        vector<bool> visited(n, false); 
        queue<int> qu;

        for (auto it : r) {
            adj[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }
        for (int i = 0; i < n; i++) {
            ans[i] = i;
            if (ind[i] == 0) {
                qu.push(i);
                visited[i] = true; 
            }
        }
        bfs(adj, q, ans, ind, visited, qu);

        return ans;
    }
};
