class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        int row = grid.size();
        int col = grid[0].size();
        vector<int>delrow = { -1 , 0 , +1 , 0};
        vector<int>delcol = { 0, -1 , 0 , +1};
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    vis[i][j] = 1; 
                    queue<pair<int,int>>q;
                    q.push({i, j});
                    while(!q.empty()){
                        int curr_row = q.front().first;
                        int curr_col = q.front().second;
                        q.pop();
                        for(int k=0; k<4; k++){
                            int nrow = curr_row + delrow[k];
                            int ncol = curr_col + delcol[k];
                            if(nrow < row && nrow>=0 && ncol<col && ncol>=0 && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                                q.push({nrow,ncol});
                                vis[nrow][ncol] = 1; 
                            } 
                        }
                    }
                }
            }
        }
        return ans; 
    }
};// DFS
class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int curr_row, int curr_col, vector<int>& delrow, vector<int>& delcol) {
        vis[curr_row][curr_col] = 1;
        for (int k = 0; k < 4; k++) {
            int nrow = curr_row + delrow[k];
            int ncol = curr_col + delcol[k];

            // Check if the new position is within bounds and is land and not visited
            if (nrow >= 0 && nrow < grid.size() && ncol >= 0 && ncol < grid[0].size() && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                dfs(grid, vis, nrow, ncol, delrow, delcol); 
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;

        int row = grid.size();
        int col = grid[0].size();
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0, -1, 0, 1};
        vector<vector<int>>vis(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                // If the cell is land ('1') and not visited, it's part of an island
                if (grid[i][j] == '1' && !vis[i][j]) {
                    ans++; 
                    dfs(grid, vis, i, j, delrow, delcol); 
                }
            }
        }
        return ans;
    }
};
