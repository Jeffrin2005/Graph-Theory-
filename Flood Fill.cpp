class Solution {// DFS SOLUTION 
private:
    void dfs(vector<vector<int>>&image ,vector<vector<int>>&temp, vector<vector<int>>&vis , int row ,int col, int color ,int original,int m ,int n){
         vis[row][col] = 1 ;
         temp[row][col] = color;
         int delrow[] = {-1,0,+1,0};
         int delcol[] = {0,+1,0,-1};
         for(int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;
            if(nrow >= 0 and nrow < m and ncol >= 0 and ncol < n and image[nrow][ncol] == original and !vis[nrow][ncol]){
                dfs(image,temp,vis,nrow,ncol,color,original,m,n);
            }
         } 
    }
public:
     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size() ;
        int n = image[0].size() ;
        vector<vector<int>>vis(m,vector<int>(n,0)) ;
         vector<vector<int>>temp = image;
         int original = image[sr][sc];
        dfs(image,temp,vis,sr,sc,color,original,m,n);
        return temp ;
    }
};/// BFS SOLUTION
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        if (m == 0) return image;
        int n = image[0].size();
        int original = image[sr][sc];
        if (original == color) return image;

        vector<vector<int>> temp = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        temp[sr][sc] = color;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int row = current.first;
            int col = current.second;

            for (int i = 0; i < 4;i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    image[nrow][ncol] == original && temp[nrow][ncol] != color) {
                    q.push({nrow, ncol});
                    temp[nrow][ncol] = color;
                }
            }
        }

        return temp;
    }
};
