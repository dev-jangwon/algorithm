# include <cstdio>

using namespace std;

int main(void) {
  int N, M, K;
  int T;
  scanf("%d %d %d", &N, &M, &K);
  if (M > (N / 2)) {
    T = (N / 2);
  } else {
    T = M;
  }

  while((N + M) - 3*T < K) {
    T--;
  }

  printf("%d", T);
  return 0;
}
