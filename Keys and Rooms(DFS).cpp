#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& rooms, vector<int>& visited) {
        visited[node] = 1;
        for (auto& newnode : rooms[node]){
            if (!visited[newnode]){
                dfs(newnode, rooms, visited);
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, 0);
        dfs(0, rooms, visited);
        for(auto& x : visited) {
            if(x == 0){
                return false;
            }
        }
        return true; 
    }
};
