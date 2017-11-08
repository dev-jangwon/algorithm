#include <iostream>
#include <vector>

using namespace std;

int N, S;
int ans = 0;
vector<int> vec;

void go(int i, int sum) {
  if (i == N) {
    if (sum == S) {
      ans += 1;
    }
    return;
  }
  go(i + 1, sum + vec[i]);
  go(i + 1, sum);
}

int main(void) {
  cin >> N >> S;
  vec.resize(N);

  for (int i = 0; i < N; i++) {
     cin >> vec[i];
  }
  go(0, 0);
  if (S == 0) ans -= 1;
  cout << ans << '\n';
  return 0;
}
