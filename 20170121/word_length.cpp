# include <cstdio>

int main(void) {
  char s[100];
  scanf("%s", s);

  int i = 0;
  while(s[i] != '\0') {
    i++;
  }

  prinf("%d", i);

  return 0;
}
