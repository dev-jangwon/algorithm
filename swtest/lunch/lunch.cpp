#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN = 11;
const int MAXT = MAXN * 2 + MAXN * MAXN;

struct point {
  int r, c;
} man[MAXN], stair[2];

int N, M, S; // N: 한 변의 길이, M: 사람 수, S: 계단 수(2)
int map[MAXN][MAXN];
int match[MAXN]; // x번째 사람이 y번 계단을 타도록 결정된 상태
int answer;

int dist(int man_index, int stair_index) {
    int dx = abs(man[man_index].r - stair[stair_index].r);
    int dy = abs(man[man_index].c - stair[stair_index].c);
    return dx + dy;
}

void update() {
  int total_min_time = 0;
  for (int stair_index = 0; stair_index < 2; stair_index++) {
    
  }
}

void dfs(int man_index) {
  if (man_index == M) { // 재귀 종료 조건
    update();
    return;
  }
  for (int stair_index = 0; stair_index < 2; stair_index++) {
    match[man_index] = stair_index;
    dfs(man_index+1);
  }
}

int main(void) {
  int T; for(scanf("%d", &T); T--) {
    scanf("%d", &N);
    M = S = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &map[i][j]);
        if (map[i][j] == 1) {
          man[M++].r = i;
          man[M].c = j;
        }
        if (map[i][j] >= 2) {
          map[S++].r = i;
          map[S].c = j;
        }
      }
    }
    answer = 1e9;
    dfs(0);
    static int tc = 0;
    printf("#%d %d\n", ++tc, answer);
  }
  return 0;
}
