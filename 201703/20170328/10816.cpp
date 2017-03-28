# include <cstdio>
# include <vector>
# include <algorithm>

using namespace std;

int N, M;

vector<int> num;
vector<int> answer;

int main(void) {
  scanf("%d", &N);
  num.resize(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &num[i]);
  }
  sort(num.begin(), num.end());
  scanf("%d", &M);
  while(M--) {
    int obj;
    scanf("%d", &obj);
    answer.push_back(upper_bound(num.begin(), num.end(), obj) - lower_bound(num.begin(), num.end(), obj));
  }
  int length = answer.size();
  for (int i = 0; i < length; i++) {
    printf("%d ", answer[i]);
  }
  return 0;
}

// # include <cstdio>
// # define SIZE 10000000
// using namespace std;
//
// int cnt[20000001];
//
// int main(void) {
//   int N;
//   scanf("%d", &N);
//   while(N--) {
//     int temp;
//     scanf("%d", &temp);
//     cnt[temp + SIZE]++;
//   }
//   int M;
//   scanf("%d", &M);
//   while(M--) {
//     int temp;
//     scanf("%d", &temp);
//     printf("%d ", cnt[temp + SIZE]);
//   }
//   return 0;
// }
