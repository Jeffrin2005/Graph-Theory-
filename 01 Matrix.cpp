class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>distance(m, vector<int>(n, 0));
        vector<vector<int>>visited(m, vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        vector<int>delrow = {-1, 0, +1, 0};
        vector<int>delcol = {0, +1, 0, -1};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int d = 0; d < 4; d++){
                int nrow = x + delrow[d];
                int ncol = y + delcol[d];
                if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol]){
                    distance[nrow][ncol] = distance[x][y] + 1;
                    q.push({nrow, ncol});
                    visited[nrow][ncol] = 1;
                }
            }
        }
        return distance;
    }
};
