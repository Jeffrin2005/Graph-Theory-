#include <bits/stdc++.h>
#define ll long long 
using namespace std;
class Solution {
private:
    int check(vector<vector<int>>& bombs, vector<bool>& detonated, int i) {
        int n = bombs.size();
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (!detonated[j]) {
                int x1 = bombs[i][0];
                int y1 = bombs[i][1];
                int r1 = bombs[i][2];
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                ll dist = pow(x1 - x2, 2) + pow(y1 - y2, 2);
                if (dist <= (ll)r1 * r1) {
                    detonated[j] = 1;
                    ans += 1 + check(bombs, detonated, j);
                }
            }
        }
        return ans;
    }
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> detonated(n, 0);
            if (!detonated[i]) {
                detonated[i] = 1;
                int temp = 1 + check(bombs, detonated, i);
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
