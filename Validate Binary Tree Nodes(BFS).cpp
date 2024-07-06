
class Solution {
public:
 bool bfs(int root, const vector<int>& leftChild, const vector<int>& rightChild, vector<bool>& visited) {
    queue<int> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = 1;
        ++count;
        // Check left child
        if (leftChild[node] != -1) { // Ensure the index is valid
            if (!visited[leftChild[node]]) { 
                q.push(leftChild[node]);
            }
        }
        // Check right child
        if (rightChild[node] != -1) { 
            if (!visited[rightChild[node]]) { 
                q.push(rightChild[node]);
            }
        }
    }

    return count == visited.size(); // Check if all nodes were reachable
}

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; ++i){
            if (leftChild[i] != -1){
                if (++inDegree[leftChild[i]] > 1) return false; // More than one parent
            }
            if (rightChild[i] != -1){
                if (++inDegree[rightChild[i]] > 1) return false; // More than one parent
            }
        }
        // Find the root node (the one with no parents)
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (root != -1) return false; // More than one root
                root = i;
            }
        }
        if (root == -1) return false; // No root
        // Use BFS to check if all nodes are reachable from the root
        vector<bool> visited(n, false);
        return bfs(root, leftChild, rightChild, visited);
    }
};
