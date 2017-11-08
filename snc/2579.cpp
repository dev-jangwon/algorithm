#include <iostream>
#include <algorithm>
// #include <cmath>
using namespace std;

int N;
int st[305] = {0, };
int maxd[305][3] = {0, };

int main(void) {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> st[i];
  }
  maxd[1][1] = st[1];
  for (int i = 2; i <= N; i++) {
    maxd[i][2] = maxd[i - 1][1] + st[i];
    maxd[i][1] = max(maxd[i - 2][1], maxd[i - 2][2]) + st[i];
  }
  cout << max(maxd[N][1], maxd[N][2]) << '\n';
  return 0;
}
