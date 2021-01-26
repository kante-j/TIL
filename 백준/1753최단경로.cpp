#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> dist;
vector<pair<int, int>> graph[20001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E, start;
	cin >> V >> E >> start;
	dist.resize(V+1, 1000000000);
	dist[start] = 0;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({ 0,start });

	while (!pq.empty()) {
		pair<int, int> front = pq.top();
		pq.pop();
		int cost = front.first;
		int cur = front.second;

		if (dist[cur] < cost) {
			continue;
		}
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDist = graph[cur][i].second;
			if (nextDist + cost < dist[next]) {
				dist[next] = nextDist + cost;
				pq.push({ nextDist+cost, next });
			}
		}
	}
	for (int i = 1; i < V + 1; i++) {
		if (dist[i] == 1000000000) {
			cout << "INF" << '\n';
		} else {
			cout << dist[i] << '\n';
		}
	}

	return 0;
}