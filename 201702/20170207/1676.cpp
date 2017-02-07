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
  int N;
  scanf("%d", &N);
  int two = getCount(2, N);
  int five = getCount(5, N);
  printf("%d", (two < five) ? two : five);
  return 0;
}
