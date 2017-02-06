# include <cstdio>
# include <cmath>

using namespace std;

int main(void) {
  int A, B, m;
  int b[26];
  int sum = 0;
  scanf("%d %d" , &A, &B);
  scanf("%d", &m);

  for (int i = m - 1; i >= 0; i--) {
    int x;
    scanf("%d", &x);
    sum += x * (int)(pow(A, i));
  }

  while (sum != 0) {
    b[j++] = sum % B;
    sum /= B;
  }

  for (int i = j - 1; i >= 0; i--) {
    printf("%d ", b[i]);
  }

  return 0;
}
