# include <cstdio>

using namespace std;

int getCount(int cn, int N) {
  int count = 0;
  for (int i = cn; i <= N; i *= cn) {
    count += (N / i);
  }
  return count;
}

int main(void) {
  int N, M;
  scanf("%d %d", &N, &M);
  int two = getCount(2, N) - getCount(2, M) - getCount(2, N - M);
  int five = getCount(5, N) - getCount(5, M) - getCount(5, N - M);
  printf("%d", (two < five) ? two : five);
  return 0;
}
