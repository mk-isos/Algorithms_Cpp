#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int>> pii;
const int INF = 0x3f3f3f3f;

struct cmp {
    bool operator() (pii A, pii B) {
        return A.first > B.first;
    }
};

int N, M;
vector<pii> graph[505][505];
int dist[505][505];

void Dijkstra(int start_x, int start_y) {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) dist[i][j] = INF;
    }
    priority_queue<pii, vector<pii>, cmp> pq;
    dist[start_y][start_x] = 0;
    pq.push({0, {start_x, start_y}});
    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int val = pq.top().first;
        pq.pop();
        if (dist[y][x] < val) continue;
        for (int i = 0; i < graph[y][x].size(); i++) {
            int nx = graph[y][x][i].second.first;
            int ny = graph[y][x][i].second.second;
            int new_val = val + graph[y][x][i].first;
            if (dist[ny][nx] > new_val) {
                dist[ny][nx] = new_val;
                pq.push({new_val, {nx, ny}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            if (s[j] == '/') {
                graph[i][j + 1].push_back({0, {j, i + 1}});
                graph[i + 1][j].push_back({0, {j + 1, i}});
                graph[i][j].push_back({1, {j + 1, i + 1}});
                graph[i + 1][j + 1].push_back({1, {j, i}});
            } else {
                graph[i][j].push_back({0, {j + 1, i + 1}});
                graph[i + 1][j + 1].push_back({0, {j, i}});
                graph[i][j + 1].push_back({1, {j, i + 1}});
                graph[i + 1][j].push_back({1, {j + 1, i}});
            }
        }
    }

    Dijkstra(0, 0);
    if (dist[N][M] == INF) cout << "NO SOLUTION";
    else cout << dist[N][M];

    return 0;
}
