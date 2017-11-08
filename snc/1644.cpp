#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> vec;

int main(void) {
  cin >> N;
  vec.resize(N + 5);

  vec[1] = 0;

  for (int i = 2; i <= N; i++) {
    vec[i] = i;
  }

  for (int i = 2; i <= sqrt(N); i++) {
    if (vec[i] == 0) {
      continue;
    }
    for (int j = i + i; j <= N; j+=i) {
      if (vec[j] != i && vec[j] % i == 0) {
        vec[j] = 0;
      }
    }
  }

  int sum;
  int ans = 0;

  for (int i = 1; i <= N; i++) {
    sum = 0;
    if (vec[i] > 0) {
      for (int j = i; j <= N; j++) {
        sum += vec[j];
        if (sum == N) {
          ans += 1;
          break;
        } else if (sum > N) {
          break;
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
