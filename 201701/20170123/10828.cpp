# include <iostream>
# include <stack>
# include <string>

using namespace std;

int main(void) {
  int N, member;
	string s;
  stack<int> st;

  cin >> N;

	while(N--) {
		cin >> s;

		if (s == "push") {
			cin >> member;
			st.push(member);
		} else if (s == "pop") {
			if (!st.empty()) {
				cout << st.top() << endl;
				st.pop();
			} else {
				cout << -1 << endl;
			}
		} else if (s == "size") {
			cout << st.size() << endl;
		} else if (s == "empty") {
			if (!st.empty()) {
				cout << 0 << endl;
			} else {
				cout << 1 << endl;
			}
		} else if (s == "top") {
			if (!st.empty()) {
				cout << st.top() << endl;
			} else {
				cout << -1 << endl;
			}
		}
	}

  return 0;
}
