class Solution {
private:
    bool bfs(vector<vector<int>>& rooms, vector<int>& visited) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (int key : rooms[t]) {
                if (!visited[key]) {
                    visited[key] = 1;
                    q.push(key);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }
public:

        bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        return bfs(rooms, visited);
    }
};
