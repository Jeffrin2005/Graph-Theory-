class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
         vector<pair<int,int>>adj[n];
         for(auto edge: edges){
                 adj[edge[0]].push_back({edge[1],edge[2]});
                 adj[edge[1]].push_back({edge[0],edge[2]});
         }
         int cnt = INT_MAX;
        
         int city =-1;
         for(int k=0;k<n;k++){ // Dijkstra's Algorithm
                 vector<int>distance(n, 1e9);
                  priority_queue<pair<int, int>> pq;
                 pq.push({0,k});
                 distance[k]=0;
                 while(!pq.empty()){
                         pair<int,int>p = pq.top();
                         pq.pop();
                         int node = p.second;
                         int cost = p.first;
                         for(auto neighbor: adj[node]){
                               int to = neighbor.first;
                               int wt = neighbor.second;
                               if(distance[to] > distance[node] + wt){
                                       distance[to] = distance[node] + wt;
                                       pq.push({distance[to], to});
                               }
                         }
                 }
                 int count = 0;
                 for(auto&x: distance){
                         if(x <= distanceThreshold)count++;
                 }
                 if(count <= cnt){
                         cnt = count;
                         city = k;
                 }
         }

         return city;
    }
};
