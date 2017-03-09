# include <cstdio>
# include <algorithm>

using namespace std;

int main(void) {
  int N, M;
  int ans;
  if (N == 1) {
    ans = 1;
  } else if (N == 2) {
    ans = min(4, (M + 1) / 2);
  } else if (N > 2 && M < 7) {
    ans = min(4, M);
  } else {
    ans = M - 2;
  }
  printf("%d", M);
  return 0;
}
