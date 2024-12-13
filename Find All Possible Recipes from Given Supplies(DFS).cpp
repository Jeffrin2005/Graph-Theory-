class Solution {private:
    void dfs(const string& node, map<string, vector<string>>& adj, map<string, int>& indegree, vector<string>& visited, vector<string>& ans) {
        if(find(visited.begin(), visited.end(), node) != visited.end()) return;  // If already visited, return
        visited.push_back(node);  // Mark this node as visited by adding to the vector
        for (auto& newnode : adj[node]) {
            indegree[newnode]--;  // Decrement the indegree of the recipe
            if (indegree[newnode] == 0) {  // If no more ingredients are needed for this recipe
                if (find(visited.begin(), visited.end(), newnode) == visited.end()) {
                    dfs(newnode, adj, indegree, visited, ans);  // Recursively process this recipe
                }
                ans.push_back(newnode);  
            }
        }
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string, int> indegree;
        map<string, vector<string>> adj;
        int n = ingredients.size();
        for (int i = 0; i < n; i++) {

            for (auto& s : ingredients[i]) {
                adj[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        vector<string> ans;
        vector<string> visited; 
        for (auto& x : supplies) {
            if (find(visited.begin(), visited.end(), x) == visited.end()){
                dfs(x, adj, indegree, visited, ans);
            }
        }

        return ans;
    }

};
