class Solution {
private:
    void bfs(vector<vector<int>>& graph, vector<vector<int>>& result) {
        queue<vector<int>> q;
        q.push({0});
        while (!q.empty()) {
            vector<int> path = q.front();
            q.pop();
            int lastNode = path.back();
            if (lastNode == graph.size() - 1) {
                result.push_back(path);
            } else {
                for (int newNode : graph[lastNode]) {
                    vector<int> newPath(path);
                    newPath.push_back(newNode);
                    q.push(newPath);
                }
            }
        }
    }
    public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        bfs(graph, result);
        return result;
    }
};
