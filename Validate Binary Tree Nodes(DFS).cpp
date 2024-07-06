
class Solution {
public:
    bool dfs(int node, const vector<int>& leftChild, const vector<int>& rightChild, vector<bool>& visited) {
        if (visited[node]) return false; // If already visited, it's a cycle
        visited[node] = true;
        // Check left child
        if (leftChild[node] != -1) {
            if ((dfs(leftChild[node], leftChild, rightChild, visited))== false){
                return false; // Return immediately if a cycle or disconnection is found
            }
        }
        // Check right child
        if (rightChild[node] != -1) {
            if ((dfs(rightChild[node], leftChild, rightChild, visited))==false){
                return false; // Return immediately if a cycle or disconnection is found
            }
        }
        return true; 
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild){
        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) {
                if (++inDegree[leftChild[i]] > 1) return false; // More than one parent
            }
            if (rightChild[i] != -1) {
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
        // Use DFS to check if all nodes are reachable from the root
        vector<bool> visited(n, false);
        if ((dfs(root, leftChild, rightChild, visited))==false ){
            return false; // If DFS finds a cycle or disconnected component
        }
        // Check if all nodes were visited
        for (bool v : visited) {
            if (!v) return false; // If any node was not visited, the tree is not valid
        }
        return true;
    }
};
