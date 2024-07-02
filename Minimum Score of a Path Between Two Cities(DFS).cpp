#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    int dfs(int node, int &ans, vector<vector<int>>& graph, vector<int>& visited){
        visited[node] = 1;
        for(int i = 0; i < graph[node].size(); i += 2){
            int v = graph[node][i]; // neighbor
            int dist = graph[node][i + 1]; // distance to neighbor
            ans = min(ans, dist);
            if(!visited[v]){
                visited[v] = 1;
                ans = min(ans, dfs(v, ans, graph, visited));
            }
        }
        return ans;
    }
    
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>> graph(n + 1);
        for(auto& edge : roads){
            graph[edge[0]].push_back(edge[1]); // u -> v
            graph[edge[0]].push_back(edge[2]); // u -> distance to v
            graph[edge[1]].push_back(edge[0]); // v -> u
            graph[edge[1]].push_back(edge[2]); // v -> distance to u
        }
        vector<int> visited(n + 1, 0);
        int ans = INT_MAX;
        dfs(1, ans, graph, visited);
        return ans;
    }
};
