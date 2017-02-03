# include <cstdio>
# include <cstring>
# include <algorithm>

using namespace std;

int memo[1000005];

int solve(int N) {
  if (N == 2 || N == 3) {
    return 1;
  }

  int &ret = memo[N];

  if (ret != -1) {
    return ret;
  }

  ret = solve(N - 1) + 1;

  if (N % 2 == 0) {
    ret = min(ret, solve(N / 2) + 1);
  }

  if(N % 3 == 0) {
    ret = min(ret, solve(N / 3) + 1);
  }

  return ret;
}

int main(void) {
  memset(memo, -1, sizeof(memo));
  int N;
  scanf("%d", &N);
  printf("%d", solve(N));
  return 0;
}
