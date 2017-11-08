#include <iostream>
#include <algorithm>
using namespace std;

int N;
int house[1005][3] = {0, };
int dp[1005][3] = {0, };

int main(void) {
  cin >> N;
  int j = 0;

  for (int i = 0; i < N * 3; i++) {
    if (i % 3 == 0 && i != 0) {
      j++;
    }
    cin >> house[j][i % 3];
  }
  dp[0] = house[0];
  dp[1] = house[1];
  dp[2] = house[2];
  for (int i = 1; i < N; i++) {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i];
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i];
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i];
  }
  for (int i = 0; i < 3; i++) {
    cout << dp[N - 1][i] << '\n';
  }
  return 0;
}
