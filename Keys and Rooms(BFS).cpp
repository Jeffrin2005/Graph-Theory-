class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, 0);
        queue<int>q;
        q.push({0});
        visited[0] = 1;
        for(int i=0; i<rooms[0].size(); i++){
            q.push(rooms[0][i]);
        }
       while(!q.empty()){
            int t = q.front();
            q.pop();
            if(!visited[t]){
                visited[t] = 1;
                for(int i=0; i<rooms[t].size(); i++){
                    q.push(rooms[t][i]);
                }
            }

            }
            for(int i=0; i<n;i++){
                if(!visited[i]){
                    return false;
                }
            }
            return true; 
       }
    
};
