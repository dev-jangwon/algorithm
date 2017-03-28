# include <cstdio>

using namespace std;

int N;
int cnt[3];
int a[2200][2200];

bool is_equal(int x, int y, int n);
void solve(int x, int y, int n);

int main(void) {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  solve(0, 0, N);
  for (int i = 0; i < 3; i++) {
      printf("%d\n", cnt[i]);
  }
  return 0;
}

bool is_equal(int x, int y, int n) {
  for (int i = x; i < x + n; i++) {
    for (int j = y; j < y + n; j++) {
      if (a[x][y] != a[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void solve(int x, int y, int n) {
  if (is_equal(x, y, n)) { // 모두 같은 수로 되어 있다면
    cnt[a[x][y] + 1] += 1;
    return;
  }
  int m = n / 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      solve(x + i * m, y + j * m, m);
    }
  }
}
