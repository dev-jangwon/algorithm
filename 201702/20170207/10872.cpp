# include <cstdio>

using namespace std;

int factorial(int n) {
  if (n <= 1) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main(void) {
  int N;
  scanf("%d", &N);
  printf("%d", factorial(N));
  return 0;
}
