class Solution {
private:
    bool bfs(vector<vector<int>>&graph, vector<int>&group , int start){
        queue<int>q;
        q.push(start);
        group[start] = 1; // group 1
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(auto&newnode : graph[curr]){
                if(group[newnode] == 0){
                    if(group[curr] == 1){
                        group[newnode] = 2;
                    }else{
                        group[newnode] = 1;
                    }
                    q.push(newnode);
                }else if(group[newnode] == group[curr]){
                    return false;
                }
            }
        }
        return true; 
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>graph(n + 1);
        vector<int>group(n + 1, 0);
        for(int i=0; i<dislikes.size(); i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1; i<=n;i++){
            if(group[i] == 0){                                                                                                                                                                                                                                                              
                if((bfs(graph,group, i )) == false){
                    return false;
                }
            }
        }
        return true ; 
        
    }
};
