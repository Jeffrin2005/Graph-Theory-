class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>>g(n);
        for (int i = 0; i < flights.size(); i++) {
            g[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
        vector<int>noOfStops(n, INT_MAX);
        pq.push({0, src, 0}); //cost : node : stops
        while (!pq.empty()) {
            auto[cost, node, stops] = pq.top(); 
            pq.pop();
            if (noOfStops[node] < stops) {
                continue;
            }
            noOfStops[node] = stops;

            if (node == dst) { //dest -> k+1 stop? k stops in between, dst -> k+1
                return cost;
            }

            if (stops > k) {
                continue;
            }

            for (auto adj : g[node]) {
                pq.push({cost+adj.second, adj.first, stops+1});
            }
        }
        return -1;
    }
};
