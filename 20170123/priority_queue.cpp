# include <iostream>
# include <queue>

using namespace std;

int main(void) {
  int N, num;
  priority_queue<int> pq;

  cin >> N;
  while(N--) {
    cin >> num;

    if (num == 0) {
        if (!pq.empty()) {
          cout << pq.front() << endl;
          pq.pop();
        } else {
          cout << 0 << endl;
        }
    } else {
      pq.push(num);
    }

  }
  return 0;
}
