# include <cstdio>
# include <cstring>
# include <queue>

using namespace std;

int w, h; // 너비 w, 높이 h
int map[50][50];
bool visited[50][50];
// 동, 서, 남, 북, 북동, 남서, 북서, 남동
int x_move[8] = {1, -1, 0, 0, 1, -1, -1, 1};
int y_move[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int cnt; // 섬 개수

void BFS(int x, int y);

int main(void) {
  while(1) {
    scanf("%d %d", &w, &h);
    if (w <=0 && h <= 0) { // 무한반복 탈출조건
      break;
    }
    cnt = 0;
    memset(map, 0, sizeof(map)); // 지도 초기화
    memset(visited, false, sizeof(visited)); // 방문여부 초기화

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        scanf("%d", &map[i][j]); // 섬 지도 입력
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
}

void BFS(int x, int y) {
  visited[x][y] = true;
  queue<pair<int, int> > q;
  q.push(make_pair(x, y));

  while(!q.empty()) {
    int x_now = q.front().first; // 현재 x 좌표
    int y_now = q.front().second; // 현재 y 좌표
    visited[x_now][y_now] = true;
    q.pop();

    for (int i = 0; i < 8; i++) {
      int x_next = x_now + x_move[i];
      int y_next = y_now + y_move[i];

      if (x_next >=0 && y_next >=0 && x_next < h && y_next < w) {
        if (map[x_next][y_next] != 0 && !visited[x_next][y_next]) {
          visited[x_next][y_next] = true;
          q.push(make_pair(x_next, y_next));
        }
      }
    }
  }
}
