#include<bits/stdc++.h>
using namespace std;

void dijkstra(int src, vector<vector<pair<int, int>>> &g, vector<pair<int, int> > &ans) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push(make_pair(0, src));
	vector<int> dist(g.size(), INT_MAX);
	dist[src] = 0;
	unordered_set<int> spt;

	while (!q.empty()) {
		auto tmp = q.top();
		q.pop();
		int u = tmp.second;
		int cost = tmp.first;
		spt.insert(src);

		for (auto v : g[u]) {
			if (spt.find(v.first) == spt.end() && dist[u] + v.second < dist[v.first]) {
				dist[v.first] = dist[u] + v.second;
			   
			} 
		}
	}

	int max_dist = INT_MIN, placeCount = 0;

	for (int i = 0; i < g.size(); i++) {
		if (dist[i] > max_dist && dist[i] != INT_MAX) {
		    max_dist = dist[i];
		}
	}
	for (int i = 0; i < g.size(); i++) {
		if (dist[i] == max_dist) placeCount++;
	}

	cout << max_dist <<  " " << placeCount << endl;
	ans[src].first = max_dist;
	ans[src].second = placeCount;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, m, q;
	//cin >> n >> m >> q;

	//int u, v, wt;
	vector<vector<pair<int, int>>> g(n, vector<pair<int, int>> ());

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> wt;
		g[u].push_back(make_pair(v, wt));
		g[v].push_back(make_pair(u, wt));
	}

	int src;
	vector<pair<int, int>> ans(g.size(), {0 , 0});
	//while(q++) {
		cin >> src;
		if (ans[src].first == 0 && ans[src].second == 0)
		    dijkstra(src, g, ans);
		else {
		    cout << ans[src].first << " " << ans[src].second << endl;
		}
	}
}
