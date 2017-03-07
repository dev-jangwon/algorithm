# include <cstdio>
# include <vector>

using namespace std;

int N; // 동전 종류 수
int K; // 목표 액수
vector<int> v;
int ans;

int main(void) {
  scanf("%d %d", &N, &K);
  v.resize(N + 1);
  for (int i = 1; i <= N; i++) {
    scanf("%d", &v[i]);
  }
  for (int i = N; i >= 1; i--) {
    ans = ans + K / v[i];
    K = K % v[i];
  }
  printf("%d", ans);
  return 0;
}
