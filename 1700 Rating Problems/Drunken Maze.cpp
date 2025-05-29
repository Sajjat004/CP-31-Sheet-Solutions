#include <bits/stdc++.h>
using namespace std;

struct State {
  int dist, x, y, dir;

  State(int dist, int x, int y, int dir) : dist(dist), x(x), y(y), dir(dir) {}

  bool operator<(const State& other) const {
    return dist > other.dist; // For min-heap
  }
};

void solve() {
  int n, m; cin >> n >> m;
  string s[n];
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  int startX, startY, endX, endY;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        startX = i;
        startY = j;
      }
      if (s[i][j] == 'T') {
        endX = i;
        endY = j;
      }
    }
  }

  const int dx[] = {0, 1, 0, -1};
  const int dy[] = {1, 0, -1, 0};

  vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(4, INT_MAX)));
  vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));

  priority_queue<State> pq;
  for (int dir = 0; dir < 4; dir++) {
    pq.push(State(0, startX, startY, dir)); 
    dist[startX][startY][dir] = 0; 
  }

  while (!pq.empty()) {
    State curr = pq.top();
    pq.pop();

    if (visited[curr.x][curr.y][curr.dir]) continue; // Already visited
    visited[curr.x][curr.y][curr.dir] = true;

    for (int dir = 0; dir < 4; ++dir) {
      if (dir == curr.dir) continue; // Skip the same direction
      for (int d = 1; d <= 3; ++d) {
        int newX = curr.x + dx[dir] * d; 
        int newY = curr.y + dy[dir] * d;


        if (newX >= 0 and newX < n and newY >= 0 and newY < m) {
          if (s[newX][newY] == '#') break; // Wall encountered

          int newDist = curr.dist + d;
          if (dist[newX][newY][dir] > newDist) {
            dist[newX][newY][dir] = newDist;
            pq.push(State(newDist, newX, newY, dir));
          }
        }
      }
    }
  }

  int ans = INT_MAX;
  for (int dir = 0; dir < 4; ++dir) {
    ans = min(ans, dist[endX][endY][dir]);
  }

  cout << (ans == INT_MAX ? -1 : ans) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  solve();
    
  return 0;
}

// Problem Lindir: https://codeforces.com/problemset/problem/2041/D
