# include <stdio.h>

int main(void) {
  int T, num1, num2;
  scanf("%d", &T);

  while(T--) {
      scanf("%d %d", &num1, &num2);
      printf("%d\n", num1 + num2);
  }
  return 0;
}
