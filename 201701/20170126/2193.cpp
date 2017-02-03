# include <cstdio>
# include <cstring>

using namespace std;

long long memo[91];

long long solve(int N) {
  if (N == 1 || N == 2) {
    return 1;
  }

  if (N <= 0) {
    return 0;
  }

  long long &ret = memo[N];

  if (ret != -1) {
    return ret;
  }

  ret = solve(N - 1) + solve(N - 2);

  return ret;
}

int main(void) {
  memset(memo, -1, sizeof(memo));
  int N;
  scanf("%d", &N);
  printf("%d", solve(N));
  return 0;
}
