

class Solution {
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& group, int node, int color) {
        if (group[node] != 0) {
            if (group[node] != color) {
                return false;
            }
            return true;
        }
        group[node] = color;

        for (auto& neighbor : graph[node]) {
            int nextColor;
            if (color == 1) {
                nextColor = 2;
            } else {
                nextColor = 1;
            }
            if (dfs(graph, group, neighbor, nextColor) == false) {
                return false;
            }
        }
        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n + 1);
        vector<int> group(n + 1, 0);  // 0 indicates unvisited, 1 and 2 are the two groups

        for (int i = 0; i < dislikes.size(); i++) {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for (int i = 1; i <= n; i++) {
            if (group[i] == 0) { 
                if (dfs(graph, group, i, 1) == false) {  // Start DFS with color 1
                    return false;
                }
            }
        }
        return true;
    }
};
