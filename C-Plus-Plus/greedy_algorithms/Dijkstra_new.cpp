#include<iostream>

#include<queue>

#include<map>

#include<stack>

#include<vector>

#include<utility>

#define MAX_VALUE -987654321

using namespace std;

int n, m, s;

class Vertex {

public:

	int index;

	int dist;

	int post = 0;

	Vertex(int index, int dist, int post) :index(index), dist(dist), post(post) {

 

	}

	Vertex(int index) :index(index) {

		dist = MAX_VALUE;

	}

	void setDist(int d) {

		dist = d;

	}

	bool operator >(const Vertex& v)const {

		return dist > v.dist;

	}

	bool operator <(const Vertex& v)const {

		return dist < v.dist;

	}

};

class Graph {

public:

	int n = 0;

	vector<Vertex> vt;

	vector<vector<pair<int, int> > > adj;

	priority_queue<Vertex> pq;

	map<int, pair<int, int> > m;

 

	void addVertex(int index, int dist) {

		vt.push_back(Vertex(index, dist, index));

		n = vt.size();

		adj.resize(n + 1);

	}

	void addVertex(int index) {

		vt.push_back(Vertex(index));

		n = vt.size();

		adj.resize(n);

	}

	void addAdj(int u, int v, int w) {

		adj[u - 1].push_back(make_pair(v, w));

	}

	void setStart(int index) {

		vt[index - 1].setDist(0);

		vt[index - 1].post = index;

	}

	void dijkstra(int s) {

		vector<int> dist(n, -1 * MAX_VALUE);

		dist[s - 1] = 0;

		setStart(s);

		for (int i = 0; i < n; i++) {

			pq.push(vt[i]);

		}

		m.insert(make_pair(s, make_pair(0, -1)));

		while (!pq.empty()) {

			int index = pq.top().index - 1;

			int cost = -1 * pq.top().dist; 

			pq.pop();

			if (dist[index] < cost) continue;

			for (int i = 0; i < adj[index].size(); i++) {

				int n = adj[index][i].first;

				int v = adj[index][i].second;

				if (dist[n - 1] > dist[index] + v) {

					dist[n - 1] = dist[index] + v;

					Vertex newVt = Vertex(n, -dist[n - 1], index + 1);

					pq.push(newVt);

					m[n] = make_pair(dist[n - 1], index + 1);

				}

			}

		}

		cout << "minimum distance length per index" << endl;

		for (int i = 0; i < n; i++) {

			dist[i] == -1 * MAX_VALUE ? printf("INF ") : printf("%d ", dist[i]);

		}

		printf("\n");

	}

};

int main() {

	cin >> n >> m >> s;

	Graph gp;

	for (int i = 0; i < n; i++)

		gp.addVertex(i + 1);

	for (int i = 0; i < m; i++) {

		int u, v, w;

		cin >> u >> v >> w;

		gp.addAdj(u, v, w);

	}

	gp.dijkstra(s);

}

