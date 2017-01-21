#include <stdio.h>

int main(void) {
  int n = 0, sum = 0, temp = 0;

  scanf("%d", &n);

  for (n--) {
    scanf("%d", &temp);
    sum += temp;
  }

  prinf("%d", sum);
  return 0;
}
