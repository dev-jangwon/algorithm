# include <iostream>
# include <vector>

using namespace std;

int main(void) {
  vector<int> v;
  int index = 3;
  int N, ord;

  cin >> N >> ord;

  for (int k = 1; k <= N; k++) {
    v.push_back(k);
  }

  for (int k = 1; k <= N; k++) {
    cout << v.at(index);
    index = (index + 3 - 1) % v.size();
  }

  return 0;
}
