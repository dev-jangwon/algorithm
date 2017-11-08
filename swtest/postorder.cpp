#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

int main(void) {
  int T;
  stack<char> st;
  scanf("%d ", &T);
  while(T--) {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '(' && s[i] != '+' && s[i] != '-' && s[i] != ')') {
        cout << s[i];
      } else {
        if (s[i] == ')') {
          while(st.top() != '(') {
            cout << st.top();
            st.pop();
          }
        } else {
          st.push(s[i]);
        }
      }
    }
    while(!st.empty()) {
      if (st.top() != '(') {
          cout << st.top();
      }
      st.pop();
    }
  }
  return 0;
}
