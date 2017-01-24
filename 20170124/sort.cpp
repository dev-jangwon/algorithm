# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

int main(void) {
  vector<int> v;
  int N, num;
  cin >> N;

  while(N--) {
    cin >> num;
    v.push_back(num);
  }

  sort(v.begin(), v.end());

  for(int i = 0; i < v.size(); i++) {
    cout << v.at(i) << endl;
  }

  return 0;
}
