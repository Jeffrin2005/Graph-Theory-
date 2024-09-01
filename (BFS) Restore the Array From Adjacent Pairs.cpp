
class Solution {
public:
    void bfs(int start, map<int, vector<int>>& adjMap, vector<int>& result) {
        queue<int> q;
        map<int, bool> visited;
        q.push(start);
        visited[start] = true;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);
            // Enqueue all unvisited adjacent nodes
            for (auto&adj : adjMap[current]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    q.push(adj);
                }
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> adjMap;
        for (auto& pair : adjacentPairs){
            adjMap[pair[0]].push_back(pair[1]);
            adjMap[pair[1]].push_back(pair[0]);
        }
        vector<int> result;
        int start = 0;
        // Find the starting element (it will have only one adjacent element)
        for (auto& p : adjMap) {
            if (p.second.size() == 1) {
                start = p.first;
                break;
            }
        }
        bfs(start, adjMap, result);

        return result;
    }
};
