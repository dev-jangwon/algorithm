#include <cstdio>

int main(void) {
  char c;
  int cnt = 1;

  while((c = getchar()) && c != '\n') {
    if (c == ',') {
      cnt ++;
    }
  }

  printf("%d", cnt);

  return 0;
}
