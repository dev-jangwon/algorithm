# include <cstdio>
# include <cstring>
# define SIZE 10000001

using namespace std;

bool isPrime[SIZE];
void Eratos() {
  memset(isPrime, true, SIZE);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i < SIZE + 1; i ++) {
    if (isPrime[i]) {
      for (int j = i * i; j < SIZE + 1; j += i) {
        isPrime[j] = false;
      }
    }
  }
  return;
}

int main(void) {
  int N;
  Eratos();
  while(scanf("%d", &N) && N != 0) {
    int i;
    for (i = 3; i <= N; i += 2) {
      if (isPrime[i] && isPrime[N - i]) {
        printf("%d = %d + %d\n", n, i, n - i);
        break;
      }
    }
    if (i > N) {
      printf("Goldbach's conjecture is wrong.\n");
    }
  }
  return 0;
}
