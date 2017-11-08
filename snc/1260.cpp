#include<iostream>
#include<queue>
using namespace std;

int N, M, V;
int map[1005][1005] = {0, };
int visit[1005] = {0, };
queue<int> q;

void dfs(int v) {
  cout << v << " ";
  visit[v] = 1;
  for (int i = 1; i <= N; i++) {
      if (map[v][i] != 0 && visit[i] == 0) {
        dfs(i);
      }
  }
}

void bfs(int v) {
  q.push(v);
  visit[v] = 1;
  while(!q.empty()) {
    int now = q.front();
    cout << now << " ";
    q.pop();
    for (int i = 1; i <= N; i++) {
      if (map[now][i] > 0 && visit[i] == 0) {
        q.push(i);
        visit[i] = 1;
      }
    }
  }
}

int main(void) {
  cin >> N >> M >> V;
  int x, y;
  for (int i = 1; i <= M; i++) {
    cin >> x >> y;
    map[x][y] = 1;
    map[y][x] = 1;
  }

  dfs(V);
  for (int i = 1; i <= N; i++) {
    visit[i] = 0;
  }
  cout << '\n';
  bfs(V);
  return 0;
}
