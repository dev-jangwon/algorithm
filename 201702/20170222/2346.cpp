# include <iostream>
# include <queue>
# include <deque>

using namespace std;

deque<pair<int, int>> dq;
pair<int, int> p;
int N;

int main(void) {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int a;
    cin >> a;
    dq.push_back(make_pair(i, a));
  }

  int pos, target, a;
  p = dq.front();
  dq.pop_front();
  cout << p.first;
  target = p.second;

  while(!dq.empty()) {
    pos = 0;
    if (target > 0) {
      while(++pos < target) {
        p = dq.front();
        dq.pop_front();
        dq.push_back(p);
      }
      p = dq.front();
      dq.pop_front();
    } else {
      while(--pos > target) {
        p = dq.back();
        dq.pop_back();
        dq.push_front(p);
      }
      p = dq.back();
      dq.pop_back();
    }
    a = p.first;
    target = p.second;
    cout << " " << a;
  }
}
