#include <bits/stdc++.h>
#define ll long long  
using namespace std;
class Solution {
private:
    void bfs(vector<vector<int>>& graph, vector<bool>& visited, ll &cnt, int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cnt++; 
            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        ll n = bombs.size();
        vector<vector<int>> graph(n);
        for (ll i = 0; i < n; i++) {
            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];
            for (ll j = 0; j < n; j++) {
                if (i != j) {
                    ll x = abs(x1 - bombs[j][0]);
                    ll y = abs(y1 - bombs[j][1]);
                    if (x * x + y * y <= r1 * r1) {
                        graph[i].push_back(j);
                    }
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ll cnt = 0;
            vector<bool> visited(n, false);
            bfs(graph, visited, cnt, i);
            ans = max(ans, cnt);
        }
        return ans; 
    }
};
