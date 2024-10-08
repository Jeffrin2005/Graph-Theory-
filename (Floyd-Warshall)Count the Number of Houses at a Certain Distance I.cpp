class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        x--;
        y--;
        vector<vector<int>>dist(n , vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            
            if(i > 0){
                dist[i][i-1] = 1;
                dist[i-1][i] = 1;
            }
        }
        dist[x][y] = 1;
        dist[y][x] = 1;
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<int>result(n , 0);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int d = dist[i][j];
                if(d <= n){
                    result[d-1]+=2;
                }
            }
        }
        return result; 

        
    }
};
