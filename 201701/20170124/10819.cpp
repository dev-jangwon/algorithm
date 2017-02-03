# include <cstdio>
# include <algorithm>
# include <vector>

using namespace std;

int calculate_diff(vector<int> &v) {
  int result = 0;
  for (int i = 0; i < v.size() - 1; i++) {
    int diff = v[i] - v[i + 1];
    if (diff < 0) {
      diff = diff * -1;
    }
    result = result + diff;
  }
  return result;
}

int main(void) {
  int N;
  scanf("%d", &N);

  vector<int> v;
  int num;

  for (int i = 0;i < N; i++) {
    scanf("%d", &num);
    v.push_back(num);
  }

  sort(v.begin(), v.end()); // permutation 전에 sort

  int max = 0;

  do {
    if (calculate_diff(v) > max) {
      max = calculate_diff(v);
    }
  } while(next_permutation(v.begin(), v.end()));

  printf("%d", max);

  return 0;
}
