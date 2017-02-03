# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int main(void) {
  vector<int> v;
  int N, num, tgt;
  cin >> N;

  while(N--) {
    cin >> num;
    v.push_back(num);
  }
  cin >> tgt;

  cout << count(v.begin(), v.end(), tgt);

  return 0;
}
