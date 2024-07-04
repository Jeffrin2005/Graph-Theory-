
class Solution {  
private:
     void bfs(int start, vector<vector<int>>& graph, vector<int>& result) {
        queue<int> q;
        q.push(start);
        result[start] = 1; // Assign the first type of flower initially (color = 1)

        while (!q.empty()) {
            int garden = q.front();
            q.pop();
            bool used[5] = {}; // Track used flowers, index 0 is unused

            // Mark the flowers used by adjacent gardens
            for (int adj : graph[garden]) {
                if (result[adj] != 0) {
                    used[result[adj]] = true;
                }
            }

            // Assign the smallest available flower type to the current garden
            for (int flower = 1; flower <= 4; flower++) {
                if (!used[flower]) {
                    result[garden] = flower;
                    break;
                }
            }

            // Add unvisited adjacent gardens to the queue
          for (int adj : graph[garden]) {
    // If the adjacent garden has not been assigned a flower yet
    if (result[adj] == 0) {
        q.push(adj); // Add the adjacent garden to the BFS queue
        result[adj] = 1; // Temporarily assign the first type of flower
        // This temporary assignment prevents the garden from being re-added to the queue
        // and ensures that when it is processed, it will be reconsidered for the correct flower type
    }
}
        }
    }
    
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> graph(n);
        for (auto& path : paths){
            // Convert 1-based index to 0-based
            int u = path[0] - 1;
            int v = path[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> result(n, 0); // Result array, initialized to 0 (no flower)
        for (int i = 0; i < n;i++){
            if (result[i] == 0){ // If garden i has no flower assigned yet
                bfs(i, graph, result);
            }
        }
        return result;
    }
};
