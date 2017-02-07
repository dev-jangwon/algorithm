# include <cstdio>
# include <cstring>
# define SIZE 10000001

using namespace std;

bool isPrime[SIZE];
void Eratos() {
  memset(isPrime, true, SIZE);
  isPrime[0] = isPrime[1] = false;
  for (int i = 2; i * i < SIZE + 1; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j < SIZE + 1; j+=i) {
        isPrime[j] = true;
      }
    }
  }
  return;
}

int main(void) {
  int M, N;
  Eratos();
  scanf("%d %d", &M, &N);
  for (int i = M; i <= N; i++) {
    if (isPrime[i]) {
      printf("%d\n", i);
    }
  }
  return 0;
}
