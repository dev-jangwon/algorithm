# include <cstdio>

using namespace std;

int GCD(int a, int b) {
  return b ? GCD(b, a % b) : a;
}

int main(void) {
  int T, N;
  int arr[100];
  int sum = 0;

  scanf("%d", &T);
  while(T--) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &arr[i]);
    }

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        sum += GCD(arr[i], arr[j]);
      }
    }
    printf("%d\n", sum);
    sum = 0;
  }
  return 0;
}
