class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (auto& x : edges) {
            
            dist[x[0]][x[1]] = x[2];
            dist[x[1]][x[0]] = x[2];
        }
        for (int i = 0; i < n; i++) dist[i][i] = 0;
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); 
                }
            }
        }

        int cnt_of_city = n;
        int city_no = -1;
        for (int city = 0; city < n; city++) {
            int cnt = 0;
            for (int adj_city = 0; adj_city < n; adj_city++) {
                if (dist[city][adj_city] <= distanceThreshold) cnt++;
            }
            if (cnt <= cnt_of_city) {
                cnt_of_city = cnt;
                city_no = city;
            }
        }
        return city_no;
    }
};
