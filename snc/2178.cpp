#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[105][105] = {-1, };
int visit[105][105] = {0, };

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

queue<pair<int, int> > q;
int cost = 0;

void bfs(int fx, int fy) {
  q.push(make_pair(fx, fy));
  visit[fx][fy] = 1;

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    if (x == N - 1 && y == M - 1) {
      cout << cost << '\n';
    }

    q.pop();

    int check = 0;

    for (int k = 0; k < 4; k++) {
      int nx = x + dx[k];
      int ny = y + dy[k];
      if (0 < nx && nx < N && 0 < ny && ny < M && map[nx][ny] > 0 && visit[nx][ny] < 0) {
        check = 1;
        q.push(make_pair(nx, ny));
        visit[nx][ny] = 1;
      }
      if (check == 1) {
        cost += 1;
      }
    }

  }
}

int main(void) {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }

  bfs(0, 0);

  return 0;
}
