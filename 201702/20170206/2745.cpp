# include <cstdio>
# include <cstring>
# include <cmath>

using namespace std;

int main(void) {
  char N[50];
  int B, result = 0;

  scanf("%s", N);
  scanf("%d", &B);

  int len = strlen(N);
  for (int i = 0; i < len; i++) {
    if ('A' <= N[len - i - 1] && N[len - i - 1] <= 'Z') {
      result += (N[len - i - 1] - 'A' + 10) * (int)(pow(B, i));
    } else {
      result += (N[len - i - 1] - '0') * (int)(pow(B, i));
    }
  }
  printf("%d", result);
  return 0;
}
