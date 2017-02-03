# include <cstdio>
# include <cstring>

using namespace std;

int memo[1001];

int solve(int N) {
  if (N == 1) {
    return 1;
  } else if (N == 2) {
    return 3;
  }

  int &ret = memo[N];

  if (ret != -1) {
    return ret;
  }

  ret = (solve(N - 1) + 2 * solve(N - 2)) % 10007;

  return ret;
}

int main(void) {
  memset(memo, -1, sizeof(memo));
  int N;
  scanf("%d", &N);
  printf("%d", solve(N));
  return 0;
}
