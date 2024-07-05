#include <bits/stdc++.h>
#define ll long long  
using namespace std;

class Solution {
private:
    void dfs(vector<vector<int>>& graph, vector<bool>& visited, ll &cnt, int i) {
        visited[i] = true;
        cnt++;
        for (int j = 0; j < graph[i].size(); j++) {
            if (!visited[graph[i][j]]) {
                dfs(graph, visited, cnt, graph[i][j]);
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
            dfs(graph, visited, cnt, i);
            ans = max(ans, cnt);
        }
        return ans; 
    }
};
