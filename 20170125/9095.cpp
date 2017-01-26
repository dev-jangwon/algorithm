# include <cstdio>
# include <cstring>

using namespace std;

int memo[1001];

int solve(int N) {
  if (N == 1) {
    return 1;
  } else if (N == 2) {
    return 2;
  } else if (N == 3) {
    return 4;
  } else if (N == 0 || N < 0) {
    return 0;
  }

  int &ret = memo[N];

  if (ret != -1) {
    return ret;
  }

  ret = solve(N - 1) + solve(N - 2) + solve(N - 3);

  return ret;
}

int main(void) {
  memset(memo, -1, sizeof(memo));
  int N, t;
  scanf("%d", &N);

  while(N--) {
    scanf(" %d", &t);
    printf("%d\n", solve(t));
  }

  return 0;
}
