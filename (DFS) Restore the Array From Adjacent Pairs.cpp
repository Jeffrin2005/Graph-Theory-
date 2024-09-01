
class Solution {
public:
    void dfs(int node, map<int, vector<int>>& adjMap, map<int, bool>& visited, vector<int>& result) {
        // Mark the current node as visited
        visited[node] = true;
        // Add the current node to the result
        result.push_back(node);
        // Recursively visit each adjacent node that has not been visited
        for(auto&adj : adjMap[node]){
            if(!visited[adj]){
                dfs(adj, adjMap, visited, result);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> adjMap;
        for (auto& pair : adjacentPairs) {
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
        map<int, bool>visited;
        // Start DFS from the identified start node
        dfs(start, adjMap, visited, result);

        return result;
    }
};
