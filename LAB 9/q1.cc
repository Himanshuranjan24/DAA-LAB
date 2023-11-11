#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> distances;

void bfs(int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    distances = vector<int>(n, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;
    distances[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                distances[neighbor] = distances[node] + 2;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int start;
    cin >> start;
    start--;

    bfs(start);

    // Output BFS traversal
    cout << "BFS Traversal : ";
    for (int i = 0; i < n; i++) {
        if (distances[i] != -1) {
            cout << " " << (i + 1);
        }
    }
    cout << endl;

    // Output distances
    cout << "Distance : [";
    for (int i = 1; i < n; i++) {
        cout << distances[i] << " ";
    }
    cout << "\b" << "]" << endl;

    return 0;
}