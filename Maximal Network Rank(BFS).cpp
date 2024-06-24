class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
            vector<int>adj[n];
            for(int i=0; i<roads.size(); i++){
                adj[roads[i][0]].push_back(roads[i][1]);
                adj[roads[i][1]].push_back(roads[i][0]);
            }
            queue<int>q;
            int maxi = 0;
            vector<int>visited(n , 0);
            for(int i=0;i< n;i++){
                q.push(i);
                visited[i] = 1;
                while(!q.empty()){
                    int current = q.front();
                    q.pop();
                    for(int j=0; j<n; j++){
                        if(i != j){
                            int val = adj[i].size() + adj[j].size();
                            if(find(adj[i].begin(), adj[i].end(), j) != adj[i].end()){
                                val--;
                            }
                            maxi = max(maxi, val);
                        }
                    }
                    for(auto&newnode : adj[current]){
                        if(!visited[newnode]){
                            visited[newnode]  = 1;
                            q.push(newnode);
                        }
                    }
                }
            }
            return maxi; 
    }
};
