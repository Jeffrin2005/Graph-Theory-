class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
       // finding the indegreee of the nodes/
       // if any indegree node is equalt to nodes - 1 print ans = i and break ;
       int nodes = 0;

       int n = edges.size();

        for(int i=0; i<n; i++){
            nodes = max(nodes, max(edges[i][0],edges[i][1]));
        }

        vector<int>indegree(nodes+1);
        
        for(int i=0; i<n; i++){
            indegree[edges[i][0]]++;
            indegree[edges[i][1]]++;
        }

       int n1 = indegree.size(); 

        int ans = 0;
       for(int i=0; i<n1; i++){
            if(indegree[i] == nodes - 1){
                ans = i;
                break; 
            }
       }

       return ans;

        

        
    }
};
