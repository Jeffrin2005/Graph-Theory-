class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>result;
        queue<vector<int>>q;
        q.push({0});
        while (!q.empty()){
            vector<int>path = q.front();
            q.pop();
            int lastnode = path.back();
            if(lastnode == graph.size() - 1){
                result.push_back(path);
            }else{
                for(auto&newnode : graph[lastnode]){
                    vector<int>copy(path);
                    copy.push_back(newnode);
                    q.push(copy);

                }
            }

        }
        return result;
        
    }
};
