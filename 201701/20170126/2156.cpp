# include <cstdio>
# include <cstring>
# include <vector>
# include <algorithm>

using namespace std;

int N;
vector<int> v;
int memo[10005][3];

int solve(int idx, int check) {
  if (idx >= N) {
    return 0;
  }

  int &ret = memo[idx][check];

  if (ret != -1) {
    return ret;
  }

  ret = 0;

  if (check == 2) {
    ret = solve(idx + 1, 0);
  } else if (check == 0 || check == 1) {
    ret = max(solve(idx + 1, check + 1) + v[idx], solve(idx + 1, 0));
  }

  return ret;
}

int main(void) {
  scanf("%d", &N);
  v.resize(N);

  int v_num;

  for (int i = 0; i < N; i++) {
    scanf("%d", &v_num);
    v[i] = v_num;
    for (int j = 0; j < 3; j++) {
      memo[i][j] = -1;
    }
  }

  int answer = solve(0, 0);
  printf("%d", answer);
  return 0;
}
