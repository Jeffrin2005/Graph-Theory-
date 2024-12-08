
class Solution {
public:
    map<string, map<string, double>> graph;
    void build_graph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            double k = values[i];
            graph[equations[i][0]][equations[i][1]] = k;
            
            graph[equations[i][1]][equations[i][0]] = 1.0 / k;
        }
    }
    double bfs(string source, string destination) {
        if (graph.find(source) == graph.end() || graph.find(destination) == graph.end()) return -1.0;
        if (source == destination) return 1.0;
        queue<pair<string, double>> q;
        q.push({source, 1.0});
        map<string, double> visited; 
        visited[source] = 1.0;

        while (!q.empty()){
            auto [current, current_product] = q.front();
            q.pop();
            if (current == destination) {
                return current_product;
            }
            for (auto& neighbour : graph[current]) {
                if (!visited.count(neighbour.first)) {
                    visited[neighbour.first] = current_product * neighbour.second;
                    q.push({neighbour.first, visited[neighbour.first]});
                }
            }
        }
        return -1.0; 
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        build_graph(equations, values);
        vector<double> result;
        for (auto& q : queries) {
            double temp = bfs(q[0], q[1]);
            result.push_back(temp);
        }
        return result;
    }
};
