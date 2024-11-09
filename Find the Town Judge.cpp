class Solution {// USING SINGLE VECTOR 
public:
    int findJudge(int n, vector<vector<int>>& v) {
        vector<int> ind(n + 1, 0);
        int n1 = v.size();
        for(int i=0; i<n1; i++){
            ind[v[i][0]]--;
            ind[v[i][1]]++;
        }
        for(int i=1; i<=n; i++){
            if(ind[i]== (n-1)){
                return i;
            }
        }

        return -1;
    }
}; // USE TWO VECTORS 
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
        vector<int> ind(n + 1, 0);
        vector<int> out(n + 1, 0);
        int n1 = v.size();
        for(int i = 0; i < n1; i++){
            out[v[i][0]]++;
            ind[v[i][1]]++;
        }
        for(int i = 1; i <= n; i++){
            if(ind[i] == n - 1 && out[i] == 0){
                return i;
            }
        }
        return -1;
    }
};
