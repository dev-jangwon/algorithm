# include <cstdio>

using namespace std;

int n[10001] = {0};

int main(void) {
  int N;
  scanf("%d", &N);
  int num;
  while(N--) {
    scanf("%d", &num);
    n[num]++;
  }
  for (int i = 0; i < 10001; i++) {
    if (n[i] != 0) {
      for (int j = 0; j < n[i]; j++) {
        printf("%d\n", i);
      }
    }
  }
  return 0;
}
