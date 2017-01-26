# include <iostream>
# include <string>

using namespace std;

int main(void) {
  string st;
  getline(cin, st);

  for(int i = 0; i < st.length(); i++) {
			if (a[i] >= 'a' && a[i] <= 'z') { // 소문자
				if (a[i] >= 'n' && a[i] <= 'z'){
					cout << <char>(a[i] - 13);
				} else {
					cout << <char>(a[i] + 13);
				}
			} else if (a[i] >= 'A' && a[i] <= 'Z') { // 대문자
				if (a[i] >= 'N' && a[i] <= 'Z') {
					cout << <char>(a[i] - 13);
				} else {
					cout << <char>(a[i] + 13);
				}
			} else {
        cout << a[i];
      }
  }

  return 0;
}
