class Solution {
public:
    map<string, map<string, double>> graph;
    // Builds a graph where each node points to other nodes with the division result as the edge weight.
    void build_graph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            double k = values[i];
            // Create an edge from the first variable to the second with the given division value.
            graph[equations[i][0]][equations[i][1]] = k;
            // Create a reverse edge from the second variable to the first with the inverse of the division value.
            graph[equations[i][1]][equations[i][0]] = 1.0 / k;
        }
    }

    double dfs(string source, string destination, set<string>& visited) {
        if (graph.find(source) == graph.end()) return -1.0;
        // Return the direct division result if there is a direct edge from source to destination.
        if (graph[source].find(destination) != graph[source].end()) return graph[source][destination];
        visited.insert(source); // Mark the source as visited to avoid cycles.
        for (auto& neighbour : graph[source]){
            if (visited.find(neighbour.first) == visited.end()){
                // cout << visited.find(neighbour.first) == visited.end();
                double ans = dfs(neighbour.first, destination, visited);
                // If a valid path is found, multiply the edge weight by the result of the recursive DFS call.
                if (ans != -1.0) {
                    return neighbour.second * ans;
                }
            }
        }
        return -1.0; // Return -1.0 if no valid path is found.
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        build_graph(equations, values); // Build the graph from the equations and values.
        vector<double> result;
        for (auto& q : queries) {
            if (q[0] == q[1]) {
                // If both variables in the query are the same, check if the variable exists in the graph.
                if (graph.find(q[0]) != graph.end()) result.push_back(1.0); // Return 1.0 if it exists.
                else result.push_back(-1.0); // Return -1.0 if it does not exist.
            } else {
                set<string> visited;
                double temp = dfs(q[0], q[1], visited); // Perform a DFS to find the division result.
                result.push_back(temp); // Store the result in the vector.
            }
        }
        return result; 
    }
};
