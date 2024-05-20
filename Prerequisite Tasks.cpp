public:
	bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
	   vector<int>adj[V];
	   for(auto&x : prerequisites){
	       adj[x.first].push_back(x.second);
	   }
	   int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}
        if(topo.size() == V) return true;
        return false;
	}
