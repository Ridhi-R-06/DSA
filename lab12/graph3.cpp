

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <tuple> 

using namespace std;

class Graph {
    int V; 
    vector<vector<pair<int, int>>> adj; 

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();
    void kruskalMST();
    void dijkstra(int src);

private:
    class DSU {
        vector<int> parent, rank;
    public:
        DSU(int n);
        int find(int x);
        void unite(int x, int y);
    };
};


Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}


void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); 
}


void Graph::primMST() {
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);
    vector<int> parent(V, -1);

    key[0] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minKey = INT_MAX;
        for (int v = 0; v < V; v++) {
            if (!inMST[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }
        if (u == -1) break;
        inMST[u] = true;

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }

    cout << "Prim's MST edges:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\n";
    }
}

Graph::DSU::DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
}


int Graph::DSU::find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}


void Graph::DSU::unite(int x, int y) {
    int rx = find(x);
    int ry = find(y);
    if (rx != ry) {
        if (rank[rx] < rank[ry]) parent[rx] = ry;
        else if (rank[ry] < rank[rx]) parent[ry] = rx;
        else {
            parent[ry] = rx;
            rank[rx]++;
        }
    }
}

void Graph::kruskalMST() {
    vector<tuple<int, int, int>> edges; 
    for (int u = 0; u < V; u++) {
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (u < v) { 
                edges.push_back({w, u, v});
            }
        }
    }
    sort(edges.begin(), edges.end());

    DSU dsu(V);
    cout << "Kruskal's MST edges:\n";
    for (auto &edge : edges) {
        int w, u, v;
        tie(w, u, v) = edge;
        if (dsu.find(u) != dsu.find(v)) {
            dsu.unite(u, v);
            cout << u << " - " << v << "\n";
        }
    }
}


void Graph::dijkstra(int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &neighbor : adj[u]) {
            int v = neighbor.first;
            int w = neighbor.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Dijkstra's shortest distances from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";
        if (dist[i] == INT_MAX) cout << "unreachable\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    int V, choice, u, v, w, src;
    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add edge\n";
        cout << "2. Prim's MST\n";
        cout << "3. Kruskal's MST\n";
        cout << "4. Dijkstra's shortest path\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (u v w): ";
                cin >> u >> v >> w;
                if (u >= 0 && u < V && v >= 0 && v < V) {
                    g.addEdge(u, v, w);
                    cout << "Edge added.\n";
                } else {
                    cout << "Invalid vertices.\n";
                }
                break;
            case 2:
                g.primMST();
                break;
            case 3:
                g.kruskalMST();
                break;
            case 4:
                cout << "Enter source vertex: ";
                cin >> src;
                if (src >= 0 && src < V) {
                    g.dijkstra(src);
                } else {
                    cout << "Invalid source vertex.\n";
                }
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
