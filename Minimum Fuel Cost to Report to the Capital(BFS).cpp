class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        if (n == 1) return 0;

        vector<vector<int>> adj(n);
        vector<int> visited(n, 0);
        vector<int> degree(n, 0);
        for (auto& edge : roads) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        vector<int> people(n, 1);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1 && i != 0) {  
                q.push(i);
                visited[i] = 1;
            }
        }

        long long ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int node = q.front();
                q.pop();
                if (node != 0) {  
                    ans += ceil(people[node] * 1.0 / seats);
                }

                for (auto& newnode : adj[node]) {
                    if (!visited[newnode]) {
                        visited[newnode] = 1;
                        degree[newnode]--;
                        people[newnode] += people[node];
                        if (degree[newnode] == 1 && newnode != 0) {
                            q.push(newnode);
                            visited[newnode] = 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
