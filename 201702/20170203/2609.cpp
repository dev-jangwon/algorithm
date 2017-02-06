# include <cstdio>

using namespace std;

int GCD(int a, int b) {
  return b ? GCD(b, a % b) : a;
}

int main(void) {
  int a, b, gcd = 0;
  scanf("%d %d", &a, &b);
  if (a > b) {
    gcd = GCD(a, b);
  } else {
    gcd = GCD(b, a);
  }
  printf("%d\n", gcd);
  printf("%d", a * b / gcd);
  return 0;
}
