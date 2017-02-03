# include <cstdio>
# include <algorithm>
# include <cstring>

using namespace std;

int memo[1001];
int P[10005];

int solve(int N) {
  if (N == 0) {
    return 0;
  } else if (N == 1) {
    return P[1];
  }

  int &ret = memo[N];

  if (ret != -1) {
    return ret;
  }

  ret = 0;

  ret = solve(N - 1) + P[1];

  for (int i = 2; i <= N; i++) {
    ret = max(ret, solve(N - i) + P[i]);
  }

  return ret;
}

int main(void) {
  memset(memo, -1, sizeof(memo));
  memset(P, -1, sizeof(P));

  int N;
  scanf("%d", &N);

  for (int i = 1; i <= N; i++) {
    scanf(" %d", &P[i]);
  }

  printf("%d", solve(N));

  return 0;
}
