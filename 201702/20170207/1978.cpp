#include <cstdio>
#include <cstring>
#define SIZE 1001

using namespace std;

bool isPrime[SIZE];
void Eratos() {
  memset(isPrime, true, SIZE);
  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i * i <= SIZE + 1; i++) {
    if(isPrime[i]) {
      for (int j = i * i; j < SIZE + 1; j+= i) {
        isPrime[j] = false;
      }
    }
  }
  return;
}
// bool is_prime(int n) { // 시간초과
//   if (n == 1) {
//     return false;
//   }
//   if ((n % 2) == 0) {
//     if (n == 2) {
//       return true;
//     } else {
//       return false;
//     }
//   }
//   for (int i = 3; i * i < n; i+=2) {
//     if (n % i == 0) {
//       return false;
//     }
//   }
//   return true;
// }

int main(void) {
  int N, num = 0, sum = 0;
  scanf("%d", &N);
  Eratos();
  while(N--) {
    scanf("%d", &num);
    // if (is_prime(num)) {
    //   sum += 1;
    // }
    if (isPrime[num]) {
      sum += 1;
    }
  }
  printf("%d", sum);
  return 0;
}
