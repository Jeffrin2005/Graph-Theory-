 public:
    void dfs(int x, int y, vector<vector<int>>& mat, vector<vector<bool>>& visited, string path, vector<string>& paths) {
        int n = mat.size();
        // Directions corresponding to 'U', 'L', 'D', 'R'
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};
        string dir = "ULDR";

        // Base case: if we reach the destination
        if (x == n - 1 && y == n - 1) {
            paths.push_back(path);
            return;
        }

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            int nx = x + delrow[i];
            int ny = y + delcol[i];

            // Check if the new position is within bounds and not visited and not blocked
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && mat[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = true; // Mark as visited
                dfs(nx, ny, mat, visited, path + dir[i], paths);
                visited[nx][ny] = false; // Unmark as visited for other paths
            }
        }
    }

    vector<string> findPath(vector<vector<int>>& mat) {
        vector<string> paths;
        int n = mat.size();
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) return paths; // Early exit if start or end is blocked

        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true; // Start from the top-left corner
        dfs(0, 0, mat, visited, "", paths);

        return paths;
    }
