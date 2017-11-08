#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int w, h;
int map[50][50];
bool visited[50][50];
int x_move[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int y_move[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int cnt;

void BFS(int x, int y);

int main(void) {
  while(1) {
    scanf("%d %d", &w, &h);
    if (w <= 0 && h <= 0) {
      break;
    }
    cnt = 0;
    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &map[i][j]);
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (map[i][j] != 0 && !visited[i][j]) {
          cnt++;
          BFS(i, j);
        }
      }
    }

    printf("%d\n", cnt);
  }
  return 0;
}

void BFS(int x, int y) {
  visited[x][y] = true;
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));

  while(!q.empty()) {
    int x_now = q.front().first;
    int y_now = q.front().second;
    visited[x_now][y_now] = true;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int x_next = x_now + x_move[i];
      int y_next = y_now + y_move[i];

      if (x_next >= 0 && y_next >= 0 && x_next < h && y_next < w) {
        if (map[x_next][y_next] != 0 && !visited[x_next][y_next]) {
          visited[x_next][y_next] = true;
          q.push(make_pair(x_next, y_next));
        }
      }
    }
  }
}
